//
//  monster.cpp
//  SpaceExplore
//
//  Created by Ritesh Pendekanti on 2/11/17.
//  Copyright © 2017 Ritesh Pendekanti. All rights reserved.
//

#include <stdio.h>
#include "monster.h"

monster::monster(stage *currentstage)
{
    m_health = 50;
    m_attack = 5;
    m_stage = currentstage;
}

bool monster::isDead()
{
    return (m_health > 0);
}

float monster::attack()
{
    return 1;
}

void monster::takeDamage(float damage)
{
    m_health -= damage;
}
