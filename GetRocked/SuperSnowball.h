#pragma once
#include "Ammo.h"
/// <summary>
/// SuperSnowball is a type of ammo the user can collect and use. 
/// Creating an object of type SuperSnowball calls the base class, Ammo's, constructor.
/// </summary>
class SuperSnowball : public Ammo
{
public:
	/// <summary>
	/// Default Constructor
	/// </summary>
	SuperSnowball() : Ammo(2) {
	}

	SuperSnowball(Ammo* ammo) : Ammo(ammo->getDamage()) {
	}
};

