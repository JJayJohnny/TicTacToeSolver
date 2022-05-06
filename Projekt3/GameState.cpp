#include "GameState.h"

GameState::GameState() : x(0), y(0), k(0), board(nullptr) {
}

GameState::GameState(GameState &g) : x(g.x), y(g.y), k(g.k){

	this->board = new char* [y];
	for (int i = 0; i < y; i++)
		this->board[i] = new char[x];
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			this->board[i][j] = g.board[i][j];
}

GameState::GameState(int x, int y, int k) : x(x), y(y), k(k) {
	board = new char* [y];
	for (int i = 0; i < y; i++)
		board[i] = new char[x];

	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			board[i][j] = EMPTY_FIELD;
}

GameState::~GameState() {
	if (board != nullptr) {
		for (int i = 0; i < y; i++)
			delete[] board[i];
		delete[] board;
	}
}

void GameState::Print() const{
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++)
			std::cout << board[i][j] << " ";
		std::cout << std::endl;
	}
}

int GameState::Calculate(char activePlayer) const{
	//check lines
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			int length = 0;
			while (board[i][j] == activePlayer) {
				length++;
				if (length == k)
					return 1;
				if (j >= (x - 1))
					break;
				j++;
			}
		}
	}
	//check columns
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			int length = 0;
			while (board[j][i] == activePlayer) {
				length++;
				if (length == k)
					return 1;
				if (j >= (y - 1))
					break;
				j++;
			}
		}
	}
	//check angles
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			int i2 = i;
			int j2 = j;
			int length = 0;
			while (board[i2][j2] == activePlayer) {
				length++;
				if (length == k)
					return 1;
				if (j2 >= (x - 1))
					break;
				if (i2 < 1)
					break;
				i2--;
				j2++;
			}
		}
	}
	for (int i = y - 1; i >= 0; i--) {
		for (int j = 0; j < x; j++) {
			int i2 = i;
			int j2 = j;
			int length = 0;
			while (board[i2][j2] == activePlayer) {
				length++;
				if (length == k)
					return 1;
				if (j2 >= (x - 1))
					break;
				if (i2 >= (y - 1))
					break;
				i2++;
				j2++;
			}
		}
	}
	return 0;
}

void GameState::Load() {
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			std::cin >> board[i][j];
}
