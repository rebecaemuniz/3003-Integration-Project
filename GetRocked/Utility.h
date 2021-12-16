#pragma once
#include <string>
#include <iostream>
namespace std
{
	/// <summary>
	/// Utility class containing reusable static methods.
	/// </summary>
	class Utility
	{
	public:
		/// <summary>
		/// Print a string to the terminal and get the user's input.
		/// </summary>
		/// <param name="statement">The statement to print.</param>
		/// <returns>The input from the user.</returns>
		static string PrintAndGetResponse(string statement) {
			string input;
			cout << statement << "\n";
			cin >> input;
			return input;
		}

		/// <summary>
		/// Print a string to the terminal and wait for the user to press a key.
		/// </summary>
		/// <param name="statement"></param>
		static void PrintAndPause(string statement) {
			cout << statement << "\n";
			system("pause");
		}

		/// <summary>
		/// Called to print a divider to terminal.
		/// </summary>
		static void PrintDivider() {
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		}

		/// <summary>
		/// Called to print error messages to the terminal depending on the errorCode.
		/// </summary>
		/// <param name="errorCode">Error code to print to the screen.</param>
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