//
// Created by kaushal on 02/12/20.
//

#include <xercesc/sax2/DefaultHandler.hpp>

#ifndef XMLPROPERTYTREE_HANDLERPROPERTYTREEFACTORY_H
#define XMLPROPERTYTREE_HANDLERPROPERTYTREEFACTORY_H

#include <xercesc/sax2/DefaultHandler.hpp>
#include "XMLPropertyTree.h"
#include "main.h"
#include <stack>
#include <memory>

namespace XMLPropertyTree {

    class HandlerPropertyTreeFactory : public xercesc::DefaultHandler {
    public:
        HandlerPropertyTreeFactory();

        ~HandlerPropertyTreeFactory();

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

    private:
        std::unique_ptr<XMLPropertyTree::XMLTree> xmltree;
        std::stack<std::shared_ptr<XMLElement>> belt;
    };

    void HandlerPropertyTreeFactory::characters(const XMLCh *const chars,
                                                const XMLSize_t length) {

    }

    void HandlerPropertyTreeFactory::endElement(const XMLCh *const uri,
                                                const XMLCh *const localname,
                                                const XMLCh *const qname) {

    }

    void HandlerPropertyTreeFactory::ignorableWhitespace(const XMLCh *const chars,
                                                         const XMLSize_t length) {

    }

    void HandlerPropertyTreeFactory::processingInstruction(const XMLCh *const target,
                                                           const XMLCh *const data) {

    }

    void HandlerPropertyTreeFactory::startDocument() {

    }

    void HandlerPropertyTreeFactory::startElement(const XMLCh *const uri,
                                                  const XMLCh *const localname,
                                                  const XMLCh *const qname,
                                                  const xercesc::Attributes& attrs) {


    }

    void HandlerPropertyTreeFactory::error(const xercesc::SAXParseException& exc) {
        std::cerr   << "\nError at file " << StrX(exc.getSystemId())
                    << ", line "  << exc.getLineNumber()
                    << ", char "  << exc.getColumnNumber()
                    << "\n  Message: " << StrX(exc.getMessage())
                    << std::endl;
    }

    void HandlerPropertyTreeFactory::fatalError(const xercesc::SAXParseException& exc) {
        std::cerr   << "\nFatal Error at file " << StrX(exc.getSystemId())
                    << ", line "  << exc.getLineNumber()
                    << ", char "  << exc.getColumnNumber()
                    << "\n  Message: " << StrX(exc.getMessage())
                    << std::endl;
    }

    void HandlerPropertyTreeFactory::warning(const xercesc::SAXParseException& exc) {
        std::cerr   << "\nWarning at file " << StrX(exc.getSystemId())
                    << ", line "  << exc.getLineNumber()
                    << ", char "  << exc.getColumnNumber()
                    << "\n  Message: " << StrX(exc.getMessage())
                    << std::endl;
    }

}


#endif //XMLPROPERTYTREE_HANDLERPROPERTYTREEFACTORY_H
