#include "monster.h"
#include "player.h"
#include "stage.h"

using namespace std;

stage::stage() {
	m_numberofmonsters = 0;
}
void stage::addMonster() {
	if (m_numberofmonsters < 50) {
		m_monsters[m_numberofmonsters] = new monster(this,m_numberofmonsters);
		m_numberofmonsters++;
	}
}
void stage::deleteMonster(int id) {
	if (m_numberofmonsters > 0) {
		delete m_monsters[id];
		m_numberofmonsters--;
	}
}
void stage::xpExchange(Player *killer, monster *killed) {
	killed->givexp(killer);
}
void stage::playerAttack(Player *attacker, monster *attacked) {
	attacked->takeDamage(attacker->attack());
	if (attacked->isDead()) {
		xpExchange(attacker, attacked);
		deleteMonster(attacked->ID());	//temporary 5 for monster's id
	}
}