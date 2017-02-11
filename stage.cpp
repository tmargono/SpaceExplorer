#include "monster.h"
#include "player.h"
#include "stage.h"

using namespace std;

stage::stage() {
	m_numberofmonsters = 0;
}
void stage::addMonster() {
	m_monsters[m_numberofmonsters] = new monster(this);
	m_numberofmonsters++;
}
void stage::deleteMonster() {
	delete m_monsters[m_numberofmonsters];
	m_numberofmonsters--;
}