//
// Created by Vathanan on 14/01/2020.
//

#include "Battlefield.h"
#include "Fantassin.h"

Battlefield::Battlefield() {
    for (int i=0;i<12;i++){
        caseElements[i]=Case();
    }
}

void Battlefield::Generer(Fort* f1,Fort* f2) {//génère les forts aux extrémités du plateau

    caseElements[0].setF(f1);
    caseElements[0].setEdgeCase(true);
    caseElements[11].setF(f2);
    caseElements[11].setEdgeCase(true);
}

std::ostream &operator<<(std::ostream &os, const Battlefield &battlefield) {//représentation du plateau
    os<<"|";
    for (const Case &t:battlefield.caseElements) {
        if (t.checkFree())
            os << "|   |";
        else
            if(t.getE()->isTeam())
                os <<"|"<< blue <<t.getE()->print()<< white <<"|";
            else
                os <<"|"<< red <<t.getE()->print()<< white <<"|";
    }
    return os << "|" <<std::endl;
}

void Battlefield::addUnit(Unit *u, int pos) {//rajout d'une unité u sur le terrain à la position pos
    if (caseElements[pos].checkFree()){//vérifie si emplacement vide
        caseElements[pos].addUnit(u);//rajoute sur plateau
        u->setPos(pos);}//met à jour attribut unité
    else {
        std::cout << "Case Pas Disponible";
    }
}

void Battlefield::removeUnit(int pos) {//enlève une unité du plateau
    if(caseElements[pos].checkFree()) {
        //std::cout << "Case Vide";
    }
    else{
        caseElements[pos].getE()->~Unit();//appel destructeur
        caseElements[pos].setE(nullptr);
    }
}

void Battlefield::moveUnit(int pos1,int pos2){//déplacement de l'unité du point pos1 au point pos2
    if(caseElements[pos2].checkFree()){//si case disponible
        caseElements[pos2].setE(caseElements[pos1].getE());//met dans case
        caseElements[pos1].setE(nullptr);//enlève de case occupé précédemment
        caseElements[pos2].getE()->setPos(pos2);}//màj de pos dans unit
    else
        std::cout << "Error";

}

bool Battlefield::checkCase(int pos) {
    return caseElements[pos].checkFree();
}

Case Battlefield::getCase(int pos){
    return caseElements[pos];
}

Battlefield::~Battlefield() {
    for (int i = 0; i < 12; ++i) {
        caseElements[i].~Case();
    }
    std::cout << "Destruction de plateau" << std::endl;
}

bool Battlefield::getTeam(int i) {
    return caseElements[i].getE()->isTeam();
}
