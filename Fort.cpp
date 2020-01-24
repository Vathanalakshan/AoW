//
// Created by Vathanan on 14/01/2020.
//
#include "Fort.h"
Fort::Fort(int pos, int health, Battlefield *bf, bool b) {
    hp=health;
    Plateau=bf;
    team=b;
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

void Fort::setTeam(bool team) {
    Fort::team = team;
}

std::ostream &operator<<(std::ostream &os, const Fort &fort) {
    os <<"Fort" <<fort.getHp() << std::endl;
    return os;
}

