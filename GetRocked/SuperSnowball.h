#pragma once
#include "Ammo.h"
// SuperSnowball is a type of ammo the user can collect and use.
// Creating an object of type SuperSnowball calls the base class, Ammo's, constructor.
class SuperSnowball : public Ammo
{
public:
	SuperSnowball() : Ammo(2) {
	}
};

