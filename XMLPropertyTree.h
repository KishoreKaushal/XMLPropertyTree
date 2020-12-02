//
// Created by kaushal on 02/12/20.
//

#include <string>
#include <memory>
#include <utility>
#include <unordered_map>
#include <vector>
#include <exception>


#ifndef XMLPROPERTYTREE_XMLPROPERTYTREE_H
#define XMLPROPERTYTREE_XMLPROPERTYTREE_H

namespace XMLPropertyTree {

    class XMLElement {
    public:
        virtual std::string getCharacterData(const std::string&) const noexcept;

        virtual std::string getAttributeValue(const std::string&) const noexcept;

        virtual std::shared_ptr<XMLElement> getChildElement();

        virtual void addChildElement(const std::shared_ptr<XMLElement>&) const noexcept;

        /*
         * Make non-copyable, by deleting copy constructor and copy assignment operator.
         * */
        XMLElement() = default;
        XMLElement(const XMLElement&) = delete;
        XMLElement& operator=(const XMLElement&) = delete;

    private:
        const std::string                                           localname;
        const std::string                                           qname;
        const std::string                                           uri;
        const std::string                                           data;
        const std::unordered_map<std::string, std::string>          mattr;
        mutable std::vector<std::shared_ptr<XMLElement const>>      vchild;
    };

    class XMLTree {
    public:

    private:
        std::shared_ptr<XMLElement const>   root;
    };
}



#endif //XMLPROPERTYTREE_XMLPROPERTYTREE_H
