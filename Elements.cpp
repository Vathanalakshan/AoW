//
// Created by Vathanan on 14/01/2020.
//

#include "Elements.h"

int  Elements::getPos() const{
    return m_pos;
};
bool Elements::getTeam() const{
    return m_team;
};

int Elements::getCurrentHealth() const{
    return m_currentHealth;
}

Elements::~Elements() {};