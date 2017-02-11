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
	bool isPosInBound(int r, int c) const;
	int getCellStatus(int r, int c) const;
	
private:
	int m_rows = 100;
	int m_cols = 100;
	int m_grid[100][100];
	Player *m_player;
	monster *m_monsters[50];
	int m_numberofmonsters;

	
	/*	Arena(int nRows, int nCols);
    ~Arena();

      // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     ratCount() const;
    int     getCellStatus(int r, int c) const;
    int     numberOfRatsAt(int r, int c) const;
    void    display(string msg) const;

      // Mutators
    void setCellStatus(int r, int c, int status);
    bool addRat(int r, int c);
    bool addPlayer(int r, int c);
    void moveRats();

  private:
    int     m_grid[MAXROWS][MAXCOLS];
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Rat*    m_rats[MAXRATS];
    int     m_nRats;
    int     m_turns;

      // Helper functions
    void checkPos(int r, int c) const;
    bool isPosInBounds(int r, int c) const;*/
};

#endif
