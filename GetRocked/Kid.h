#pragma once
#include "Enemy.h"
#include <string>
// This Class is an example of requirement:
//	LO2. Use subclassing to design simple class hierarchies that allow code
//		to be reused for distinct subclasses.
/// <summary>
/// Kid is a type of enemy the user can encounter.
/// Creating an object of type Kid calls the base class, Enemy's, constructor.
/// </summary>
class Kid : public Enemy
{
public:

	/*
	This class is an example of requirement:
		LO5. Explain the relationship between object-oriented inheritance
			(code-sharing and overriding) and subtyping (the idea of a
			subtype being usable in a context that expects the supertype).
	The Kid class will inherit the member properties of Enemy:
		int currentHealth, int maxHealth, int pointsWorth
		Kid is a subtype of Enemy.
	*/
	/// <summary>
	/// Default constructor.
	/// </summary>
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

