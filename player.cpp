#include "player.h"

using namespace std;

Player::Player() {
	m_health = 100;
	m_damage = 10;
	m_xp = 0;
	m_level = 1;
}
float Player::attack() {
	float damage = m_level * 20;	//TEMPORARY 20
	return damage;
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
void Player::levelup() {
	if (m_xp >= 2000*(1 + 0.20*m_level))	//TEMPORARY 3000
		m_level++;
}
void Player::receivexp(float xp) {
	m_xp += xp;
}