#include "Game.h"
#include "Ammo.h"
/// <summary>
/// Called to print the current stats to the terminal.
/// </summary>
/// <param name="game">The current game object.</param>
void PrintCurrentStats(Game* game) {
	cout << "Current Stats:"
		<< "\nHealth: " << game->getHealth()
		<< "\nPoints: " << game->getPoints()
		<< "\nSnowballs: " << game->getSnowballs()
		<< "\nSuper Snowballs: " << game->getSuperSnowballs() << "\n" << endl;
}

/// <summary>
/// Called to print the current stats and the locatio description to the terminal.
/// </summary>
/// <param name="game">The current game object.</param>
void PrintCurrentStatsWithLocation(Game* game) {
	PrintCurrentStats(game);
	cout << game->displayLocationMessage() << "\n" << endl;
}

/// <summary>
/// Called to perform the action of gathering snowballs at the current location.
/// </summary>
/// <param name="game">The current game object.</param>
void PerformGather(Game* game) {
	// If the user has already gathered at this location, do nothing.
	if (game->getHasGathered()) {
		cout << "You've already gathered here. Try another action.\n\n";
		return;
	}

	// The player loses health if gathering while the enemy has not yet been defeated.
	if (game->getGameState() == EncounterState) {
		cout << "The enemy hits you with a snowball when you're gathering snow.\n\n";
		game->loseHealth();
	}

	// Random number generation.
	int roll = rand() % 100;

	// 40% chance of getting a super snow ball;
	if (roll <= 40) {
		cout << "With so much snow around you, you managed to create a Super Snowball!\n\n";
		game->gainSuperSnowball();
		// Track total super snowballs collected.
		game->incrementSuperSnowballsCollected();
	}
	else {
		cout << "You were able to gather a snowball from your location.\n\n";
		game->gainSnowball();
		// Track total snowballs collected.
		game->incrementSnowballsCollected();
	}


	// Prevent the player from gathering at this location again.
	game->setHasGathered(true);
}

/// <summary>
/// Called to perform the action of moving to a new location.
/// </summary>
/// <param name="game">The current game object.</param>
void PerformMove(Game* game) {
	// The player loses health if moving while the enemy has not yet been defeated.
	if (game->getGameState() == EncounterState) {
		cout << "The enemy hits you with a snowball as you scurry away.\n" << endl;
		game->loseHealth();
	}
	else {
		cout << "Moving to a new location...\n" << endl;
	}
	// Reset has game variables.
	game->setHasGeneratedEnemy(false);
	game->setHasGathered(false);

	// Determine if enemy appears.
	int roll = rand() % 100;
	// 65 percent chance of running into an enemy;
	if (roll <= 65 || game->getShouldGenerateAdult()) {
		game->setGameState(EncounterState);
		game->setHasGeneratedEnemy(false);
	}
	else {
		game->setGameState(MainState);
	}
}

/// <summary>
/// Called to perform the action of throwing a snowball at a playground enemy.
/// </summary>
/// <param name="game">The current game object.</param>
void PerformAttack(Game* game) {
	// Check if user can use attack action.
	if (game->getGameState() != EncounterState) {
		cout << "You are trying to perform the attack action"
			<< " but there's no one there to attack.\n" << endl;
		return;
	}

	Enemy* enemy = game->getEnemy();

	// Ask user which snowball to use.
	int selectedAmmo = Ammo::AskForAmmoResponse();
	Ammo* ammoSelected;

	// The following logic flow is an example of requirement:
	//		LO3. Correctly reason about control flow in a program using dynamic dispatch.
	// Depending on the user's input choice, 'ammo' is either a 'Snowball' or a 
	//		'SuperSnowball'. Then when Enemy::reduceHealth is called, 
	//		dynamic dispatch will determine which overloaded method to call based on the ammo type.
	if (selectedAmmo == 1) {
		// Check if user has snowballs to throw.
		if (game->getSnowballs() == 0) {
			cout << "Oops! You don't have any Snowballs to throw.\n";
			return;
		}

		// Create appropriate ammo type.
		Snowball* ammo = new Snowball();
		game->useSnowball();
		ammoSelected = ammo;

		// Apply snowball attack.
		enemy->reduceHealth(ammo);
	}
	else {
		// Check if user has snowballs to throw.
		if (game->getSuperSnowballs() == 0) {
			cout << "Oops! You don't have any Super Snowballs to throw.\n";
			return;
		}

		// Create appropriate ammo type.
		SuperSnowball* ammo = new SuperSnowball();
		game->useSuperSnowball();
		ammoSelected = ammo;

		// Apply snowball attack.
		enemy->reduceHealth(ammo);
	}

	system("CLS");

	// Adjust game statistics.
	if (enemy->isDefeated()) {
		cout << "Nice shot! Your enemy got rocked and ran away crying!\n";

		// Using dynamic dispatching to determine how many points to gain.
		game->gainPoints(enemy->getPointsWorth());

		// Track total number of enemies defeated.
		game->incrementEnemiesDefeated();

		// Set the game state back to main state.
		game->setGameState(MainState);
	}
	else { // The enemy has not been defeated.
		game->loseHealth();
	}

	// If the user selects to use a Super Snowball against a kid,
	// an adult will step in at the next location.
	if (enemy->getMaxHealth() == 1
		&& ammoSelected->getDamage() == 2) {
		game->setShouldGenerateAdult(true);
	}

}

/// <summary>
/// Generate either an Adult or a Kid enemy.
/// </summary>
/// <param name="game">The current game object.</param>
void GenerateEncounter(Game* game) {
	int roll = rand() % 100;
	// 33 percent chance the encounter is an adult.
	// Guaranteed to be an adult if flag is set.
	if (game->getShouldGenerateAdult() || roll < 33) {
		// Create a adult encounter.
		game->assignEnemy(new Adult());
		// Reset flag.
		game->setShouldGenerateAdult(false);
	}
	else {
		// Create a kid encounter.
		game->assignEnemy(new Kid());
	}

	// Set flag for enemy already generated at this location.
	game->setHasGeneratedEnemy(true);
}

/// <summary>
/// Print the ending statistics to the terminal.
/// </summary>
/// <param name="game">The current game object.</param>
void DisplayClosingStats(Game* game) {
	cout << "Closing Stats:" 
		<< "\nPoints Earned: " << game->getPoints()
		<< "\nEnemies Defeated: " << game->getEnemiesDefated()
		<< "\nTotal Snowballs Collected: " << game->getSnowballsCollected()
		<< "\nTotal Super Snowballs Collected: " << game->getSuperSnowballsCollected()
		<< "\n" << endl;

}

/// <summary>
/// Called to initialize the game loop to start playing the game.
/// </summary>
/// <param name="game">The current game objecgt.</param>
/// <returns>An integer representing if the game completed cleanly.</returns>
int StartGame(Game* game) {
	// Continue to play until the user ends the game.
	while (game->getGameState() != EndState
			&& !game->isDefeated()) {

		// If in EncounterState, generate an enemy.
		if (game->getGameState() == EncounterState
			&& !game->getHasGeneratedEnemy()) {
			GenerateEncounter(game);
		}

		// Always print the user's statistics at the top of the console.
		PrintCurrentStatsWithLocation(game);

		// Ask the user to perform an action.
		GameAction action = AskForActionResponse(game->getGameState());
		if (action != Attack) {
			system("CLS");
		}

		// Perform the action depending on user's choice.
		switch (action) {
		case Help:
			DisplayHelp();
			break;
		case Move:
			PerformMove(game);
			break;
		case Gather:
			PerformGather(game);
			break;
		case Attack:
			PerformAttack(game);
			break;
		case Save:
			cout << "Save functionality has not yet been implemented.\n\n";
			break;
		case Quit:
			game->setGameState(EndState);
			break;
		default:
			cout << "Invalid action detected!\n";
			return -1;
		}
	}

	// Display closing stats before exiting the game.
	DisplayClosingStats(game);

	return 0;
}