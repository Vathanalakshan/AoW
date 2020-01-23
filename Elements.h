//
// Created by Vathanan on 14/01/2020.
//

#ifndef AOW_ELEMENTS_H
#define AOW_ELEMENTS_H

#include <string>
#include <iostream>
class Elements
{
protected:
    int pos;//Ses position



public:
    int getPos() const;

    Elements(int pos);

    friend std::ostream &operator<<(std::ostream &os, const Elements &elements);
};

#endif //AOW_ELEMENTS_H
