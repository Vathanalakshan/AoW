//
// Created by Vathanan on 14/01/2020.
//
#include "Fort.h"
Fort::Fort(int pos, Battlefield *bf, bool b) {
    hp=100;
    Plateau=bf;
    team=b;
    gold=0;
}

int Fort::getHp() const {
    return hp;
}

void Fort::setHp(int hp) {
    Fort::hp = hp;
}

Battlefield *Fort::getPlateau() const {
    return Plateau;
}

void Fort::setPlateau(Battlefield *plateau) {
    Plateau = plateau;
}

bool Fort::isTeam() const {
    return team;
}

void Fort::setTeam(bool i) {
    Fort::team = i;
}

std::ostream &operator<<(std::ostream &os, const Fort &fort) {
    os <<"Fort" <<fort.getHp() << std::endl;
    return os;
}

int Fort::getGold() const {
    return gold;
}

void Fort::setGold(int i) {
    Fort::gold =Fort::gold+ i;
}

