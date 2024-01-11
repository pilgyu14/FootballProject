#include "pch.h"
#include "Staduim.h"
#include "Image.h"
#include "ResMgr.h"
#include "Vec2.h"

Staduim::Staduim()
{
	m_Image = ResMgr::GetInst()->ImgLoad(L"StaduimImg", L"Image\\Staduim.bmp");
}

Staduim::~Staduim()
{
}

void Staduim::Update()
{
}

void Staduim::Render(HDC _dc)
{
	int Width = (int)m_Image->GetWidth();
	int Height = (int)m_Image->GetHeight();

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	//¸¶Á¨Å¸ »ö»ó »¬¶§ transparent: Åõ¸íÇÑ
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width * vScale.x, Height * vScale.y
		, m_Image->GetDC()
		, 0, 0, Width, Height
		, RGB(255, 0, 255));
	Component_Render(_dc);
}

