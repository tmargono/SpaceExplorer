#ifndef STAGE_H
#define STAGE_H

#include "player.h"
#include "monster.h"

class stage {
public:
	stage();
	void addMonster();
	void deleteMonster();
private:
	Player *m_player;
	monster *m_monsters[50];
	int m_numberofmonsters;
};

#endif
