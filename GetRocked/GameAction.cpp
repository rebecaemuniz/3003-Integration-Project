#include "GameAction.h"

/// <summary>
/// Get the available actions for the given game state.
/// </summary>
/// <param name="gameState">The current state of the game.</param>
/// <returns>A string of available actions the user can perform.</returns>
string getAvailableActions(GameState gameState) {
	if (gameState == MainState) {
		return "1 (Move), 2 (Gather), 4 (Save), 5 (Quit), 0 (Help).\n";
	}
	else if (gameState == EncounterState) {
		return "1 (Move), 2 (Gather), 3 (Attack), 4 (Save), 5 (Quit), 0 (Help).\n";
	}
}