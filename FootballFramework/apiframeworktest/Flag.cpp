#include "pch.h"
#include "Flag.h"
#include "Image.h"
#include "ResMgr.h"
#include "Vec2.h"
#include "KeyMgr.h"
#include "Core.h"
#include "Arrow.h"
#include "SoundMgr.h"
#include "StageMgr.h"

Flag::Flag()
	:curIndex(0),
	 check(false),
	 rule(L"¡è¡é:ÆÀ¼±ÅÃ"),
	 rule2(L"Enter:°ÔÀÓ½ÃÀÛ")
{
	// Flag Setting
	flags[0] = L"Ghana";
	flags[1] = L"Japan";
	flags[2] = L"USA";
	flags[3] = L"France";
	flags[4] = L"Argentina";
	flags[5] = L"Korea";

	SetIndexImage();

	arrowUP = new Arrow;
	arrowUP->SetDir(Dir::UP);
	arrowUP->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 35, Core::GetInst()->GetResolution().y / 2 - 100));
	arrowUP->SetScale(Vec2(0.3f, 0.3f));
	CreateObject(arrowUP, GROUP_TYPE::UI);

	arrowDown = new Arrow;
	arrowDown->SetDir(Dir::DOWN);
	arrowDown->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 35, Core::GetInst()->GetResolution().y / 2 + 190));
	arrowDown->SetScale(Vec2(0.3f, 0.3f));
	CreateObject(arrowDown, GROUP_TYPE::UI);

	arrowUP->CheckAlpha(curIndex);
	arrowDown->CheckAlpha(curIndex);
}

Flag::~Flag()
{
}

void Flag::Update()
{
	if (!check)
	{
		if (KEY_TAP(KEY::UP))
		{
			if (curIndex > 0)
			{
				curIndex--;
				SetIndexImage();
				arrowUP->CheckAlpha(curIndex);
				arrowDown->CheckAlpha(curIndex);
				StageMgr::GetInst()->SetCurStageData((STAGE_TYPE)curIndex);
				SoundMgr::GetInst()->Play(L"CursorEff");
			}
		}
		if (KEY_TAP(KEY::DOWN))
		{
			if (curIndex < 4)
			{
				curIndex++;
				SetIndexImage();
				arrowUP->CheckAlpha(curIndex);
				arrowDown->CheckAlpha(curIndex);
				StageMgr::GetInst()->SetCurStageData((STAGE_TYPE)curIndex);
				SoundMgr::GetInst()->Play(L"CursorEff");
			}
		}
	}
}

void Flag::Render(HDC _dc)
{
	int Width = (int)f_curImg->GetWidth();
	int Height = (int)f_curImg->GetHeight();

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	//¸¶Á¨Å¸ »ö»ó »¬¶§ transparent: Åõ¸íÇÑ
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width * vScale.x, Height * vScale.y
		, f_curImg->GetDC()
		, 0, 0, Width, Height
		, RGB(255, 0, 255));

	if (!check)
	{
		// ±ÛÀÚ
		HFONT hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH, TEXT("±Ã¼­"));

		HFONT oldFont = (HFONT)SelectObject(_dc, hFont);

		SetTextColor(_dc, RGB(0, 0, 0));

		TextOut(_dc, 830, 300, rule.c_str(), rule.length());

		TextOut(_dc, 830, 350, rule2.c_str(), rule2.length());

		SelectObject(_dc, oldFont);
		DeleteObject(hFont);
	}
	Component_Render(_dc);
}

void Flag::SetCheck(bool _check)
{
	check = _check;
	if (_check)
	{
		arrowDown->CheckAlpha(-1);
		arrowUP->CheckAlpha(-1);
	}
}

void Flag::SetIndexImage()
{
	wstring fileRoute = L"Image\\" + flags[curIndex] + L".bmp";
	f_curImg = ResMgr::GetInst()->ImgLoad(L"FlagImg" + to_wstring(curIndex), fileRoute);
}
