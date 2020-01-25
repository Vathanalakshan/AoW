//
// Created by Vathanan on 14/01/2020.
//
#include "Fantassin.h"
#include "EmptyCase.h"

Fantassin::Fantassin(int pos,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, Player *joueur)
        : Unit(pos,hp, price, attackDmg, rangeMin, rangeMax, plateau, joueur) {}

std::ostream &operator<<(std::ostream &os, const Fantassin &fantassin) {
    os << "Haha";
    return os;
}


void Fantassin::action1(){
    if (isTeam()){
        attack(pos+1);
    }
    else{
        attack(pos-1);
    }

std::cout<< "1 " << std::endl;
};
void Fantassin::action2(){
    if (isTeam()){
        move(pos+1);
    }
    else{
        move(pos-1);
    }
std::cout<< "1 " << std::endl;

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
};