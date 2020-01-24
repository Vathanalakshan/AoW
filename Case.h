//
// Created by Vathanan on 24/01/2020.
//

#ifndef AOW_CASE_H
#define AOW_CASE_H

#include <ostream>
#include "Fort.h"
class Unit; // Forward Declaration

class Case {
    protected:
    Unit* u = nullptr;
    bool edgeCase = false;
    Fort* f = nullptr;

    public:
    Case();

    Unit *getE() const;

    void setE(Unit *e);

    bool isEdgeCase() const;

    void setEdgeCase(bool edgeCase);

    Fort *getF() const;

    void setF(Fort *f);

    bool checkFree() const;

    void addUnit(Unit *e);

    friend std::ostream &operator<<(std::ostream &os, const Case &aCase);
};


#endif //AOW_CASE_H

