//
// Created by Vathanan on 14/01/2020.
//
#include "Unit.h"

Unit::Unit(int p,int health, int prix, int ad, int rMin, int rMax, Battlefield *bf,bool t) {
    pos=p; //position dans le tableau de case
    hp=health; //points de vie actuel
    price=prix; //prix de d'achat de l'unité
    attackDmg=ad; //dégats d'attaque de l'unité
    rangeMin=rMin; //portée minimale
    rangeMax=rMax; //portée maximale
    plateau=bf; //plateau de jeu
    team=t;//appartenance à l'équipe, true pour bleu, false pour rouge
}
// getters et setters:
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
    std::string g;
    if(team){std::cout<< blue <<this->getNom()<<" a attaque "<<u->getNom()<<" et a inflige"<<i<<" points de degats"<< std::endl;}
    else{std::cout<< red <<this->getNom()<<" a attaque "<<u->getNom()<<" et a inflige"<<i<<" points de degats"<< std::endl;}
    std::cout<<g<<this->getNom()<<" a attaque "<<u->getNom()<<" et a inflige"<<i<<" points de degats"<< std::endl;
    u->takeDmg(i); //inflige les dégats
    act=true;//a effectué l'action
    if (u->isDead()){//vérifie si unité meurt
        this->promote();//promotion
        plateau->removeUnit(u->getPos());//suppresion de l'unité morte
    }
}

void Unit::takeDmg(int i) {
    this->setHp(this->hp-i);//enleve i aux points de vie

}

bool Unit::isDead() {
    if (hp<=0) {
        this->plateau->removeUnit(this->pos);
        return true;
    }
    return false;
}

void Unit::doDmg(Fort *f, int i) {
    f->takeDmg(i);//inflige degats
    act=true;//action effectuée
    std::string g;
    if(team){std::cout<< blue <<nom<<" a attaque "<<f->getNom()<<" et a inflige "<<i<<" points de degats" << std::endl;}
    else{std::cout<< red <<nom<<" a attaque "<<f->getNom()<<" et a inflige "<<i<<" points de degats" << std::endl;}


}

void Unit::attack(int position) {
    Case c=plateau->getCase(position);//recupère case cible
    Unit *u=c.getE();//recupere unité
    if (c.getE() == nullptr ){//si pas d'unité
        if(c.getF() != nullptr){//regarde si fort présent
            doDmg(c.getF(), attackDmg); //si oui attaque
        }
    }
    else{//si unité présente
        if(sameTeam(u)) //vérifie si même équipe
            {}
        else{doDmg(u, attackDmg);}//sinon attaque
    }

}

void Unit::move(int position) {
    Case c=plateau->getCase(position);//récupère case cible
        if (c.getE() == nullptr ){//si pas d'unité
            if(c.getF() == nullptr){//et si pas de fort
                plateau->moveUnit(pos,position);//se déplace
                std::string g;
                if(team){std::cout<< blue <<nom<<" a avance" << std::endl;}
                else{std::cout<< red <<nom<<" a avance" << std::endl;}
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






