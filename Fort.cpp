//
// Created by Vathanan on 14/01/2020.
//
#include "Fort.h"

Fort::Fort(bool t){
    m_currentHealth=200;
    m_team=t;
    if (t)
        m_pos=0;
    else
        m_pos=11;

}

