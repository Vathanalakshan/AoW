//
// Created by Vathanan on 14/01/2020.
//
#include "Fantassin.h"


Fantassin::Fantassin(int pos,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, bool t)
        : Unit(pos,hp, price, attackDmg, rangeMin, rangeMax, plateau, t) {
    id++;
    nom = "Fan-" + std::to_string(id);
}

std::ostream &operator<<(std::ostream &os, const Fantassin &fantassin) {
    os << fantassin.getNom() <<" "<<fantassin.getHp() <<" Hp";
    return os;
}


void Fantassin::action1(){
    if (isTeam()){
        int p=pos+1;
        attack(p);
    }
    else{
        int p=pos-1;
        attack(p);
    }

std::cout<< "1 " << std::endl;
};

void Fantassin::action2(){
    if (isTeam()){
        int p=pos+1;
        move(p);
        std::cout<< "+1 " << std::endl;

    }
    else{
        int p=pos+1;
        move(p);
        std::cout<< "-1 " << std::endl;
    }
};

void Fantassin::action3(){
    if(getact()){
        if (superSoldat){
            action1();
        }
    }
    else{action1();}
    setact(false);
std::cout<< "1 " << std::endl;
}

void Fantassin::promote() {
    superSoldat=true;

}

std::string Fantassin::print() {
    return getNom()+ " " + std::to_string(getHp()) + "Hp";
}