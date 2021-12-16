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

	/*
	This class is an example of requirement:
		LO5. Explain the relationship between object-oriented inheritance 
			(code-sharing and overriding) and subtyping (the idea of a 
			subtype being usable in a context that expects the supertype).
	The Adult class will inherit the member properties of Enemy: 
		int currentHealth, int maxHealth, int pointsWorth
		Adult is a subtype of Enemy.
	*/
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

