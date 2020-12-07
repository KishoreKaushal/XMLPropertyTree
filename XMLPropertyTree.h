//
// Created by kaushal on 02/12/20.
//

#include <string>
#include <memory>
#include <utility>
#include <unordered_map>
#include <vector>


#ifndef XMLPROPERTYTREE_XMLPROPERTYTREE_H
#define XMLPROPERTYTREE_XMLPROPERTYTREE_H

namespace XMLPropertyTree {

    class XMLElement {
    public:
        virtual std::string getData(const std::string&) const noexcept;

        virtual std::string getAttributeValue(const std::string&) const noexcept;

        virtual std::shared_ptr<XMLElement> nthChildElement(const int&) const noexcept;

        virtual void addChildElement(const std::shared_ptr<XMLElement>&) const noexcept;

        virtual std::string operator[](const std::string&) const noexcept;

        virtual std::shared_ptr<XMLElement> operator[](const int&) const noexcept;

        virtual bool empty() const noexcept;

        /*
         * Make non-copyable, by deleting copy constructor and copy assignment operator.
         * */
        XMLElement() = default;
        XMLElement(const XMLElement&) = delete;
        XMLElement& operator=(const XMLElement&) = delete;

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
        XMLTree() = default;

        ~XMLTree();

        XMLTree(const XMLTree&) = delete;
        XMLTree& operator=(const XMLTree&) = delete;

        virtual bool empty() const noexcept;

    private:
        const std::shared_ptr<XMLElement>   root;
    };
}



#endif //XMLPROPERTYTREE_XMLPROPERTYTREE_H
