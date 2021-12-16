#pragma once
#include <string>
#include "Ammo.h"

// This class is an example of requirement: LO1. Design and implement a class.
class Enemy
{
// The following class properties are an example of requirement:
//		LO2a. Include comments describing the visibility inheritance model
// The following properties have the protected access modifier.
//		When inherited, these properties are treated like private members: 
//		they are accessible to the derived class but
//		are not accessible outside the derived class.
protected:
	int currentHealth;
	int maxHealth;
	int pointsWorth;
public:
	// Class constructor.
	Enemy(int health) {
		currentHealth = health;
		maxHealth = health;
		pointsWorth = health;
	};

	// Reduce the enemy's health points depending on the ammo type.
	void reduceHealth(Ammo* ammo) {
		currentHealth -= ammo->getDamage();
	}

	// Get if the enemy has been defeated.
	bool isDefeated() {
		return currentHealth <= 0;
	}

	// Get the enemy's point worth after they are defeated.
	int getPointsWorth() {
		return pointsWorth;
	}

	// Get the enemy's max health points.
	int getMaxHealth() {
		return maxHealth;
	}

	// Get whether the enemy still has full health.
	bool isFullHealth() {
		return currentHealth == maxHealth;
	}

	/*virtual string getEnemyMessage() {
		return "";
	}*/
};

