#pragma once

#include "Weapon.h"

class Axe : public Weapon
{
public:
	Axe(LPGAMEOBJECT wielder) :Weapon(wielder) {}

	LPGAMEOBJECT Clone();
	void Ready(float x, float y, bool flip);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void Update(DWORD dt, std::vector<LPGAMEOBJECT>* objects);
};

