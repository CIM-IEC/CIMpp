#include "CIMContentHandler.hpp"
#include <iostream>
#include <sstream>
#include <regex>

#include <stdexcept>

#include "Folders.hpp"
#include "CIMFactory.hpp"
#include "assignments.hpp"
#include "CIMExceptions.hpp"

#ifndef CGMES_BUILD
#include "CIMNamespaces.hpp"
#endif

CIMContentHandler::CIMContentHandler() : Objects(nullptr), RDFMap(nullptr)
{
}

CIMContentHandler::~CIMContentHandler()
{
	checkStacksEmpty();
}

void CIMContentHandler::checkStacksEmpty()
{
	if (!objectStack.empty())
	{
		throw CriticalError("CIMContentHandler: Critical Error: objectStack is not empty!");
	}
	if (!tagStack.empty())
	{
		std::cerr << "First 5 items on stack: " << std::endl;
		int i = 10;
		while (!tagStack.empty() && i--) {
			std::string name = tagStack.top();
			std::cerr << "{" << name << "}" << std::endl;
			tagStack.pop();
		}
		throw CriticalError("CIMContentHandler: Critical Error: tagStack is not empty!");
	}
}

void CIMContentHandler::setObjectsContainer(std::vector<BaseClass*> *Objects)
{
	this->Objects = Objects;
}

void CIMContentHandler::setRDFMap(std::unordered_map<std::string, BaseClass*> *RDFMap)
{
	this->RDFMap = RDFMap;
}


void CIMContentHandler::startDocument()
{
	if(Objects == nullptr)
	{
		throw NoObjectsContainer(this);
	}
	if(RDFMap == nullptr)
	{
		throw NoRdfMap(this);
	}

}

void CIMContentHandler::endDocument()
{
}


void CIMContentHandler::startElement(const XMLCh* const uri,
                                     const XMLCh* const localname,
                                     const XMLCh* const qName,
                                     const xercesc::Attributes&  atts )
{
	// Only process tags in cim namespace
	if(std::string(xercesc::XMLString::transcode(qName)).find("cim:") == std::string::npos)
	{
		bool isModelDescription = std::string(xercesc::XMLString::transcode(qName)).find("md:") != std::string::npos
                                  || std::string(xercesc::XMLString::transcode(qName)).find("DependentOn:") != std::string::npos
                                  || std::string(xercesc::XMLString::transcode(qName)).find("createdBy") != std::string::npos;
		bool isModel = std::string(xercesc::XMLString::transcode(qName)).find("rdf:") != std::string::npos;

		if(!isModelDescription && !isModel)
		{
			std::cerr << "WARNING: "<< qName << " not in namespace \"cim\"" << std::endl;
		}
		return;
	}

	// Remember last opened tag
	tagStack.push(std::string(xercesc::XMLString::transcode(qName)));

	// If there is no RDF ID (an XML attribute!) then we don't have a new CIM
	// object or RDF relation therefore the XML element will contain a value
	// assignment.
	if(atts.getLength() == 0)
		return;
	// If name is a CIM class check if to create a new object
	if(CIMFactory::IsCIMClass(std::string(xercesc::XMLString::transcode(qName))))
	{
		// Get rdf_id
		std::string rdf_id = get_rdf_id(atts);
		if(rdf_id.empty())
		{
			throw NoRdfID();
		}
		// check if object already exists
		std::unordered_map<std::string, BaseClass*>::iterator it = RDFMap->find(rdf_id);
		if(it != RDFMap->end()) // object exists -> push it on the stack
		{
			objectStack.push(it->second);
		}
		else // object does not exist -> create object
		{
			BaseClass* BaseClass_ptr = CIMFactory::CreateNew(std::string(xercesc::XMLString::transcode(qName)));

			//Check if created Object is IdentifiedObject and place rdf_id into mRID
			if(CIMPP::IdentifiedObject* idOb = dynamic_cast<CIMPP::IdentifiedObject*>(BaseClass_ptr))
			{
				(*idOb).mRID = rdf_id;
			}
			RDFMap->emplace(rdf_id, BaseClass_ptr);
			objectStack.push(BaseClass_ptr);
			Objects->push_back(BaseClass_ptr);
		}
		return;
	}
	// Create a task if the XML element is no CIM class and contains a RDF ID
	std::string rdf_id = get_rdf_resource(atts);
    if(!rdf_id.empty())
	{
		taskQueue.push_back(Task(objectStack.top(), std::string(xercesc::XMLString::transcode(qName)), rdf_id));
		return;
	}
	// Assign an enum symbol if the rdf id contains a enum symbol
	std::string enumSymbol = get_rdf_enum(atts);
	if(!enumSymbol.empty())
	{
		if(!assign(objectStack.top(), std::string(xercesc::XMLString::transcode(qName)), enumSymbol))
			std::cerr << "CIMContentHandler: Error: " << enumSymbol << " can not be assigned" << std::endl;
		return;
	}

	// Nobody knows what to do
	std::cerr << "CIMContentHandler: Error: Nobody knows, the " << qName << " I've seen... *sing*" << std::endl;
}

void CIMContentHandler::endElement(const XMLCh* const uri,
								   const XMLCh* const localname,
								   const XMLCh* const qName)
{
	// Only process tags in cim namespace
	if(std::string(xercesc::XMLString::transcode(qName)).find("cim:") == std::string::npos)
	{
		return;
	}

	// Pop Stacks
	if (tagStack.size() == 0) {
		std::cerr << "WARNING: Nearly tried to pop empty tag stack for tag: " << qName << std::endl;
	}
	else {
		tagStack.pop();
	}
	if(CIMFactory::IsCIMClass(std::string(xercesc::XMLString::transcode(qName))))
	{
		if (objectStack.size() == 0) {
			std::cerr << "WARNING: Nearly tried to pop empty object stack for tag: " << qName << std::endl;
		}
		else {
			objectStack.pop();
		}
		//std::cout << "Popped " << name << std::endl;
	}
}

void CIMContentHandler::characters(const XMLCh* const chars,
													const XMLSize_t length )
{
	// Only process tags in "cim" namespace
	if(tagStack.empty())
	{
		return;
	}
	if(objectStack.empty())
	{
		throw CriticalError("CIMContentHandler: Critical Error: objectStack empty");
	}

#ifndef DEBUG
	assign(objectStack.top(), tagStack.top(), std::string(xercesc::XMLString::transcode(chars)));
#else
	// Check if the characters only contain whitespace
	if(is_only_whitespace(characters))
	{
		return;
	}
	if(!assign(objectStack.top(), tagStack.top(), characters))
		std::cout << "CIMContentHandler: Note: Cannot assign '" << characters << "' to " << tagStack.top() << std::endl;
#endif
}

void CIMContentHandler::ignorableWhitespace(const std::string &ch)
{}

void CIMContentHandler::processingInstruction(const std::string &target, const std::string &data)
{}

void CIMContentHandler::skippedEntity(const std::string &name)
{}

std::string CIMContentHandler::get_rdf_id(const xercesc::Attributes &attributes)
{
	for(int i = 0; i < attributes.getLength(); i++)
	{
		if(std::string(xercesc::XMLString::transcode(attributes.getQName(i))) == "rdf:ID")
			return std::string(xercesc::XMLString::transcode(attributes.getValue(i)));
		if(std::string(xercesc::XMLString::transcode(attributes.getQName(i))) == "rdf:about")
			return std::string(xercesc::XMLString::transcode(attributes.getValue(i))).substr(1);
	}
	return std::string();
}

std::string CIMContentHandler::get_rdf_resource(const xercesc::Attributes &attributes)
{
    for (XMLSize_t i = 0; i < attributes.getLength(); i++) {
		if(std::string(xercesc::XMLString::transcode(attributes.getQName(i))) == "rdf:resource")
		{
			if(std::string(xercesc::XMLString::transcode(attributes.getValue(i))).at(0) == '#')
			{
				return std::string(xercesc::XMLString::transcode(attributes.getValue(i))).substr(1);
			}
		}
	}
	return std::string();
}

bool CIMContentHandler::is_only_whitespace(const std::string& characters)
{
	return std::regex_match(characters, std::regex("^[[:space:]]*$"));
}

std::string CIMContentHandler::get_rdf_enum(const xercesc::Attributes &attributes)
{
    for (XMLSize_t i = 0; i < attributes.getLength(); i++) {
		if(std::string(xercesc::XMLString::transcode(attributes.getQName(i))) == "rdf:resource")
		{
			std::regex expr("^http[s]*://[a-zA-Z0-9./_]*CIM-schema-cim[0-9]+#([a-zA-z0-9]*).([a-zA-z0-9]*)");
			std::smatch m;
			std::string str = std::string(xercesc::XMLString::transcode(attributes.getValue(i)));
			if(std::regex_match(str, m, expr))
			{
				return std::string(m[1]).append(".").append(m[2]);
			}
			std::cerr << "CIMContentHandler: Note: rdf:resource does not relate to an object in this file "<< str << std::endl;
		}
	}
	std::cerr << "CIMContentHandler: Note: Attribute contain no rdf:resource" << std::endl;
	return std::string();
}

bool CIMContentHandler::resolveRDFRelations()
{
	unsigned int unresolved;
	unresolved = 0;
	size_t taskSize = taskQueue.size();
	std::list<Task>::iterator it = taskQueue.begin();
	while(it != taskQueue.end())
	{
		if(!it->resolve(RDFMap))
		{
			std::cout << "CIMContentHandler: Note: Cannot resolve following RDF relationship: ";
			it->print();
			unresolved++;
			++it;
		}
		else
		{
			taskQueue.erase(it++);
		}
	}
	std::cout << "CIMContentHandler: Note: " << unresolved << " out of " << taskSize << " tasks remain unresolved!" << std::endl;
	if(unresolved > 0)
		return false;
	else
		return true;
}


void CIMContentHandler::error(const xercesc::SAXParseException& ex)
{
    char* message = xercesc::XMLString::transcode(ex.getMessage());
    std::cout << "Error " << message << " at line: " << ex.getLineNumber() << std::endl;
    xercesc::XMLString::release(&message);
}


void CIMContentHandler::fatalError(const xercesc::SAXParseException& ex)
{
    char* message = xercesc::XMLString::transcode(ex.getMessage());
    std::cout << "Fatal Error: " << message << " at line: " << ex.getLineNumber() << std::endl;
    xercesc::XMLString::release(&message);
}