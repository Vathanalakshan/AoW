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

void Battlefield::Generer(Player *p) {
    Fort *f1=new Fort(0,100,this,true);
    Fort *f2=new Fort(11,100,this,true);

    caseElements[0].setF(f1);
    caseElements[0].setEdgeCase(true);
    caseElements[11].setF(f2);
    caseElements[11].setEdgeCase(true);
    Fantassin *fan=new Fantassin(1,10,100,1,5,12,this,p);
    caseElements[1].addUnit(fan);
}

std::ostream &operator<<(std::ostream &os, const Battlefield &battlefield) {
    for(const Case &t:battlefield.caseElements){
        os << t << std::endl;
    }
    return os;
}
