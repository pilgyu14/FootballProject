#include "pch.h"
#include "TouchLine.h"
#include "Collider.h"

TouchLine::TouchLine()
{
	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	GetCollider()->SetScale(Vec2(60.f, 550.f));
}

TouchLine::~TouchLine()
{
}

void TouchLine::Update()
{
}

void TouchLine::Render(HDC _dc)
{
	Component_Render(_dc);
}
