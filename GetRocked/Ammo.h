#pragma once
#include <string>
#include <iostream>
/// <summary>
/// The ammo class.
/// </summary>
class Ammo
{
private:
	int damage;

public:
	/// <summary>
	/// Constructor to set the damage of the ammo.
	/// </summary>
	Ammo(int dmg) {
		damage = dmg;
	}

	/// <summary>
	/// Get the damage of the ammo.
	/// </summary>
	/// <returns>An integer representing the damage of the ammo.</returns>
	int getDamage() {
		return damage;
	}

	/// <summary>
	/// Ask the user for which type of ammo to use.
	/// </summary>
	static int AskForAmmoResponse();
};

