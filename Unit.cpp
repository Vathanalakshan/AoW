//
// Created by Vathanan on 14/01/2020.
//
#include "Unit.h"

Unit::Unit(int p,int health, int prix, int ad, int rMin, int rMax, Battlefield *bf, Player *j) : Elements(p) {
    hp=health;
    price=prix;
    attackDmg=ad;
    rangeMin=rMin;
    rangeMax=rMax;
    Plateau=bf;
    Joueur=j;
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
    return Plateau;
}

void Unit::setPlateau(Battlefield *plateau) {
    Plateau = plateau;
}

Player *Unit::getJoueur() const {
    return Joueur;
}

void Unit::setJoueur(Player *joueur) {
    Joueur = joueur;
}



