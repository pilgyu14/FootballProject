#include "pch.h"
#include "VSIcon.h"
#include "Image.h"
#include "ResMgr.h"
#include "Vec2.h"

VSIcon::VSIcon()
{
	vsImg = ResMgr::GetInst()->ImgLoad(L"VSImg", L"Image\\VS.bmp");
}

VSIcon::~VSIcon()
{
}

void VSIcon::Update()
{
}

void VSIcon::Render(HDC _dc)
{
	int Width = (int)vsImg->GetWidth();
	int Height = (int)vsImg->GetHeight();

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	//¸¶Á¨Å¸ »ö»ó »¬¶§ transparent: Åõ¸íÇÑ
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width * vScale.x, Height * vScale.y
		, vsImg->GetDC()
		, 0, 0, Width, Height
		, RGB(255, 0, 255));
	Component_Render(_dc);
}
