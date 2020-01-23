//
// Created by Vathanan on 14/01/2020.
//
#include "Fort.h"
Fort::Fort(int pos, int health, Battlefield *bf, Player *j) :Elements(pos) {
    hp=health;
    Plateau=bf;
    Joueur=j;
}

std::ostream &operator<<(std::ostream &os, const Fort &fort) {
    os << static_cast<const Elements &>(fort) << " hp: " << fort.hp << " Plateau: " << fort.Plateau << " Joueur: "
       << fort.Joueur;
    return os;
}

