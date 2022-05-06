#pragma once
#include <iostream>

#define PLAYER1 '1'
#define PLAYER2 '2'
#define EMPTY_FIELD '0'

class GameState {
public:
	int x, y;
	int k;
	char** board;

	GameState();
	GameState(GameState &g);
	GameState(int x, int y, int k);

	GameState& operator=(GameState &other) {

		if (board != nullptr) {
			for (int i = 0; i < y; i++) {
				if(board[i] != nullptr)
					delete[] board[i];
			}
			delete[] board;
		}

		x = other.x;
		y = other.y;
		k = other.k;

		board = new char* [y];
		for (int i = 0; i < y; i++)
			this->board[i] = new char[x];
		for (int i = 0; i < y; i++)
			for (int j = 0; j < x; j++)
				this->board[i][j] = other.board[i][j];
		return *this;
	}

	~GameState();
	void Print() const;

	int Calculate(char activePlayer)const;
	void Load();
};