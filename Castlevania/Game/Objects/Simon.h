#pragma once

#ifndef SIMON_ANI
#define SIMON_IDLE_ANIMATION		0
#define SIMON_WALK_ANIMATION		1
#define SIMON_CROUNCH_ANIMATION		2
#define SIMON_ATTACK_1_ANIMATION	3
#define SIMON_ATTACK_2_ANIMATION	4
#define SIMON_HITED_ANIMATION		5
#define SIMON_DEAD_ANIMATION		6
#endif // !SIMON_ANI

#define SIMON_SPEED					0.05f
#define JUMP_FORCE					-0.5f;
#define GRAVITY						0.002f;

#include "..\ID.h"
#include "GameObject.h"

class Simon : public GameObject
{
private:
	bool attack;
	bool crounch;
	bool onair;
	bool onstair;

public:
	Simon();
	~Simon();

	void GoIdle();
	void GoLeft();
	void GoRight();
	void Crounch();
	void Jump();
	void Attack(bool crounch);
	void SubAttack();

	void Update(DWORD dt, std::vector<LPGAMEOBJECT>* objects);
	void Render(float x = 0, float y = 0);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

};

