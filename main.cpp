#include <iostream>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>
#include "HandlerPropertyTreeFactory.h"
#include "XString.h"

static char* execName = nullptr;
static void usage() {
    std::cout   << "\nUsage: " << execName << " <XML Schema> <XML file>\n\n"
                   "This program invokes the SAX2XMLReader, and then generates an\n"
                   "XMLPropertyTree and prints it.\n\n"
               << std::endl;
}

static                         char*      xmlFile            = 0;
static xercesc::SAX2XMLReader::ValSchemes valScheme          = xercesc::SAX2XMLReader::Val_Auto;
static                         bool       doNamespaces       = true;
static                         bool       doSchema           = true;
static                         bool       schemaFullChecking = true;
static                         bool       namespacePrefixes  = false;
static                         XMLCh*     externalSchema     = nullptr;

int main(int argC, char* argV[]) {

    try {
        xercesc::XMLPlatformUtils::Initialize();    // initialize the XML4C2 system
    } catch (const xercesc::XMLException& e) {
        std::cerr   << "Error during initialization! :\n"
                    << XString(e.getMessage()) << std::endl;
        return 1;
    }

    // command-line arguments
    if (argC < 3) {
        xercesc::XMLPlatformUtils::Terminate();
        return 1;
    }

    execName        = argV[0];                                          // executable name
    externalSchema  = xercesc::XMLString::transcode(argV[1]);           // XSD file name
    xmlFile         = argV[2];                                          // XML file name

    //
    //  Create a SAX parser object. Then, according to what we were told on
    //  the command line, set it to validate or not.
    //
    // creating a unique_ptr for automatic memory management.
    std::unique_ptr<xercesc::SAX2XMLReader> parser(xercesc::XMLReaderFactory::createXMLReader());

    parser->setFeature(xercesc::XMLUni::fgSAX2CoreNameSpaces, doNamespaces);
    parser->setFeature(xercesc::XMLUni::fgXercesSchema, doSchema);
    parser->setFeature(xercesc::XMLUni::fgXercesHandleMultipleImports, true);
    parser->setFeature(xercesc::XMLUni::fgXercesSchemaFullChecking, schemaFullChecking);
    parser->setFeature(xercesc::XMLUni::fgSAX2CoreNameSpacePrefixes, namespacePrefixes);

    // for using external schema for validation
    parser->setProperty(xercesc::XMLUni::fgXercesSchemaExternalNoNameSpaceSchemaLocation,
                        static_cast<void*>(externalSchema));


    //  Create the handler object and install it as the document and error
    //  handler for the parser. Then parse the file and catch any exceptions
    //  that propogate out
    //

    XMLSize_t errorCount = 0;
    int errorCode = 0;
    try
    {
        XMLPropertyTree::HandlerPropertyTreeFactory handler;
        parser->setContentHandler(&handler);
        parser->setErrorHandler(&handler);
        parser->parse(xmlFile);
        errorCount = parser->getErrorCount();
    }
    catch (const xercesc::OutOfMemoryException&)
    {
        std::cerr << "OutOfMemoryException" << std::endl;
        errorCode = 5;
    }
    catch (const xercesc::XMLException& e)
    {
        std::cerr << "\nAn error occurred\n  Error: "
                                  << XString(e.getMessage())
                                  << "\n" << std::endl;
        errorCode = 4;
    }

    if(errorCode) {
        xercesc::XMLPlatformUtils::Terminate();
        return errorCode;
    }

    // And call the termination method
    xercesc::XMLPlatformUtils::Terminate();

    if (errorCount > 0)
        return 4;
    else
        return 0;

    return 0;
}
