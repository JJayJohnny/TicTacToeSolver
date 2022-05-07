#pragma once
#include <iostream>

#define PLAYER1 '1'
#define PLAYER2 '2'
#define EMPTY_FIELD '0'

class GameState {
private:
	int CheckRows(char activePlayer)const;
	int CheckColumns(char activePlayer)const;
	int CheckDiagonals(char activePlayer)const;

public:
	int x, y;
	int k;
	char** board;

	GameState();
	GameState(GameState &g);
	GameState(int x, int y, int k);
	GameState& operator=(GameState& other);
	~GameState();
	void Print() const;
	int Calculate(char activePlayer, char oponent)const;
	int AdvancedCalculate(char activePlayer);
	void Load();
};