//
// Created by kaushal on 02/12/20.
//

#include <string>
#include <memory>
#include <utility>
#include <unordered_map>
#include <vector>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/sax2/Attributes.hpp>
#include "XString.h"


#ifndef XMLPROPERTYTREE_XMLPROPERTYTREE_H
#define XMLPROPERTYTREE_XMLPROPERTYTREE_H

namespace XMLPropertyTree {

    class XMLElement {
    public:
        /**---------------------------------------------------------------------
         * Explicit Constructor for element initialization.
         *--------------------------------------------------------------------*/
         explicit XMLElement(const XString&             arguri,
                             const XString&             arglocalname,
                             const XString&             argqname,
                             const xercesc::Attributes& argattributes) noexcept;

        /*----------------------------------------------------------------------
         * Make non-copyable, by deleting copy constructor
         * and copy assignment operator.
         *--------------------------------------------------------------------*/
        XMLElement(const XMLElement&) = delete;
        XMLElement& operator=(const XMLElement&) = delete;

        virtual void setData(const XString& argdata) noexcept;

        virtual std::string getData() const noexcept;

        virtual std::string getLocalname() const noexcept;

        virtual std::string getQname() const noexcept;

        virtual std::string getUri() const noexcept;

        virtual std::string getAttributeValue(const std::string& attr) const noexcept;

        virtual XMLElement* nthChildElement(const int& n) const noexcept;

        virtual void addChildElement(std::unique_ptr<XMLElement> xmlElement) noexcept;

        virtual std::string operator[](const std::string& attr) const noexcept;

        virtual XMLElement* operator[](const int& n) const noexcept;

        virtual bool empty() const noexcept;

    private:
        std::string                                     localname;
        std::string                                     qname;
        std::string                                     uri;
        std::string                                     data;
        std::unordered_map<std::string, std::string>    mattr;
        std::vector<std::unique_ptr<XMLElement>>        vchild;
    };

    class XMLTree {
    public:
        /**---------------------------------------------------------------------
         * Constructor: uses std::move semantic to initialize XMLTree.
         *--------------------------------------------------------------------*/
        explicit XMLTree(std::unique_ptr<XMLElement> argroot)
            : root(std::move(argroot)) {}

        XMLTree(const XMLTree&) = delete;
        XMLTree& operator=(const XMLTree&) = delete;

        virtual bool empty() const noexcept;

    private:
        const std::unique_ptr<XMLElement>   root;
    };
}



#endif //XMLPROPERTYTREE_XMLPROPERTYTREE_H
