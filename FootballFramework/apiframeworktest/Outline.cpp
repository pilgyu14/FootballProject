#include "pch.h"
#include "Outline.h"
#include "Collider.h"

Outline::Outline()
{
	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(80.f, 0.f));
	GetCollider()->SetScale(Vec2(350.f, 50.f));
}

Outline::~Outline()
{
}

void Outline::Update()
{
}

void Outline::Render(HDC _dc)
{
	Component_Render(_dc);
}
