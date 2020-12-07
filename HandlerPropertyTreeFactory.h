//
// Created by kaushal on 02/12/20.
//

#include <xercesc/sax2/DefaultHandler.hpp>

#ifndef XMLPROPERTYTREE_HANDLERPROPERTYTREEFACTORY_H
#define XMLPROPERTYTREE_HANDLERPROPERTYTREEFACTORY_H

#include <xercesc/sax2/DefaultHandler.hpp>
#include "XMLPropertyTree.h"
#include "XString.h"
#include <stack>
#include <memory>

namespace XMLPropertyTree {

    class HandlerPropertyTreeFactory : public xercesc::DefaultHandler {
    public:
        HandlerPropertyTreeFactory() = default;

        ~HandlerPropertyTreeFactory();

        /**---------------------------------------------------------------------
         * Making non-copyable. Use std::move semantics.
         ---------------------------------------------------------------------*/

        HandlerPropertyTreeFactory(const HandlerPropertyTreeFactory&) = delete;
        HandlerPropertyTreeFactory& operator=(const HandlerPropertyTreeFactory&) = delete;

        /**---------------------------------------------------------------------
         * Implementation of the SAX DocumentHandler Interface
         ---------------------------------------------------------------------*/

        virtual void endDocument() override;

        virtual void endElement (const XMLCh* const uri,
                                 const XMLCh* const localname,
                                 const XMLCh* const qname) override;

        virtual void characters(const XMLCh*    chars,
                                const XMLSize_t length) override;

        virtual void ignorableWhitespace(const XMLCh*       chars,
                                         const XMLSize_t    length) override;

        virtual void processingInstruction(const XMLCh* const target,
                                           const XMLCh* const data) override;

        virtual void startDocument() override;

        virtual void startElement(const XMLCh* const            uri,
                          const XMLCh* const            localname,
                          const XMLCh* const            qname,
                          const xercesc::Attributes&    attrs) override;

        /**---------------------------------------------------------------------
         * Implementation of the SAX ErrorHandler Interface
         ---------------------------------------------------------------------*/
        virtual void error(const xercesc::SAXParseException& exc) override;

        virtual void fatalError(const xercesc::SAXParseException& exc) override;

        virtual void warning(const xercesc::SAXParseException& exc) override;

        virtual std::unique_ptr<XMLPropertyTree::XMLTree> getXMLTree();

    private:
        std::unique_ptr<XMLPropertyTree::XMLTree> xmltree;
        std::unique_ptr<XMLPropertyTree::XMLElement> rootelement;
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

    void HandlerPropertyTreeFactory::endDocument() {
        xmltree = std::make_unique<XMLPropertyTree::XMLTree>(rootelement);
    }

    void HandlerPropertyTreeFactory::startDocument() {

    }

    void HandlerPropertyTreeFactory::startElement(const XMLCh *const uri,
                                                  const XMLCh *const localname,
                                                  const XMLCh *const qname,
                                                  const xercesc::Attributes& attrs) {


    }

    void HandlerPropertyTreeFactory::error(const xercesc::SAXParseException& exc) {
        xmltree.reset(nullptr);
        std::cerr << "\nError at file " << XString(exc.getSystemId())
                  << ", line " << exc.getLineNumber()
                  << ", char " << exc.getColumnNumber()
                  << "\n  Message: " << XString(exc.getMessage())
                    << std::endl;
    }

    void HandlerPropertyTreeFactory::fatalError(const xercesc::SAXParseException& exc) {
        xmltree.reset(nullptr);
        std::cerr << "\nFatal Error at file " << XString(exc.getSystemId())
                  << ", line " << exc.getLineNumber()
                  << ", char " << exc.getColumnNumber()
                  << "\n  Message: " << XString(exc.getMessage())
                    << std::endl;
    }

    void HandlerPropertyTreeFactory::warning(const xercesc::SAXParseException& exc) {
        xmltree.reset(nullptr);
        std::cerr << "\nWarning at file " << XString(exc.getSystemId())
                  << ", line " << exc.getLineNumber()
                  << ", char " << exc.getColumnNumber()
                  << "\n  Message: " << XString(exc.getMessage())
                    << std::endl;
    }

    std::unique_ptr<XMLPropertyTree::XMLTree> HandlerPropertyTreeFactory::getXMLTree() {
        if(xmltree->empty()) {
            xmltree.reset(nullptr);
        }
        return std::move(xmltree);
    }

}


#endif //XMLPROPERTYTREE_HANDLERPROPERTYTREEFACTORY_H
