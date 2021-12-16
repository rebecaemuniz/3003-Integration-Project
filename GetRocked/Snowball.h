#pragma once
#include "Ammo.h"
/// <summary>
/// Snowball is a type of ammo the user can collect and use. 
/// Creating an object of type Snowball calls the base class, Ammo's, constructor.
/// </summary>
class Snowball : public Ammo
{
public:
	/// <summary>
	/// Default Constructor
	/// </summary>
	Snowball() : Ammo(1) {
	}

	Snowball(Ammo* ammo) : Ammo(ammo->getDamage()) {
	}
};

