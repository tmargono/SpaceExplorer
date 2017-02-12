#ifndef PLAYER_H
#define PLAYER_H

class stage;
class monster;

class Player {
public:
	Player();
	void increaseXP(float xp);
	float attack();
	void takedamage(float damage);
	bool death();
	void levelup();
	void receivexp(float xp);
private:
	stage *m_stage;
	int m_level;
	float m_xp;
	float m_damage;
	float m_health;
};

#endif
