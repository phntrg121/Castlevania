#include "Torch.h"
#include "..\..\ID.h"
#include "..\..\Scenes\Scene.h"

Torch::Torch()
{
	hp = 1;
	invulnerableTime = 300;
	hit = false;
	alive = true;
	item = -1;
}


void Torch::Update(DWORD dt)
{

}

void Torch::Render(float x, float y)
{
	if (!alive) return;
	currentAnimation->first->Draw(currentAnimation->second, this->x + x, this->y + y);

	//float l, t, r, b;
	//GetBoundingBox(l, t, r, b);
	//NSDebug::RenderBoundBox(x, y, l, t, r, b);
}

void Torch::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = l + 16;
	b = t + 32;
}

LPGAMEOBJECT Torch::Clone()
{
	Torch* clone = new Torch;
	for (ANIMATION* ani : animations)
	{
		clone->AddAnimation(ani->first->Clone());
	}
	clone->SetAnimation(0);
	return clone;
}

bool Torch::IsHitted()
{
	if (GetTickCount() - invulnerableTimeStart >= invulnerableTime)
	{
		hit = false;
	}
	return hit;
}


void Torch::TakeDamage(int damage, LPGAMEOBJECT hitter)
{
	LPSCENE scene = Scenes::GetInstance()->GetScene();

	invulnerableTimeStart = GetTickCount();
	hit = true;

	//hitter bbox
	float lh, th, rh, bh;
	hitter->GetBoundingBox(lh, th, rh, bh);
	//object bbox
	float lo, to, ro, bo;
	GetBoundingBox(lo, to, ro, bo);

	int eff_x, eff_y;
	if (hitter->IsFlip()) eff_x = ro - (rh - lh) / 2;
	else eff_x = lo + (rh - lh) / 2;
	eff_y = to + (bh - th) / 2;

	LPEFFECT effect = Spawner::GetInstance()->SpawnEffect(EFFECT_HIT_ID, eff_x, eff_y);
	Scenes::GetInstance()->GetScene()->AddEffect(effect);

	OutputDebugString(L"Torch being hit\n");

	hp -= damage;

	if (hp <= 0)
	{
		hp = 0;
		alive = false;

		LPSPRITE sprite = currentAnimation->first->GetFrame(currentAnimation->second);
		RECT r = sprite->GetRect();

		LPEFFECT e = Spawner::GetInstance()->SpawnEffect(EFFECT_DEAD_ID, x + ((r.right - r.left) / 2) - 4, y + ((r.bottom - r.top) / 2) - 8);
		scene->AddEffect(e);

		OutputDebugString(L"Torch is dead\n");

		if (item > -1)
		{
			LPITEM i = Spawner::GetInstance()->SpawnItem(item, x + ((r.right - r.left) / 2) - 4, y + ((r.bottom - r.top) / 2) - 8);
			scene->AddItem(i);

			OutputDebugString(L"Item Drop!!!\n");
		}
	}
}
