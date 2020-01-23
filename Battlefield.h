//
// Created by Vathanan on 14/01/2020.
//

#ifndef AOW_BATTLEFIELD_H
#define AOW_BATTLEFIELD_H

#include "Elements.h"
#include <array>
#include <ostream>
#include "Fort.h"
class Player;

class Battlefield
{
protected:
    std::array<Elements*,10> caseElements;
public:
    Battlefield();

    void addUnit(int pos,Elements* e);
    void removeUnit(int pos);
    Elements* getElement(int pos);

    friend std::ostream &operator<<(std::ostream &os, const Battlefield &battlefield);

    void Generer(Player& P1,Player& P2);
    void Printfile();

    };



#endif //AOW_BATTLEFIELD_H
