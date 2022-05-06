#pragma once

#include "MyVector.h"

class GameEngine {
public:
	void GenerateAllMoves(int n, int m, char activePlayer, GameState &state, MyVector &w);
	char GetOpponent(char player) const;
};