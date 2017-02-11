#ifndef STAGE_H
#define STAGE_H

#include "player.h"
#include "monster.h"

class stage {
public:
	stage();
	void addMonster();
	void deleteMonster(int id);
	void playerAttack(Player *attacker, monster *attacked);
	void xpExchange(Player *killer, monster *killed);
private:
	Player *m_player;
	monster *m_monsters[50];
	int m_numberofmonsters;
};

#endif
