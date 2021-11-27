#pragma once
#include "Ammo.h"
// Snowball is a type of ammo the user can collect and use.
// Creating an object of type Snowball calls the base class, Ammo's, constructor.
class Snowball : public Ammo
{
public:
	Snowball() : Ammo(1) {
	}
};

