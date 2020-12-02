//
// Created by kaushal on 02/12/20.
//

#include <xercesc/sax2/DefaultHandler.hpp>

#ifndef XMLPROPERTYTREE_CREATEPROPERTYTREEHANDLER_H
#define XMLPROPERTYTREE_CREATEPROPERTYTREEHANDLER_H

#include <xercesc/sax2/DefaultHandler.hpp>
#include "XMLPropertyTree.h"
#include "main.h"

namespace XMLPropertyTree {

    class CreatePropertyTreeHandler : public xercesc::DefaultHandler {
    public:
        CreatePropertyTreeHandler();

        ~CreatePropertyTreeHandler();

        /**---------------------------------------------------------------------
         * Implementation of the SAX DocumentHandler Interface
         ---------------------------------------------------------------------*/

        void endDocument() override;

        void endElement (
                const XMLCh* const uri,
                const XMLCh* const localname,
                const XMLCh* const qname) override;

        void characters(const XMLCh*    chars,
                        const XMLSize_t length) override;

        void ignorableWhitespace(const XMLCh*       chars,
                                 const XMLSize_t    length) override;

        void processingInstruction(const XMLCh* const target,
                                   const XMLCh* const data) override;

        void startDocument() override;

        void startElement(const XMLCh* const            uri,
                          const XMLCh* const            localname,
                          const XMLCh* const            qname,
                          const xercesc::Attributes&    attrs) override;

        /**---------------------------------------------------------------------
         * Implementation of the SAX ErrorHandler Interface
         ---------------------------------------------------------------------*/
        void error(const xercesc::SAXParseException& exc) override;

        void fatalError(const xercesc::SAXParseException& exc) override;

        void warning(const xercesc::SAXParseException& exc) override;

    };

    void CreatePropertyTreeHandler::characters(const XMLCh *const chars,
                                               const XMLSize_t length) {

    }

    void CreatePropertyTreeHandler::endElement(const XMLCh *const uri,
                                               const XMLCh *const localname,
                                               const XMLCh *const qname) {

    }

    void CreatePropertyTreeHandler::ignorableWhitespace(const XMLCh *const chars,
                                                        const XMLSize_t length) {

    }

    void CreatePropertyTreeHandler::processingInstruction(const XMLCh *const target,
                                                          const XMLCh *const data) {

    }

    void CreatePropertyTreeHandler::startDocument() {

    }

    void CreatePropertyTreeHandler::startElement(const XMLCh *const uri,
                                                 const XMLCh *const localname,
                                                 const XMLCh *const qname,
                                                 const xercesc::Attributes& attrs) {


    }

    void CreatePropertyTreeHandler::error(const xercesc::SAXParseException& exc) {
        std::cerr   << "\nError at file " << StrX(exc.getSystemId())
                    << ", line "  << exc.getLineNumber()
                    << ", char "  << exc.getColumnNumber()
                    << "\n  Message: " << StrX(exc.getMessage())
                    << std::endl;
    }

    void CreatePropertyTreeHandler::fatalError(const xercesc::SAXParseException& exc) {
        std::cerr   << "\nFatal Error at file " << StrX(exc.getSystemId())
                    << ", line "  << exc.getLineNumber()
                    << ", char "  << exc.getColumnNumber()
                    << "\n  Message: " << StrX(exc.getMessage())
                    << std::endl;
    }

    void CreatePropertyTreeHandler::warning(const xercesc::SAXParseException& exc) {
        std::cerr   << "\nWarning at file " << StrX(exc.getSystemId())
                    << ", line "  << exc.getLineNumber()
                    << ", char "  << exc.getColumnNumber()
                    << "\n  Message: " << StrX(exc.getMessage())
                    << std::endl;
    }

}


#endif //XMLPROPERTYTREE_CREATEPROPERTYTREEHANDLER_H
