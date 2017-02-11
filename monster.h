//
//  Enemy.h
//  SpaceExplore
//
//  Created by Ritesh Pendekanti on 2/11/17.
//  Copyright © 2017 Ritesh Pendekanti. All rights reserved.
//

#ifndef monster_h
#define monster_h
class stage;
class monster
{
public:
    
    monster(stage *currentStage);
    bool isDead();
    float attack();
    void takeDamage(float damage);
    
private:
    stage *m_stage;
    float m_health;
    float m_attack;
    
};

#endif /* monster_h */
