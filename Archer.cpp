//
// Created by Vathanan on 14/01/2020.
//

#include "Archer.h"
Archer::Archer(int p,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, bool t)
        : Unit(p,hp, price, attackDmg, rangeMin, rangeMax, plateau, t) {
    id++;
    nom = "Arc-" + std::to_string(id);

}

void Archer::action1(){
    moved=false;
    int rM=rangeMax;
    if(pos==8 && team){rM=3;}
    if(pos==7 && team){rM=4;}
    for (int i=rangeMin; i<rM+1;i++){
        if (!act) {
            if (isTeam()) {
                attack(pos + i);
            } else {
                attack(pos - i);
            }
        }
    }
    act=false;

    std::cout<< "1 " << std::endl;
};
void Archer::action2(){
    if (isTeam()){
        if (pos < 8) {
            move(pos + 1);
        }
    }
    else{
            if (pos > 3) {
                move(pos-1);
            }
    }
    std::cout<< "1 " << std::endl;

};
void Archer::action3(){
    std::cout<< "1 " << std::endl;
}

void Archer::promote() {

}

std::string Archer::print() {
    return getNom()+ " " + std::to_string(getHp())+ "Hp";
}

Archer::~Archer() {
    std::cout<< nom << " meurt." << std::endl;
}

