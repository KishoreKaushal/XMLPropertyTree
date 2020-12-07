//
// Created by kaushal on 02/12/20.
//

#include <string>
#include <memory>
#include <utility>
#include <unordered_map>
#include <vector>
#include <xercesc/sax2/DefaultHandler.hpp>
#include "XString.h"


#ifndef XMLPROPERTYTREE_XMLPROPERTYTREE_H
#define XMLPROPERTYTREE_XMLPROPERTYTREE_H

namespace XMLPropertyTree {

    class XMLElement {
    public:
        /**---------------------------------------------------------------------
         * Explicit Constructor for element initialization.
         *--------------------------------------------------------------------*/
         explicit XMLElement(const XMLCh*               localname,
                             const XMLCh*               qname,
                             const XMLCh*               uri,
                             const XMLCh*               data,
                             const xercesc::Attributes& attributes) noexcept;

        /*----------------------------------------------------------------------
         * Make non-copyable, by deleting copy constructor
         * and copy assignment operator.
         *--------------------------------------------------------------------*/
        XMLElement(const XMLElement&) = delete;
        XMLElement& operator=(const XMLElement&) = delete;

        virtual std::string getData(const std::string&) const noexcept;

        virtual std::string getAttributeValue(const std::string&) const noexcept;

        virtual std::shared_ptr<XMLElement> nthChildElement(const int&) const noexcept;

        virtual void addChildElement(const std::shared_ptr<XMLElement>&) const noexcept;

        virtual std::string operator[](const std::string&) const noexcept;

        virtual std::shared_ptr<XMLElement> operator[](const int&) const noexcept;

        virtual bool empty() const noexcept;

    private:
        const std::string                                   localname;
        const std::string                                   qname;
        const std::string                                   uri;
        const std::string                                   data;
        const std::unordered_map<std::string, std::string>  mattr;
        mutable std::vector<std::shared_ptr<XMLElement>>    vchild;
    };

    class XMLTree {
    public:
        /**---------------------------------------------------------------------
         * Constructor: uses std::move semantic to initialize XMLTree.
         *--------------------------------------------------------------------*/
        explicit XMLTree(std::unique_ptr<XMLElement>& argroot)
            : root(std::move(argroot)) {}

        ~XMLTree();

        XMLTree(const XMLTree&) = delete;
        XMLTree& operator=(const XMLTree&) = delete;

        virtual bool empty() const noexcept;

    private:
        const std::unique_ptr<XMLElement>   root;
    };
}



#endif //XMLPROPERTYTREE_XMLPROPERTYTREE_H
