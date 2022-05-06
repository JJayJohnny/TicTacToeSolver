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

void GameEngine::GEN_ALL_POS_MOV() {
	int n, m, k;
	char activePlayer;
	//std::cin >> n >> m >> k >> activePlayer;
	scanf(" %d %d %d %c", &n, &m, &k, &activePlayer);
	GameState gs(m, n, k);
	gs.Load();
	MyVector w;
	GenerateAllMoves(n, m, activePlayer, gs, w);
	//std::cout << w.GetSize() << std::endl;
	printf("%d\n", w.GetSize());
	for (int i = 0; i < w.GetSize(); i++)
		w[i].Print();
}

char GameEngine::GetOpponent(char player) const{
	if (player == PLAYER1)
		return PLAYER2;
	else
		return PLAYER1;
}
