#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "MyVector.h"
#include <iostream>

class GameEngine {
public:
	void GenerateAllMoves(int n, int m, char activePlayer, GameState &state, MyVector &w);
	void GEN_ALL_POS_MOV(bool cutOnGameOver);
	void SOLVE_GAME_STATE();
	int MinMax(GameState& gs, char activePlayer, char firstPlayer);
	char GetOpponent(char player) const;
};