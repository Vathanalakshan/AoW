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

const std::string &Unit::getNom() const {
    return nom;
}

void Unit::setNom(const std::string &nom) {
    Unit::nom = nom;
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

bool Unit::sameTeam(Unit *u) {
    return(this->isTeam()==u->isTeam());
}

void Unit::setTeam(bool i) {
    Unit::team = i;
}

void Unit::doDmg(Unit *u, int i) {
    u->takeDmg(i);
    act=true;
    if (u->isDead()){
        this->promote();
        plateau->removeUnit(u->getPos());
    }
    std::cout<<nom<<" a attaqué "<<u->getNom()<<" et a infligé"<<i<<" points de dégats"<< std::endl;
}

void Unit::takeDmg(int i) {
    this->setHp(this->hp-i);
    bool b=isDead();
    //this->plateau->removeUnit(this->pos);

}

bool Unit::isDead() {
    if (hp<=0) {
        this->plateau->removeUnit(this->pos);
        return true;
    }
    return false;
}

void Unit::doDmg(Fort *f, int i) {
    f->takeDmg(i);
    act=true;
    std::cout<<nom<<" a attaqué "<<f->getNom()<<" et a infligé"<<i<<" points de dégats"<< std::endl;


}

void Unit::attack(int position) {
    Case c=plateau->getCase(position);
    Unit *u=c.getE();
    if (c.getE() == nullptr ){
        if(c.getF() != nullptr){
            doDmg(c.getF(), attackDmg);
        }
    }
    else{
        if(sameTeam(u))
            {}
        else{doDmg(u, attackDmg);}
    }

}

void Unit::move(int position) {
    Case c=plateau->getCase(position);
    if (!moved){
        if (c.getE() == nullptr ){
            if(c.getF() == nullptr){
                plateau->moveUnit(pos,position);
                std::cout << pos << "hhh" << position;
                moved=true;
            }
        }
    }
}

int Unit::getact() const {
    return act;
}

void Unit::setact(bool act) {
    this->act=act;
}

void Unit::setI(int j) {
    id=j;
}

int Unit::id=0;

Unit::~Unit() = default;






