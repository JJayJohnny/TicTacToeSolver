#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "GameState.h"
#include "MyVector.h"
#include "GameEngine.h"
#include <string.h>

class MyVector;
class GameState;

using namespace std;

int main() {
	GameEngine engine;
	char command[40];

	while (cin >> command) {
		if (strcmp(command, "GEN_ALL_POS_MOV") == 0) {
			int n, m, k;
			char activePlayer;
			cin >> n >> m >> k>>activePlayer;
			GameState gs(m, n, k);
			gs.Load();
			MyVector w;
			engine.GenerateAllMoves(n, m, activePlayer, gs, w);
			cout << w.GetSize()<<endl;
			for (int i = 0; i < w.GetSize(); i++)
				w[i].Print();
		}
	}
	_CrtDumpMemoryLeaks();
	return 0;
}