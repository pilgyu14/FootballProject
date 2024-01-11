#include "pch.h"
#include "GoalText.h"
#include "ResMgr.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"
#include "Vec2.h"


GoalText::GoalText()
{
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"GoalText", L"Image\\GoalText.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"GoalTextAni", pImg, Vec2(0.f, 0.f), Vec2(64.f, 64.f), Vec2(64.f, 0.f), 5, 0.1f);
	GetAnimator()->Play(L"GoalTextAni", false);
}

GoalText::~GoalText()
{
}

void GoalText::Update()
{
	GetAnimator()->Update();
}

void GoalText::Render(HDC _dc)
{
	Component_Render(_dc);
}
