#include "CIMModel.hpp"
#include "CIMContentHandler.hpp"
#include "ModelDescriptionHandler.hpp"
#include "ModelDescription.hpp"
#include "CIMExceptions.hpp"


#include <xercesc/util/XMLString.hpp>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>


#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

CIMModel::CIMModel() : DependencyCheck(true)
{
}

CIMModel::~CIMModel()
{
	// Clean up the mess
	for(BaseClass* Object : Objects)
		delete Object;
}

bool CIMModel::addCIMFile(CIMFile file)
{
	if(!file.good())
	{
		return false;
	}

	Files.push_back(file);

	return true;
}

bool CIMModel::addCIMFile(std::string path)
{
	CIMFile file(path);

	if(!file.good())
	{
		return false;
	}

	Files.push_back(file);

	return true;
}

void CIMModel::parseFiles()
{
	// TODO: What happens when run twice?!
	CIMContentHandler* ContentHandler = new CIMContentHandler();
	ContentHandler->setObjectsContainer(&Objects);
	ContentHandler->setRDFMap(&RDFMap);
    try
    {
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch(const xercesc::XMLException& ex)
    {
        char* message = xercesc::XMLString::transcode(ex.getMessage());
        std::cout << "Initialization Error :\n";
        std::cout << "Exception message is: \n" << message << std::endl;
        xercesc::XMLString::release(&message);
        return;
    }

	for(CIMFile& file : Files) //TODO: Suche evtl. mit eigener dependency-liste beschleunigen
	{

		xercesc::SAX2XMLReader* xmlReader = xercesc::XMLReaderFactory::createXMLReader();
		xmlReader->setFeature(xercesc::XMLUni::fgSAX2CoreValidation, false);
		// xmlReader->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);   // optional
		// CIMContentHandler* cimContentHandler = new CIMContentHandler();

		xmlReader->setContentHandler(ContentHandler);
		xmlReader->setErrorHandler(ContentHandler);

		if(DependencyCheck == true)
		{
			if(!(file.getModelDescription()->dependencyID).empty()) //TODO: Ueberpruefung besser Implementieren
			{
				bool depFound;
				for(std::string& fileDepID : (file.getModelDescription()->dependencyID))
				{
					depFound = 0;
					for(CIMFile& fileDep : Files)
					{
						if(fileDep.getModelDescription()->rdfID == fileDepID)
						{
							depFound = 1;
							break;
						}
					}
					if(!depFound)
					{
						//throw MissingDependencyFile(this, fileDepID);
						std::cerr << "WARNING: Dependency " << fileDepID << " is missing" << std::endl;
					}
				}
			}
		}
        xmlReader->parse(file.getpath().c_str());


        delete xmlReader;
	}

	ContentHandler->resolveRDFRelations();
}

void CIMModel::setDependencyCheckOn()
{
	DependencyCheck = true;
}

void CIMModel::setDependencyCheckOff()
{
	DependencyCheck = false;
}

bool CIMModel::getDependencyCheck()
{
	return DependencyCheck;
}
