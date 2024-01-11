#include "pch.h"
#include "StartPlayer.h"
#include "TimeMgr.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "Core.h"

StartPlayer::StartPlayer()
	:minX(330),
	 maxX(130),
	 dir(1),
	 speed(80)
{
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"PlayerRightRun", L"Image\\PlayerRightRun.bmp");

	Image* pImg2 = ResMgr::GetInst()->ImgLoad(L"PlayerLeftRun", L"Image\\PlayerLeftRun.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"PlayerRightRunAni", pImg, Vec2(0.f, 0.f), Vec2(16.f, 24.f), Vec2(16.f, 0.f), 4, 0.05f);
	GetAnimator()->CreateAnimation(L"PlayerLeftRunAni", pImg2, Vec2(0.f, 0.f), Vec2(16.f, 24.f), Vec2(16.f, 0.f), 4, 0.05f);

	SetDirAni();
}

StartPlayer::~StartPlayer()
{
}

void StartPlayer::Update()
{
	Vec2 vPos = GetPos();

	float resolutionX = Core::GetInst()->GetResolution().x / 2;

	if (vPos.x >= resolutionX + 130 || vPos.x <= resolutionX - 330)
	{
		dir *= -1;
		GetAnimator()->Stop();
		SetDirAni();
	}

	vPos.x += (float)speed * fDT * dir;

	SetPos(vPos);
	GetAnimator()->Update();
}

void StartPlayer::Render(HDC _dc)
{
	Component_Render(_dc);
}

void StartPlayer::SetDirAni()
{
	if(dir == 1)
		GetAnimator()->Play(L"PlayerRightRunAni", true);
	else if(dir == -1)
		GetAnimator()->Play(L"PlayerLeftRunAni", true);
}

void StartPlayer::SetDir(int setDir)
{
	dir = setDir;
	GetAnimator()->Stop();
	SetDirAni();
}
