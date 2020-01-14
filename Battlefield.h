//
// Created by Vathanan on 14/01/2020.
//

#ifndef AOW_BATTLEFIELD_H
#define AOW_BATTLEFIELD_H

#include "Elements.h"

class Battlefield
{
protected:
    Elements* tab[12]{};
    int Turn{};
    int maxTurns{};

public:
    Battlefield(/* args */);
    ~Battlefield();

};



#endif //AOW_BATTLEFIELD_H
