#pragma once
#include <string>
#include <iostream>
class Ammo
{
private:
	int damage;

public:
	Ammo(int dmg) {
		damage = dmg;
	}

	int getDamage() {
		return damage;
	}

	static int AskForAmmoResponse();
};

