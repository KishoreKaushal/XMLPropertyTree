//
// Created by kaushal on 02/12/20.
//

#include "XMLPropertyTree.h"

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
