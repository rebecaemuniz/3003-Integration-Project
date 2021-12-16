// Name: Rebeca Muniz
// Class: COP 3003
// Professor: Scott Vanselow
// Description: Get-Rocked is a text-based game played solely in the console window. The user will encounter enemies 
// and defeat them with rocks collected in the game. The goal is to get the most points in the game before you run
// out of health. 
//GetRocked.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Utility.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Game.h"
using namespace std;

/// <summary>
/// This is the main function that the application runs.
/// </summary>
/// <returns>An integer representing if the game completed cleanly.</returns>
int main()
{
    std::cout << "Welcome to Get Rocked!\n"
        << "It is snowing and you are a kid on the playground.\n"
        << "As you move around the infinitely-large playground,\n"
        << "you can pick up snowballs and throw them at other kids you encounter.\n\n"
        << "Be careful though, they too will throw snow balls at you!\n"
        << "Play too rough and an adult will intervene.\n"
        << "But who cares, throw snowballs at them too! They're worth double points!\n";

    Utility::PrintDivider();
        
    
    // Declare local variables.
    Game* game;
    string userInput;

    // Ask if starting a new game or resuming a saved game.
    userInput = Utility::PrintAndGetResponse("Enter (1) Start a new game. (2) Load a saved game.\n");

    // Ask for input again, if the user did not type 1 or 2
    while (userInput.compare("1") != 0 && userInput.compare("2") != 0) {
        system("CLS");
        userInput = Utility::PrintAndGetResponse("Invalid input. Enter (1) Start a new game. (2) Load a saved game.\n");
    }

    system("CLS");

    // If loading a saved game
    if (userInput.compare("2") == 0) {
        // TODO: attempt to read saved file and parse into variables

        // TODO: create new game
        cout << "Loading saved game is not implemented yet.\n"
            << "Loading dummy data...." << endl;
        game = new Game(1, 5, 5, 5, 1, true, false, true, 100, 200, 300);
    }
    // If starting new game.
    else {
        game = new Game();
    }
    
    // Start game.
    int gameExitCode = StartGame(game);

    // If the game exited with an exit code other than 0, something went wrong.
    if (gameExitCode != 0) {
        // Using a switch statement here so we can specify an error message in the future.
        switch (gameExitCode) {
        case -1:
        default:
            cout << "Something went wrong during runtime of the game. (T . T)!" << endl;
        }

        return gameExitCode;
    }

    // Display game exit message.
    Utility::PrintDivider();
    cout << "Thank you for playing Get Rocked! Hope you play again soon!" << endl;
    Utility::PrintAndPause("Type anything to exit the game.");
    
    // Exit the application
    return 0;
}