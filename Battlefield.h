//
// Created by Vathanan on 14/01/2020.
//

#ifndef AOW_BATTLEFIELD_H
#define AOW_BATTLEFIELD_H

#include <array>
#include <ostream>
#include "Fort.h"
#include "Case.h"


class Battlefield
{
protected:

    std::array<Case,12> caseElements;

public:
    Battlefield();

    friend std::ostream &operator<<(std::ostream &os, const Battlefield &battlefield);

    void Generer();
    void addUnit(Unit *u,int pos);
    void removeUnit(int pos);
    void moveUnit(int pos1, int pos2);

};



#endif //AOW_BATTLEFIELD_H