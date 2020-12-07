//
// Created by kaushal on 02/12/20.
//

#include "XMLPropertyTree.h"

// TODO: XString(arg)() may go out-of-scope : Need to resolve this.
XMLPropertyTree::XMLElement::XMLElement(const XMLCh *arguri,
                                        const XMLCh *arglocalname,
                                        const XMLCh *argqname,
                                        const XMLCh *argdata,
                                        const xercesc::Attributes &argattributes)
                                        noexcept:
                                            uri(XString(arguri)()),
                                            localname(XString(arglocalname)()),
                                            qname(XString(argqname)()),
                                            data(XString(argdata)()) {

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


