#pragma once
#include <string>
#include "Ammo.h"
#include "Snowball.h"
#include "SuperSnowball.h"

// This class is an example of requirement: LO1. Design and implement a class.
/// <summary>
/// This is an Enemy class.
/// </summary>
class Enemy
{
/* The following class properties are an example of requirement :
 *		LO2a. Include comments describing the visibility inheritance model
 * The following properties have the protected access modifier.
 *		When inherited, these properties are treated like private members:
 *		they are accessible to the derived class but
 *		are not accessible outside the derived class.
 */
protected:
	int currentHealth;
	int maxHealth;
	int pointsWorth;
public:
	/// <summary>
	/// Class constructor.
	/// </summary>
	Enemy(int health) {
		currentHealth = health;
		maxHealth = health;
		pointsWorth = health;
	};

	/// <summary>
	/// Reduce the enemy's health points.
	/// </summary>
	/// <param name="ammo">The ammo to attack the enemy with.</param>
	void reduceHealth(Snowball* ammo) {
		// This will deal 1 damange to the enemy.
		currentHealth -= ammo->getDamage();
	}

	/// <summary>
	/// Reduce the enemy's health points.
	/// </summary>
	/// <param name="ammo">The ammo to attack the enemy with.</param>
	void reduceHealth(SuperSnowball* ammo) {
		// This will deal 2 damage to the enemy.
		currentHealth -= ammo->getDamage();
	}

	/// <summary>
	/// Get if the enemy has been defeated.
	/// </summary>
	/// <returns>Whether the enemy is defeated.</returns>
	bool isDefeated() {
		return currentHealth <= 0;
	}

	/// <summary>
	/// Get the enemy's point worth after they are defeated.
	/// </summary>
	int getPointsWorth() {
		return pointsWorth;
	}

	/// <summary>
	/// Get the enemy's max health points.
	/// </summary>
	int getMaxHealth() {
		return maxHealth;
	}

	/// <summary>
	/// Get whether the enemy still has full health.
	/// </summary>
	bool isFullHealth() {
		return currentHealth == maxHealth;
	}

	/*virtual string getEnemyMessage() {
		return "";
	}*/
};

