#include "player.h"

using namespace std;

Player::Player(stage *currentstage) {
	m_health = 100;
	m_damage = 10;
	m_xp = 0;
	m_level = 0;
	m_stage = currentstage;
}
float Player::attack() {
	return 1;
}
void Player::increaseXP(float xp) {
	m_xp += xp;
}
void Player::takedamage(float damage) {
	m_health -= damage;
}
bool Player::death() {
	if (m_health <= 0)
		return true;
	return false;
}