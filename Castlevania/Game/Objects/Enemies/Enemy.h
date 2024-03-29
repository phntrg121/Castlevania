#pragma once

#include "..\GameObject.h"
#include "..\Simon.h"

class Enemy : public GameObject
{
protected:
	bool active;
	bool incell;
	bool alive;
	bool outview;
	int hp;
	bool hit;
	DWORD invulnerableTime;
	DWORD invulnerableTimeStart;
	int score;
	float default_x, default_y;
	bool default_flip;
	float activeL, activeR;

	void CheckView();

public:
	Enemy();

	bool IsAlive() { return alive; }
	bool IsActive() { return active; }
	bool IsInCell() { return incell; }
	bool IsOutView() { return outview; }
	void InCell(bool cell) { incell = cell; }
	bool IsHit();

	virtual void Active();
	virtual void Unactive();
	virtual void TakeDamage(int damage, LPGAMEOBJECT hitter);

	void SetDefaultFlip(bool flip) { default_flip = flip; }
	void SetDefaultPosition(float x, float y) { default_x = x; default_y = y; }
	void SetActiveLR(float l, float r) { activeL = l; activeR = r; }

	void GetDefaultPosition(float& x, float& y) { x = default_x; y = default_y; }

	virtual Enemy* Clone() = 0;
	virtual void Update(DWORD dt, std::vector<LPGAMEOBJECT>* objects);
	virtual void Brain(DWORD dt) = 0;
	virtual void Render(float x, float y);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
};
typedef Enemy* LPENEMY;

