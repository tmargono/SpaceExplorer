//
//  Enemy.h
//  SpaceExplore
//
//  Created by Ritesh Pendekanti on 2/11/17.
//  Copyright © 2017 Ritesh Pendekanti. All rights reserved.
//

#ifndef monster_h
#define monster_h
#include "player.h"

class stage;
class monster
{
public:
    
    monster(stage *currentStage, int id);
    bool isDead();
    float attack(float damage, Player* player);
    void takeDamage(float damage);
	void givexp(Player *killer);
	int ID();
    
private:
    stage *m_stage;
    float m_health;
    float m_attack;
	float m_xp;
	int m_id;
};

#endif /* monster_h */
