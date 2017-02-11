//
//  monster.cpp
//  SpaceExplore
//
//  Created by Ritesh Pendekanti on 2/11/17.
//  Copyright © 2017 Ritesh Pendekanti. All rights reserved.
//

#include <stdio.h>
#include "monster.h"
#include "player.h"

monster::monster(stage *currentstage)
{
    m_health = 50;
    m_attack = 5;
    m_stage = currentstage;
	m_xp = 100;
}

bool monster::isDead(Player *killer)
{
	if (m_health <= 0) 
	{
		givexp(killer);
		return true;
	}
	return false;
}

float monster::attack()
{
    return 1;
}

void monster::takeDamage(float damage)
{
    m_health -= damage;
}

void monster::givexp(Player *killer)
{
	killer->receivexp(m_xp);
}