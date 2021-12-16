#pragma once
#include "Enemy.h"
#include <string>
// This Class is an example of requirement:
//	LO2. Use subclassing to design simple class hierarchies that allow code
//		to be reused for distinct subclasses.
// Adult is a type of enemy the user can encounter.
/// Creating an object of type Adult calls the base class, Enemy's, constructor.
class Adult : public Enemy
{
private:
public:
	/// <summary>
	/// Default constructor.
	/// </summary>
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

