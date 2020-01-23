//
// Created by Vathanan on 14/01/2020.
//

#include "Battlefield.h"

Battlefield::Battlefield(){
}

void Battlefield::addUnit(int pos, Elements *e) {
    if(caseElements[pos] == nullptr){
        caseElements[pos]=e;
    } else{
        std::cout << "Erreur d'ajout" << std::endl;
        std::cout << caseElements[pos]<<std::endl;
    }
}

void Battlefield::removeUnit(int pos) {
    if(caseElements[pos] != nullptr){
        caseElements[pos]=nullptr;
    } else{
        std::cout << "Erreur d'ajout" << std::endl;
    }
}

Elements *Battlefield::getElement(int pos) {
    return caseElements[pos];
}

void Battlefield::Generer(Player& P1,Player& P2){
    Fort f1(0,100,this,&P2);
    Fort f2(11,100,this,&P1);
    this->addUnit(0,&f1);
    this->addUnit(11,&f2);
}

void Battlefield::Printfile() {
    for (int i =0 ; i < sizeof(caseElements); i++)
        if (caseElements[i] == nullptr)
            std::cout << caseElements[i];
}


