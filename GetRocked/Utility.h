#pragma once
#include <string>
#include <iostream>
namespace std
{
	class Utility
	{
	public:
		// Print a string to the terminal and get the user's input.
		static string PrintAndGetResponse(string statement) {
			string input;
			cout << statement << "\n";
			cin >> input;
			return input;
		}

		static void PrintAndPause(string statement) {
			cout << statement << "\n";
			system("pause");
		}

		// Called to print a divider to terminal.
		static void PrintDivider() {
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		}

		// Called to print error messages to the terminal depending on the errorCode.
		static void PrintError(int errorCode) {
			string errorMessage;

			// using a switch statement here in order to later
			// specify errors and print specific error messages.
			switch (errorCode) {
			case 1:
			default:
				cout << "Something went wrong with the game.\n"
					<< "Exiting application.\n";
			}
		}
	};
}