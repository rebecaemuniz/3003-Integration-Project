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

// The object oriented approach is about encapsulating data and behavior into objects. OOP
// uses classes as blueprints for an object. This object will have their own methods and be 
// able to interact with other objects to perform actions in an application. OOP follows a bottom
// up apprach and is able to hide data so it is more secure.   
// The procedural/functional  approach passes data from function to function to get a result.
// They follow a top down approach, overloading is not possible, and data is less secure because they
// have no access specifiers like private, public, and protected.

// Game class that contains the flow and variables of the game.
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
	// Constructor for loading a saved game.
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

	// Default constructor for starting a new game.
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

	// Getter method to get the current Health of the player.
	string getHealth() {
		return std::to_string(currentHealth);
	}

	// Decrement the player's current health.
	void loseHealth() {
		currentHealth--;
	}

	// Getter method to get the current Points accumulated.
	string getPoints() {
		return std::to_string(currentPoints);
	}

	// Called to increate the points in the game after defeating an enemy.
	void gainPoints(int amount) {
		currentPoints += amount;
	}

	// Getter method to get the current count of Snowballs.
	int getSnowballs() {
		return currentSnowballs;
	}

	// Increment the amount of current snowballs.
	void gainSnowball() {
		currentSnowballs++;
	}

	// Decrement the amount of snowballs.
	void useSnowball() {
		currentSnowballs--;
	}

	// Getter method to get the current count of Super Snowballs.
	int getSuperSnowballs() {
		return currentSuperSnowballs;
	}

	// Increment the amount of super current snowballs.
	void gainSuperSnowball() {
		currentSuperSnowballs++;
	}

	// Decrement the amount of super snowballs.
	void useSuperSnowball() {
		currentSuperSnowballs--;
	}

	// Getter method to get the current game state of the game.
	GameState getGameState() {
		return gameState;
	}

	// Setter method to set the state of the game.
	void setGameState(GameState state) {
		gameState = state;
	}

	// Getter method to get if the user has already gathered at the current location.
	bool getHasGathered() {
		return hasGatheredAtLocation;
	}

	// Setter method to set if the user has already gathered at the current location.
	void setHasGathered(bool hasGathered) {
		hasGatheredAtLocation = hasGathered;
	}

	// Getter method to get the current enemy.
	Enemy* getEnemy() {
		return enemy;
	}

	// Get if an adult should be generated.
	bool getShouldGenerateAdult() {
		return shouldGenerateAdult;
	}

	// Set if the next encounter should be an adult.
	void setShouldGenerateAdult(bool generateAdult) {
		shouldGenerateAdult = generateAdult;
	}
	
	// Method called to assign the enemy of type Kid.
	void assignEnemy(Kid* kid) {
		enemy = kid;
	}

	// Method called to assign the enemy of type Adult.
	void assignEnemy(Adult* adult) {
		enemy = adult;
	}

	// Getter method for if an enemy has already been generated at the current location.
	bool getHasGeneratedEnemy() {
		return hasGeneratedEnemy;
	}

	// Setter method to set the enemy encounter.
	void setHasGeneratedEnemy(bool generatedEnemy) {
		hasGeneratedEnemy = generatedEnemy;
	}

	// Called to get the description of the new location.
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

	// Getter method to get the total number of snowballs collected.
	int getSnowballsCollected() {
		return snowballsCollected;
	}

	// Method to increment the number of snowballs collected.
	void incrementSnowballsCollected() {
		snowballsCollected++;
	}

	// Getter method to get the total number of super snowballs collected.
	int getSuperSnowballsCollected() {
		return superSnowballsCollected;
	}

	// Method to increment the number of super snowballs collected.
	void incrementSuperSnowballsCollected() {
		superSnowballsCollected++;
	}

	// Getter method to get the total number of enemies defeated.
	int getEnemiesDefated() {
		return enemiesDefated;
	}

	// Called to get whether the user is defeated.
	bool isDefeated() {
		return currentHealth <= 0;
	}

	// Method to increment the number of enemies defeated.
	void incrementEnemiesDefeated() {
		enemiesDefated++;
	}
};

int StartGame(Game* game);