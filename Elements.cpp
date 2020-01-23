//
// Created by Vathanan on 14/01/2020.
//

#include "Elements.h"

int  Elements::getPos() const{
    return pos;
}

std::ostream &operator<<(std::ostream &os, const Elements &elements) {
    os << "pos: " << elements.pos;
    return os;
}

Elements::Elements(int pos) : pos(pos) {};
