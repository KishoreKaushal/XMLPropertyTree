//
// Created by kaushal on 02/12/20.
//
#include <xercesc/util/XMLString.hpp>
#include <iostream>


#ifndef XMLPROPERTYTREE_MAIN_H
#define XMLPROPERTYTREE_MAIN_H

class [[maybe_unused]] StrX {
public:
    [[maybe_unused]] explicit StrX(const XMLCh* const toTranscode) {
        fLocalForm = xercesc::XMLString::transcode(toTranscode);
    }

    ~StrX(){
        xercesc::XMLString::release(&fLocalForm);
    }

    [[nodiscard]] const char* localForm() const {
        return fLocalForm;
    }

private:
    char* fLocalForm;
};

inline std::ostream& operator<<(std::ostream& target, const StrX& toDump) {
    target << toDump.localForm();
    return target;
}

#endif //XMLPROPERTYTREE_MAIN_H
