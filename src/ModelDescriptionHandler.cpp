#include "ModelDescriptionHandler.hpp"
#include "IEC61970/IEC61970CIMVersion.h"

#ifndef CGMES_BUILD
#include "IEC61970/Base/Domain/String.h"
#include "CIMNamespaces.hpp"
#else
#include "String.hpp"
#endif

#include <stdexcept>
#include <iostream>
#include <string>

#include "CIMExceptions.hpp"

using CIMPP::IEC61970CIMVersion;

ModelDescriptionHandler::ModelDescriptionHandler() : modelDescription(nullptr)
{
}


void ModelDescriptionHandler::startDocument()
{
	if(modelDescription == nullptr)
		throw MissingModelDescription(this);
}

void ModelDescriptionHandler::endDocument()
{}

void ModelDescriptionHandler::startPrefixMapping(const std::string &prefix, const std::string &uri)
{
	if(prefix == "cim")
	{
		std::size_t pos = IEC61970CIMVersion::version.find("CIM");
		std::string versionParser = IEC61970CIMVersion::version.substr(pos+3,2);

		pos = uri.find("cim");
		std::string versionFile = uri.substr(pos+3,2);

		if(versionParser != versionFile)
		{
			std::cout << "CIM version(" << versionFile << ") in File does not match CIM version(" << versionParser << ") in Parser" << std::endl;
		}
	}
}

void ModelDescriptionHandler::startElement(const std::string &namespaceURI, const std::string &localName, const std::string &qName, const xercesc::Attributes &atts)
{
	//Only process tags in md namespace
	if(qName.find("md:") == std::string::npos)
	{
		return;
	}

	tagStack.push(qName);

	if(qName.find("DependentOn") != std::string::npos)
	{
		std::string rdfID = get_rdf_resource(atts);

		modelDescription->dependencyID.push_back(rdfID);
	}
	else if(qName.find("FullModel") != std::string::npos)
	{
		std::string rdfID = get_rdf_id(atts);

		modelDescription->rdfID = rdfID;
	}
}

void ModelDescriptionHandler::endElement(const std::string &namespaceURI, const std::string &localName, const std::string &qName)
{
	//Only process tags in md namespace
	if(qName.find("md:") == std::string::npos)
	{
		return;
	}

	tagStack.pop();
}

void ModelDescriptionHandler::characters(const std::string &ch) //TODO:getter
{
	if(!tagStack.empty() && tagStack.top().find("md:") != std::string::npos)
	{
		std::string name = tagStack.top();
		if(name.find("created") != std::string::npos)
		{
			modelDescription->created = ch;
		}
		else if(name.find("scenarioTime") != std::string::npos)
		{
			modelDescription->scenarioTime = ch;
		}
		else if(name.find("version") != std::string::npos)
		{
			modelDescription->version = ch;
		}
		else if(name.find("description") != std::string::npos)
		{
			modelDescription->description = ch;
		}
		else if(name.find("modelingAuthoritySet") != std::string::npos)
		{
			modelDescription->modelingAuthoritySet = ch;
		}
		else if(name.find("profile") != std::string::npos)
		{
			modelDescription->profile = ch;
		}

	}

}

void ModelDescriptionHandler::ignorableWhitespace(const std::string &ch)
{}

void ModelDescriptionHandler::processingInstruction(const std::string &target, const std::string &data)
{}

void ModelDescriptionHandler::skippedEntity(const std::string &name)
{}

std::string ModelDescriptionHandler::get_rdf_id(const xercesc::Attributes &attributes)
{
 	for(int i = 0; i < attributes.getLength(); i++)
 	{
 		if(xercesc::XMLString::transcode(attributes.getQName(i)) == "rdf:ID")
 			return std::string(xercesc::XMLString::transcode(attributes.getValue(i)));
 		if(xercesc::XMLString::transcode(attributes.getQName(i)) == "rdf:about")
 			return std::string(xercesc::XMLString::transcode(attributes.getValue(i))).substr(0);
 	}
 	return std::string();
}

std::string ModelDescriptionHandler::get_rdf_resource(const xercesc::Attributes &attributes) //TODO: Resource in get_rdf_id ?
{
	for(int i = 0; i < attributes.getLength(); i++)
 	{
 		if(xercesc::XMLString::transcode(attributes.getQName(i)) == "rdf:resource")
 		{
 			return std::string(xercesc::XMLString::transcode(attributes.getValue(i))).substr(0);
 		}
 	}
 	return std::string();
}

void ModelDescriptionHandler::setModelDescription(ModelDescription* mDesc)
{
	modelDescription = mDesc;
}


void ModelDescriptionHandler::error(const xercesc::SAXParseException& ex)
{
	char* message = xercesc::XMLString::transcode(ex.getMessage());
	std::cout << "Error " << message << " at line: " << ex.getLineNumber() << std::endl;
	xercesc::XMLString::release(&message);
}


void ModelDescriptionHandler::fatalError(const xercesc::SAXParseException& ex)
{
	char* message = xercesc::XMLString::transcode(ex.getMessage());
	std::cout << "Fatal Error: " << message << " at line: " << ex.getLineNumber() << std::endl;
	xercesc::XMLString::release(&message);
}