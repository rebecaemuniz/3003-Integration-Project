#include "Ammo.h"
#include <limits>
using namespace std;

// Ask the user for choice of ammo type.
static int AskForAmmoResponse() {
	string availableActions = "\n1 (Snowball), 2 (Super Snowball!!)\n";
	string question = "What ammo type do you want to use?\n";
	int input;
	cout << availableActions << question;
	cin >> input;

	// While the input value is invalid, ask for the user's input.
	while (input != 1 && input != 2) {
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

	return input;
}