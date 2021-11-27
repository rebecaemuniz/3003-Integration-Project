#include "GameAction.h"
// Get the available actions for the given game state.
string getAvailableActions(GameState gameState) {
	if (gameState == MainState) {
		return "1 (Move), 2 (Gather), 4 (Save), 5 (Quit), 0 (Help).\n";
	}
	else if (gameState == EncounterState) {
		return "1 (Move), 2 (Gather), 3 (Attack), 4 (Save), 5 (Quit), 0 (Help).\n";
	}
}