//
// Created by Vathanan on 14/01/2020.
//
#include <string>
#include "Fort.h"
Fort::Fort(Battlefield *bf, bool b) {
    hp=100;
    Plateau=bf;
    team=b;
    gold=0;
    nom="Fort";
    if(b){
        nom="Fort bleu";
    }
    else{
        nom="Fort rouge";
    }
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
    os <<"Fort " << fort.isTeam() <<fort.getHp() << std::endl;
    return os;
}

int Fort::getGold() const {
    return gold;
}

void Fort::setGold(int i) {
    Fort::gold =i;
}

void Fort::takeDmg(int i) {
    setHp(hp-i);

}

std::string Fort::getNom() {
    return nom;
}
std::string Fort::print() {
    return getNom()+ " " + std::to_string(getHp()) + "Hp" + std::to_string(getGold()) + "Gold";
}

