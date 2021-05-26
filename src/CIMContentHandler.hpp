#ifndef CIMCONTENTHANDLER_HPP
#define CIMCONTENTHANDLER_HPP

#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/sax2/Attributes.hpp>
#include <xercesc/util/XMLString.hpp>


#include <stack>
#include <list>
#include <unordered_map>
#include <vector>

#include "BaseClass.h"
#include "Task.hpp"
#include "Folders.hpp"

class CIMContentHandler : public xercesc::DefaultHandler
{
public:
	CIMContentHandler();
	~CIMContentHandler();
	std::vector<BaseClass*> *Objects;
	std::unordered_map<std::string, BaseClass*> *RDFMap;
	void setObjectsContainer(std::vector<BaseClass*> *Objects);
	void setRDFMap(std::unordered_map<std::string, BaseClass*> *RDFMap);

	void checkStacksEmpty(); //Check if tagStack or ObjectStack is empty, throw CriticalError if true

	bool resolveRDFRelations(); // AKA work through task queue

protected:
	void startDocument() override;
	void endDocument() override;
	//void startPrefixMapping(const std::string &prefix, const std::string &uri) override;
	//void endPrefixMapping(const std::string &prefix) override;
	void startElement( const XMLCh* const uri,
                  const XMLCh* const localname,
                  const XMLCh* const qname,
                  const xercesc::Attributes&  attrs );
	void endElement( const XMLCh* const uri,
					 const XMLCh* const localname,
					 const XMLCh* const qname );
	void characters( const XMLCh* const chars,
					 const XMLSize_t length );
	void ignorableWhitespace(const std::string &ch) ;
	void processingInstruction(const std::string &target, const std::string &data) ;
	void skippedEntity(const std::string &name) ;

	static std::string get_rdf_id(const xercesc::Attributes  &properties);
	static std::string get_rdf_resource(const xercesc::Attributes  &properties);
	static std::string get_rdf_enum(const xercesc::Attributes &properties);
	static bool is_only_whitespace(const std::string &characters);

    void error(const xercesc::SAXParseException& ex);
    void fatalError(const xercesc::SAXParseException& ex);

private:
	std::stack<BaseClass*> objectStack;
	std::stack<std::string> tagStack;
	std::list<Task> taskQueue;
};



#endif // CIMCONTENTHANDLER_HPP
