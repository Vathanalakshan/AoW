//
// Created by Vathanan on 14/01/2020.
//

#include "Archer.h"
Archer::Archer(int p,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, bool t)
        : Unit(p,hp, price, attackDmg, rangeMin, rangeMax, plateau, t) {
    id++;
    nom = "Arc-" + std::to_string(id);

}

void Archer::action1(){//attaque l'ennemi le plus proche
    int rM=rangeMax;
    if(pos==8 && team){rM=3;}
    for (int i=rangeMin; i<rM+1;i++){//pour tout la portée, en partant du plus proche
        if (!act) {//si pas déjà attaquer
            if (isTeam()) {//attaque selon coté
                attack(pos + i);
            } else {
                attack(pos - i);
            }
        }
    }
    act=false;//réinitialisation pour tour prochain

};
void Archer::action2(){//déplacement par rapport à la limite du terrain+ portée max
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

};
void Archer::action3(){
}

void Archer::promote() {

}

std::string Archer::print() {
    return getNom()+ " " + std::to_string(getHp())+ "Hp";
}

Archer::~Archer() {
    std::cout<< nom << " meurt." << std::endl;
}

