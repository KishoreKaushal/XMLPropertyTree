//
// Created by kaushal on 02/12/20.
//
#include <xercesc/util/XMLString.hpp>
#include <iostream>


#ifndef XMLPROPERTYTREE_XSTRING_H
#define XMLPROPERTYTREE_XSTRING_H

class [[maybe_unused]] XString {
public:
    [[maybe_unused]] explicit XString(const XMLCh* const toTranscode) {
        fLocalForm = xercesc::XMLString::transcode(toTranscode);
    }

    ~XString(){
        xercesc::XMLString::release(&fLocalForm);
    }

    [[nodiscard]] const char* localForm() const {
        return fLocalForm;
    }

private:
    char* fLocalForm;
};

inline std::ostream& operator<<(std::ostream& target, const XString& toDump) {
    target << toDump.localForm();
    return target;
}

#endif //XMLPROPERTYTREE_XSTRING_H
