#pragma once
#include "Utility.h"
#include "GameState.h"
using namespace std;
enum GameAction {
	Help,	//0
	Move,	//1
	Gather,	//2
	Attack,	//3
	Save,	//4
	Quit	//5
};

// Get the available actions for the given game state.
string getAvailableActions(GameState gameState);

// Ask for the user's choice for action type.
static GameAction AskForActionResponse(GameState gameState) {
	string question = "What would you like to do?\n";
	string availableActions = getAvailableActions(gameState);
	int input;
	cout << availableActions << question;
	cin >> input;

	// While the input value is invalid, ask for the user's input.
	while (input < 0 || input > 5 || cin.fail()) {
		string errorMessage = "\nInvalid input.\n";

		if (cin.fail())
		{
			errorMessage = "\nPlease enter an integer.\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		cout << errorMessage << availableActions << question;
		cin >> input;
	}

	return GameAction(input);
}

static void DisplayHelp() {
	cout << "Help Guide:\n"
		<< "Key - Action - Description\n"
		<< " 0  - Help   - Display the action help guide.\n"
		<< " 1  - Move   - Move to another location on the playground.\n"
		<< " 2  - Gather - Gather a snowball from the snow at this location.\n"
		<< " 3  - Attack - Throw a snowball at the enemy.\n"
		<< " 4  - Save   - Save the current game stats to resume play at a later time.\n"
		<< " 5  - Quit   - Quit the game.\n" << endl;

	system("pause");
	system("CLS");
}