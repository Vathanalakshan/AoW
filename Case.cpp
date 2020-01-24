//
// Created by Vathanan on 24/01/2020.
//

#include "Case.h"

Unit *Case::getE() const {
    return u;
}

void Case::setE(Unit *i) {
    Case::u = i;
}

bool Case::isEdgeCase() const {
    return edgeCase;
}

void Case::setEdgeCase(bool i) {
    Case::edgeCase = i;
}

Fort *Case::getF() const {
    return f;
}

void Case::setF(Fort *i) {
    Case::f = i;
}

Case::Case() {}

std::ostream &operator<<(std::ostream &os, const Case &aCase) {
    os << "u: " << aCase.checkFree() << " edgeCase: " << aCase.edgeCase << " f: ";
    if(aCase.f != nullptr){
        os<<*aCase.f ;
    }else{
        os<<aCase.f<<std::endl;
    }
    return os;
}

bool Case::checkFree() const {
    {
        return u == nullptr;
    }
}

void Case::addUnit(Unit *e) {
    u=e;
}

