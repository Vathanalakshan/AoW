//
// Created by Vathanan on 14/01/2020.
//

#include "Catapulte.h"

Catapulte::Catapulte(int p,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, bool t)
        : Unit(p,hp, price, attackDmg, rangeMin, rangeMax, plateau, t) {
    id=i;
    i=i++;
    if(team){
        nom="Catapulte "+id;
        nom=nom+" bleu";
    }
    else {
        nom = "Catapulte " + id;
        nom = nom + " rouge";
    }
}


void Catapulte::action1(){
    for (i=rangeMin; i<rangeMax;i++){
        if (!act) {
            if (isTeam()) {
                attack(pos + i);
                attack(pos+i+1);
            } else {
                attack(pos - i);
                attack(pos - i-1);
            }
        }
    }
    if(!act){
        if(isTeam()){
            attack(pos+rangeMax);
            Case c=plateau->getCase(pos+rangeMax-1);
            doDmg(c.getE(),attackDmg);
        }
        else{
            attack(pos-rangeMax);
            Case c=plateau->getCase(pos-rangeMax+1);
            doDmg(c.getE(),attackDmg);
        }
    }
    std::cout<< "1 " << std::endl;
};

void Catapulte::action2(){
    std::cout<< "1 " << std::endl;

};
void Catapulte::action3(){
    if(!getact()){
        if (isTeam()){
            move(pos+1);
        }
        else{
            move(pos-1);
        }
    }
    std::cout<< "1 " << std::endl;
};