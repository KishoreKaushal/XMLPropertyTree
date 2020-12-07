//
// Created by kaushal on 02/12/20.
//

#include "XMLPropertyTree.h"

XMLPropertyTree::XMLElement::XMLElement(const XString&              arguri,
                                        const XString&              arglocalname,
                                        const XString&              argqname,
                                        const xercesc::Attributes&  argattributes)
                                        noexcept:
                                            uri(arguri()),
                                            localname(arglocalname()),
                                            qname(argqname()) {

    // Initializing attribute map
    XMLSize_t numattr = argattributes.getLength();

    for (XMLSize_t i = 0; i < numattr; i++) {
        mattr.insert(std::make_pair(qname, XString(argattributes.getValue(i))()));
    }

}


std::string XMLPropertyTree::XMLElement::getData() const noexcept {
    return data;
}

std::string XMLPropertyTree::XMLElement::getAttributeValue(const std::string& attr)
const noexcept {
    return mattr.at(attr);
}

std::shared_ptr<XMLPropertyTree::XMLElement>
XMLPropertyTree::XMLElement::nthChildElement(const int& n) const noexcept {
    return vchild.at(n);
}

std::string XMLPropertyTree::XMLElement::operator[](const std::string &attr)
const noexcept {
    return getAttributeValue(attr);
}

std::shared_ptr<XMLPropertyTree::XMLElement>
XMLPropertyTree::XMLElement::operator[](const int &n) const noexcept {
    return nthChildElement(n);
}

bool XMLPropertyTree::XMLElement::empty() const noexcept {
    if(data.empty() and mattr.empty() and vchild.empty()) {
        return true;
    }
    return false;
}

std::string XMLPropertyTree::XMLElement::getLocalname() const noexcept {
    return localname;
}

std::string XMLPropertyTree::XMLElement::getQname() const noexcept {
    return qname;
}

std::string XMLPropertyTree::XMLElement::getUri() const noexcept {
    return uri;
}

void XMLPropertyTree::XMLElement::addChildElement(const std::shared_ptr<XMLElement>& xElement)
noexcept {
    vchild.push_back(xElement);
}

void XMLPropertyTree::XMLElement::setData(const XString &argdata) noexcept {
    data = argdata();
}

bool XMLPropertyTree::XMLTree::empty() const noexcept {
    if (root) return root->empty();
    return false;
}
