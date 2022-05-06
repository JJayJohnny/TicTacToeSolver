#include "GameEngine.h"

void GameEngine::GenerateAllMoves(int n, int m, char activePlayer, GameState &state, MyVector &w) {
	if (state.Calculate(activePlayer, GetOpponent(activePlayer))==0) {
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

void GameEngine::GEN_ALL_POS_MOV(bool cutOnGameOver) {
	int n, m, k;
	char activePlayer;
	//std::cin >> n >> m >> k >> activePlayer;
	scanf(" %d %d %d %c", &n, &m, &k, &activePlayer);
	GameState gs(m, n, k);
	gs.Load();
	MyVector w;
	GenerateAllMoves(n, m, activePlayer, gs, w);
	if (cutOnGameOver) {
		for (int i = 0; i < w.GetSize(); i++) {
			if (w[i].Calculate(activePlayer, GetOpponent(activePlayer)) == 1) {
				printf("1\n");
				w[i].Print();
				return;
			}
		}
	}
	//std::cout << w.GetSize() << std::endl;
	printf("%d\n", w.GetSize());
	for (int i = 0; i < w.GetSize(); i++)
		w[i].Print();
}

void GameEngine::SOLVE_GAME_STATE() {
	int n, m, k;
	char activePlayer;
	scanf(" %d %d %d %c", &n, &m, &k, &activePlayer);
	GameState gs(m, n, k);
	gs.Load();
	int result = MinMax(gs, activePlayer, activePlayer);

	if ((activePlayer == PLAYER1 && result == 1) || (activePlayer == PLAYER2 && result == -1))
		printf("FIRST_PLAYER_WINS\n");
	else if ((activePlayer == PLAYER1 && result == -1) || (activePlayer == PLAYER2 && result == 1))
		printf("SECOND_PLAYER_WINS\n");
	else
		printf("BOTH_PLAYERS_TIE\n");
}

int GameEngine::MinMax(GameState& gs, char activePlayer, char firstPlayer) {
	int score = gs.Calculate(activePlayer, GetOpponent(activePlayer));
	MyVector availableMoves;
	GenerateAllMoves(gs.y, gs.x, activePlayer, gs, availableMoves);
	if (availableMoves.GetSize() == 0) {
		if (activePlayer == firstPlayer)
			return score;
		else
			return (-1) * score;
	}

	if (activePlayer == firstPlayer) {
		int best = MinMax(availableMoves[0], GetOpponent(activePlayer), firstPlayer);
		for (int i = 1; i < availableMoves.GetSize(); i++) {
			int move = MinMax(availableMoves[i], GetOpponent(activePlayer), firstPlayer);
			if (move > best)
				best = move;
			if (move == 1)
				return move;
		}
		return best;
	}
	else {
		int best = MinMax(availableMoves[0], GetOpponent(activePlayer), firstPlayer);
		for (int i = 1; i < availableMoves.GetSize(); i++) {
			int move = MinMax(availableMoves[i], GetOpponent(activePlayer), firstPlayer);
			if (move < best)
				best = move;
			if (move == -1)
				return move;
		}
		return best;
	}
}

char GameEngine::GetOpponent(char player) const{
	if (player == PLAYER1)
		return PLAYER2;
	else
		return PLAYER1;
}
