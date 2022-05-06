#define _CRT_SECURE_NO_WARNINGS

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "GameState.h"
#include "MyVector.h"
#include "GameEngine.h"
#include <string.h>

int main() {
	GameEngine engine;
	char command[40];

	while (true) {
		scanf("%s", &command);
		if (feof(stdin) != 0)
			break;
		if (strcmp(command, "GEN_ALL_POS_MOV") == 0)
			engine.GEN_ALL_POS_MOV(false);
		if (strcmp(command, "GEN_ALL_POS_MOV_CUT_IF_GAME_OVER") == 0)
			engine.GEN_ALL_POS_MOV(true);
		if (strcmp(command, "SOLVE_GAME_STATE") == 0)
			engine.SOLVE_GAME_STATE();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}