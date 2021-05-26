#include "CIMFile.hpp"
#include "ModelDescription.hpp"

#include "ModelDescriptionHandler.hpp"
#include "ModelDescription.hpp"
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>

#include <iostream>
#include <fstream>

CIMFile::CIMFile(std::string path) : path(path), modelDescription(nullptr)
{
}

std::string CIMFile::getpath()
{
	return path;
}

ModelDescription* CIMFile::getModelDescription()
{
	if(modelDescription == nullptr)
	{
		if(!this->good())
		{
			//TODO: file not good, say something
			return nullptr;
		}
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
            return modelDescription;
        }

		modelDescription = new ModelDescription();
        ModelDescriptionHandler* DescriptionHandler = new ModelDescriptionHandler();
		DescriptionHandler->setModelDescription(modelDescription);


		xercesc::SAX2XMLReader* Reader = xercesc::XMLReaderFactory::createXMLReader();
        Reader->setFeature(xercesc::XMLUni::fgSAX2CoreValidation, false);
		// xmlReader->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);   // optional

        Reader->setContentHandler(DescriptionHandler);
        Reader->setErrorHandler(DescriptionHandler);
        Reader->parse(getpath().c_str());

	}

	return modelDescription;
}

bool CIMFile::good()
{
	if(path.find(".xml") == std::string::npos)
	{
		return false;
	}

	std::ifstream infile(path);
	return infile.good();
}
