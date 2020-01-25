//
// Created by Vathanan on 14/01/2020.
//
#include "Unit.h"

Unit::Unit(int p,int health, int prix, int ad, int rMin, int rMax, Battlefield *bf,bool t) {
    pos=p;
    hp=health;
    price=prix;
    attackDmg=ad;
    rangeMin=rMin;
    rangeMax=rMax;
    plateau=bf;
    team=t;
}

Unit::Unit(int p) {
    pos=p;
}

int Unit::getHp() const {
    return hp;
}

void Unit::setHp(int i) {
    Unit::hp = i;
}

int Unit::getPrice() const {
    return price;
}

void Unit::setPrice(int i) {
    Unit::price = i;
}

int Unit::getAttackDmg() const {
    return attackDmg;
}

void Unit::setAttackDmg(int i) {
    Unit::attackDmg = i;
}

int Unit::getRangeMin() const {
    return rangeMin;
}

void Unit::setRangeMin(int i) {
    Unit::rangeMin = i;
}

int Unit::getRangeMax() const {
    return rangeMax;
}

void Unit::setRangeMax(int i) {
    Unit::rangeMax = i;
}

Battlefield *Unit::getPlateau() const {
    return plateau;
}

void Unit::setPlateau(Battlefield *i) {
    plateau = i;
}

int Unit::getPos() const {
    return pos;
}

void Unit::setPos(int i) {
    Unit::pos = i;
}

bool Unit::isTeam() const {
    return team;
}

void Unit::setTeam(bool i) {
    Unit::team = i;
}



