#include "pch.h"
#include "Goal.h"
#include "ResMgr.h"
#include "Image.h"
#include "Collider.h"

Goal::Goal()
{
	m_pImage = ResMgr::GetInst()->ImgLoad(L"GoalImg", L"Image\\Goal.bmp");
	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(-40.f, -20.f));
	GetCollider()->SetScale(Vec2(125.f, 30.f));
}

Goal::~Goal()
{
}

void Goal::Update()
{
}

void Goal::Render(HDC _dc)
{
	int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	vPos.x = vPos.x - (Width * vScale.x) / 2.f; 
	vPos.y = vPos.y - (Height * vScale.y) / 2.f; 

	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width * vScale.x, Height * vScale.y
		, m_pImage->GetDC()
		, 0, 0, Width, Height
		, RGB(255, 0, 255));
	Component_Render(_dc);
}
