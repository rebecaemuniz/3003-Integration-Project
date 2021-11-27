#pragma once
#include "Enemy.h"
#include <string>
// Kid is a type of enemy the user can encounter.
// Creating an object of type Kid calls the base class, Enemy's, constructor.
class Kid : public Enemy
{
public:
	// Default constructor.
	Kid() : Enemy(1) {
	}

	// Get a display message depending on the condition of the enemy.
	/*string getEnemyMessage() {
		if (isDefeated()) {
			return "That kid got rocked!\n";
		}
		else {
			return "Another kid stands before you, armed with snowballs.\n";
		}
	}*/
};

