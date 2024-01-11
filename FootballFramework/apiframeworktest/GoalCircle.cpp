#include "pch.h"
#include "GoalCircle.h"
#include "Image.h"
#include "ResMgr.h"
#include "Vec2.h"

GoalCircle::GoalCircle()
{
	originImg = ResMgr::GetInst()->ImgLoad(L"OriginImg", L"Image\\OrginCircle.bmp");
	goalImg = ResMgr::GetInst()->ImgLoad(L"GreenImg", L"Image\\GreenCircle.bmp");
	failImg = ResMgr::GetInst()->ImgLoad(L"RedImg", L"Image\\RedCircle.bmp");

	curImg = originImg;
}

GoalCircle::~GoalCircle()
{
}

void GoalCircle::Update()
{
}

void GoalCircle::Render(HDC _dc)
{
	int Width = (int)curImg->GetWidth();
	int Height = (int)curImg->GetHeight();

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	//¸¶Á¨Å¸ »ö»ó »¬¶§ transparent: Åõ¸íÇÑ
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width * vScale.x, Height * vScale.y
		, curImg->GetDC()
		, 0, 0, Width, Height
		, RGB(255, 0, 255));
	Component_Render(_dc);
}
