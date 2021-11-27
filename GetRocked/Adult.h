#pragma once
#include "Enemy.h"
#include <string>
// Adult is a type of enemy the user can encounter.
// Creating an object of type Adult calls the base class, Enemy's, constructor.
class Adult : public Enemy
{
private:
public:
	// Default constructor.
	Adult() : Enemy(2) {
	}

	// Get a display message depending on the condition of the enemy.
	/*string getEnemyMessage() {
		if (isDefeated()) {
			return "That adult didn't stand a chance!\n";
		}
		else if (currentHealth != maxHealth) {
			return "The adult is not happy after getting smacked by a snowball.\n";
		}
		else {
			return "An adult intervenes and is wanting to teach you a lesson.\n";
		}
	}*/
};

