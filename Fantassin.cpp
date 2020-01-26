//
// Created by Vathanan on 14/01/2020.
//
#include "Fantassin.h"


Fantassin::Fantassin(int pos,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, bool t)
        : Unit(pos,hp, price, attackDmg, rangeMin, rangeMax, plateau, t) {
    id++;
    nom = "Fan-" + std::to_string(id);//nom=classe+id
}

std::ostream &operator<<(std::ostream &os, const Fantassin &fantassin) {
    os << fantassin.getNom() <<" "<<fantassin.getHp() <<" Hp";
    return os;
}


void Fantassin::action1(){//action1: attaque
    if (isTeam()){//vérifie équipe, si bleu se dirige vers la droite
            int p = pos + 1;//portée de 1
            attack(p);//essaye d'attaquer par rapport à sa portée

    }
    else{//si rouge si dirige vers la gauche
            int p = pos - 1;//portée de 1
            attack(p);//essaye d'attaquer par rapport à sa portée

    }

};

void Fantassin::action2(){//action 2 se déplacer
    if (isTeam()) {//vérifie équipe, si bleu se dirige vers la droite
        if (pos < 10) {//vérifie limite droite du plateau
        int p = pos + 1;
        move(p);

        }

    }
    else{
        if(pos>1) {//vérifie limite gauche du plateau
            int p = pos - 1;
            move(p);

        }
    }

};

void Fantassin::action3(){//action 3, attaque si pas déjà fait, ou si supersoldat
    if(getact()){//si déjà attaquer
        if (superSoldat){//mais super soldat
            action1();//alors attaque selon équipe
        }
    }
    else{action1();}//si pas attaquer essaye d'attaquer
    setact(false);//réinitialisation du bool action effectuée pour le prochain tour

}

void Fantassin::promote() {//promotion en supersoldat après kill d'une unité
    superSoldat=true;
    nom="S"+nom;

}

std::string Fantassin::print() {
    return getNom()+ " " + std::to_string(getHp()) + "Hp";
}

Fantassin::~Fantassin() {
    std::cout<< nom << " meurt." << std::endl;
}

