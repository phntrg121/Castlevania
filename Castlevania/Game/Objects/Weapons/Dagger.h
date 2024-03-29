#pragma once

#include "..\Bullet.h"

class Dagger : public Bullet
{
private:
	void ProcessAABBCollision(LPGAMEOBJECT coObject);
	void ProcessSweptAABBCollision(LPGAMEOBJECT coObject,
		float min_tx, float min_ty, float nx, float ny,
		float& dx, float& dy);

public:
	Dagger(LPGAMEOBJECT shooter, LPGAMEOBJECT target = NULL) :Bullet(shooter, target) {}

	Bullet* Clone();
	void Ready(float x, float y, bool flip);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void Update(DWORD dt, std::vector<LPGAMEOBJECT>* objects);
};

