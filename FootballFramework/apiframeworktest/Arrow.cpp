#include "pch.h"
#include "Arrow.h"
#include "Image.h"
#include "ResMgr.h"
#include "Vec2.h"

Arrow::Arrow()
	:arrowDir(Dir::UP),
	 alpha(0)
{
	ChangeImg();
}

Arrow::~Arrow()
{
}

void Arrow::Update()
{
}

void Arrow::Render(HDC _dc)
{
	if (alpha == 0)
	{
		int Width = (int)a_curImg->GetWidth();
		int Height = (int)a_curImg->GetHeight();

		Vec2 vPos = GetPos();
		Vec2 vScale = GetScale();
		//¸¶Á¨Å¸ »ö»ó »¬¶§ transparent: Åõ¸íÇÑ
		TransparentBlt(_dc
			, (int)(vPos.x - (float)(Width / 2))
			, (int)(vPos.y - (float)(Height / 2))
			, Width * vScale.x, Height * vScale.y
			, a_curImg->GetDC()
			, 0, 0, Width, Height
			, RGB(255, 0, 255));
	}
	Component_Render(_dc);
}

void Arrow::SetDir(Dir setDir)
{
	arrowDir = setDir;
	ChangeImg();
}

void Arrow::ChangeImg()
{
	if (arrowDir == Dir::UP)
	{
		a_curImg = ResMgr::GetInst()->ImgLoad(L"ArrowImgUP", L"Image\\ArrowUp.bmp");
	}
	else if (arrowDir == Dir::DOWN)
	{
		a_curImg = ResMgr::GetInst()->ImgLoad(L"ArrowImgDOWN", L"Image\\ArrowDown.bmp");
	}
}

void Arrow::CheckAlpha(int index)
{
	if (index == -1) alpha = 1;
	else if (arrowDir == Dir::UP && index == 0) 
		alpha = 1;
	else if (arrowDir == Dir::DOWN && index == 4) 
		alpha = 1;
	else
	{
		alpha = 0;
	}
	ChangeImg();
}


