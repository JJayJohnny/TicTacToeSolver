#include "GameEngine.h"

void GameEngine::GenerateAllMoves(int n, int m, char activePlayer, GameState &state, MyVector &w) {
	if (state.Calculate(activePlayer) == 0 && state.Calculate(GetOpponent(activePlayer)) == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
			{
				if (state.board[i][j] == EMPTY_FIELD) {
					state.board[i][j] = activePlayer;
					w.PushBack(state);
					state.board[i][j] = EMPTY_FIELD;
				}
			}
		}
	}
}

char GameEngine::GetOpponent(char player) const{
	if (player == PLAYER1)
		return PLAYER2;
	else
		return PLAYER1;
}
