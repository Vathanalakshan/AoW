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

void Battlefield::Generer(Fort* f1,Fort* f2) {

    caseElements[0].setF(f1);
    caseElements[0].setEdgeCase(true);
    caseElements[11].setF(f2);
    caseElements[11].setEdgeCase(true);
}

std::ostream &operator<<(std::ostream &os, const Battlefield &battlefield) {
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

void Battlefield::addUnit(Unit *u, int pos) {
    if (caseElements[pos].checkFree()){
        caseElements[pos].addUnit(u);
        u->setPos(pos);}
    else {
        std::cout << "Case Pas Disponible";
    }
}

void Battlefield::removeUnit(int pos) {
    if(caseElements[pos].checkFree()) {
        //std::cout << "Case Vide";
    }
    else{
        caseElements[pos].getE()->~Unit();
        caseElements[pos].setE(nullptr);
    }
}

void Battlefield::moveUnit(int pos1,int pos2){
    if(caseElements[pos2].checkFree()){
        caseElements[pos2].setE(caseElements[pos1].getE());
        caseElements[pos1].setE(nullptr);
        caseElements[pos2].getE()->setPos(pos2);}
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
