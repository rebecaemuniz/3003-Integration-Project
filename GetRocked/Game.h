#pragma once
#include <string>
#include <iostream>
#include "GameState.h"
#include "GameAction.h"
#include "Enemy.h"
#include "Kid.h"
#include "Adult.h"
#include "Ammo.h"
#include "Snowball.h"
#include "SuperSnowball.h"
#include "Utility.h"
using namespace std;

// This following comment is for requirement: 
//		LO4. Include a comment in which you compare and contrast the procedural/functional 
//		approach and the object-oriented approach.
/* The object oriented approach is about encapsulating dataand behavior into objects.OOP
 * uses classes as blueprints for an object. This object will have their own methods and be 
 * able to interact with other objects to perform actions in an application. OOP follows a bottom
 * up apprach and is able to hide data so it is more secure.
 * The procedural/functional  approach passes data from function to function to get a result.
 * They follow a top down approach, overloading is not possible, and data is less secure because they
 * have no access specifiers like private, public, and protected.
 */

/// Game class that contains the flow and variables of the game.
class Game
{
private:
	int currentHealth;
	int currentPoints;
	int currentSnowballs;
	int currentSuperSnowballs;
	GameState gameState;
	bool hasGatheredAtLocation;
	Enemy* enemy;
	bool shouldGenerateAdult;
	bool hasGeneratedEnemy;
	int snowballsCollected;
	int superSnowballsCollected;
	int enemiesDefated;

public:
	// This constructor is an example of requirement: LO1b.Overload a constructor
	/// <summary>
	/// Constructor for loading a saved game.
	/// </summary>
	/// <param name="health">The player's health.</param>
	/// <param name="points">The player's accumulated points.</param>
	/// <param name="snowballs">The player's accumulated number of snowballs.</param>
	/// <param name="superSnowballs">The player's accumulated number of super snowballs.</param>
	/// <param name="state">The current state of the game.</param>
	/// <param name="hasGathered">Whether the player has gathered at the current location.</param>
	/// <param name="generateAdult">Whether to generate an adult at the next location.</param>
	/// <param name="generateEnemy">Whether an enemy has been generated at the current location.</param>
	/// <param name="snowballsObtained">Total number of snowballs obtained.</param>
	/// <param name="superSnowballsObtained">Total number of super snowballs obtained.</param>
	/// <param name="enemiesRocked">Total number of enemies defeated.</param>
	Game(int health, int points, int snowballs, int superSnowballs, 
		int state, bool hasGathered, bool generateAdult, bool generateEnemy, 
		int snowballsObtained, int superSnowballsObtained, int enemiesRocked) {
		currentHealth = health;
		currentPoints = points;
		currentSnowballs = snowballs;
		currentSuperSnowballs = superSnowballs;
		gameState = GameState(state);
		hasGatheredAtLocation = hasGathered;
		shouldGenerateAdult = generateAdult;
		hasGeneratedEnemy = generateEnemy;
		snowballsCollected = snowballsObtained;
		superSnowballsCollected = superSnowballsObtained;
		enemiesDefated = enemiesRocked;

		// Display resuming game message.
		cout << "Loading saved game..\n\n";
		Utility::PrintDivider();
	}

	/// <summary>
	/// Default constructor for starting a new game.
	/// </summary>
	Game() {
		// The following is an example of the requirement: LO1c. Utilize an initialization list
		currentHealth = 3;
		currentPoints = 0;
		currentSnowballs = 1;
		currentSuperSnowballs = 0;
		gameState = GameState(1);
		hasGatheredAtLocation = false;
		shouldGenerateAdult = false;
		hasGeneratedEnemy = false;
		snowballsCollected = 0;
		superSnowballsCollected = 0;
		enemiesDefated = 0;

		// Display new game message.
		cout << "Starting new game...\n";
		Utility::PrintDivider();
	}

	/// <summary>
	/// Getter method to get the current Health of the player.
	/// </summary>
	/// <returns></returns>
	string getHealth() {
		return std::to_string(currentHealth);
	}

	/// <summary>
	/// Decrement the player's current health.
	/// </summary>
	void loseHealth() {
		currentHealth--;
	}

	/// <summary>
	/// Getter method to get the current Points accumulated.
	/// </summary>
	/// <returns></returns>
	string getPoints() {
		return std::to_string(currentPoints);
	}

	/// <summary>
	/// Called to increate the points in the game after defeating an enemy.
	/// </summary>
	/// <param name="amount"></param>
	void gainPoints(int amount) {
		currentPoints += amount;
	}

	/// <summary>
	/// Getter method to get the current count of Snowballs.
	/// </summary>
	/// <returns></returns>
	int getSnowballs() {
		return currentSnowballs;
	}

	/// <summary>
	/// Increment the amount of current snowballs.
	/// </summary>
	void gainSnowball() {
		currentSnowballs++;
	}

	/// <summary>
	/// Decrement the amount of snowballs.
	/// </summary>
	void useSnowball() {
		currentSnowballs--;
	}

	/// <summary>
	/// Getter method to get the current count of Super Snowballs.
	/// </summary>
	/// <returns></returns>
	int getSuperSnowballs() {
		return currentSuperSnowballs;
	}

	/// <summary>
	/// Increment the amount of super current snowballs.
	/// </summary>
	void gainSuperSnowball() {
		currentSuperSnowballs++;
	}

	/// <summary>
	/// Decrement the amount of super snowballs.
	/// </summary>
	void useSuperSnowball() {
		currentSuperSnowballs--;
	}

	/// <summary>
	/// Getter method to get the current game state of the game.
	/// </summary>
	/// <returns>The current state of the game.</returns>
	GameState getGameState() {
		return gameState;
	}

	/// <summary>
	/// Setter method to set the state of the game.
	/// </summary>
	/// <param name="state">The current state of the game.</param>
	void setGameState(GameState state) {
		gameState = state;
	}

	/// <summary>
	/// Getter method to get if the user has already gathered at the current location.
	/// </summary>
	/// <returns>Whether or not the user has gathered at the current location.</returns>
	bool getHasGathered() {
		return hasGatheredAtLocation;
	}

	/// <summary>
	/// Setter method to set if the user has already gathered at the current location.
	/// </summary>
	/// <param name="hasGathered">Sets if the user has gathered at the current location.</param>
	void setHasGathered(bool hasGathered) {
		hasGatheredAtLocation = hasGathered;
	}

	/// <summary>
	/// Getter method to get the current enemy.
	/// </summary>
	/// <returns>The enemy.</returns>
	Enemy* getEnemy() {
		return enemy;
	}

	/// <summary>
	/// Get if an adult should be generated.
	/// </summary>
	/// <returns>Whether or not an adult should be generated.</returns>
	bool getShouldGenerateAdult() {
		return shouldGenerateAdult;
	}

	/// <summary>
	/// Set if the next encounter should be an adult.
	/// </summary>
	/// <param name="generateAdult">Set whether or not an adult should be generated next.</param>
	void setShouldGenerateAdult(bool generateAdult) {
		shouldGenerateAdult = generateAdult;
	}
	
	/// <summary>
	/// Method called to assign the enemy of type Kid.
	/// </summary>
	/// <param name="kid">The enemy to assign.</param>
	void assignEnemy(Kid* kid) {
		enemy = kid;
	}

	/// <summary>
	/// Method called to assign the enemy of type Adult.
	/// </summary>
	/// <param name="adult">The enemy to assign.</param>
	void assignEnemy(Adult* adult) {
		enemy = adult;
	}

	/// <summary>
	/// Getter method for if an enemy has already been generated at the current location.
	/// </summary>
	/// <returns></returns>
	bool getHasGeneratedEnemy() {
		return hasGeneratedEnemy;
	}

	/// <summary>
	/// Setter method to set the enemy encounter.
	/// </summary>
	/// <param name="generatedEnemy">Sets whether or not an enemy has been generated.</param>
	void setHasGeneratedEnemy(bool generatedEnemy) {
		hasGeneratedEnemy = generatedEnemy;
	}

	/// <summary>
	/// Called to get the description of the new location.
	/// </summary>
	/// <returns>A string describing the location the user arrived at.</returns>
	string displayLocationMessage() {
		if (gameState == MainState) {
			return "This location is calm and there are no enemies in sight.";
		}
		// else the game is in the EncounterState
		else {
			//return enemy->getEnemyMessage();
			if (enemy->getMaxHealth() == 1) {
				return "A playground enemy is staring you in the face, ready for combat.";
			}
			else {
				if (enemy->isFullHealth()) {
					return "An angry parent has approached you on the playground.";
				}
				else {
					return "The angry adult is even more angry after getting slapped by a snowball.";
				}
			}
		}
	}

	/// <summary>
	/// Getter method to get the total number of snowballs collected.
	/// </summary>
	/// <returns></returns>
	int getSnowballsCollected() {
		return snowballsCollected;
	}

	/// <summary>
	/// Method to increment the number of snowballs collected.
	/// </summary>
	void incrementSnowballsCollected() {
		snowballsCollected++;
	}

	/// <summary>
	/// Getter method to get the total number of super snowballs collected.
	/// </summary>
	/// <returns></returns>
	int getSuperSnowballsCollected() {
		return superSnowballsCollected;
	}

	/// <summary>
	/// Method to increment the number of super snowballs collected.
	/// </summary>
	void incrementSuperSnowballsCollected() {
		superSnowballsCollected++;
	}

	/// <summary>
	/// Getter method to get the total number of enemies defeated.
	/// </summary>
	/// <returns></returns>
	int getEnemiesDefated() {
		return enemiesDefated;
	}

	/// <summary>
	/// Called to get whether the user is defeated.
	/// </summary>
	/// <returns></returns>
	bool isDefeated() {
		return currentHealth <= 0;
	}

	/// <summary>
	/// Method to increment the number of enemies defeated.
	/// </summary>
	void incrementEnemiesDefeated() {
		enemiesDefated++;
	}
};

int StartGame(Game* game);