#include "pch.h"
#include "InGameUI.h"
#include "ResMgr.h"
#include "Image.h"
#include "Vec2.h"
#include "Flag.h"
#include "VSIcon.h"
#include "Core.h"
#include "KeyMgr.h"
#include "Player.h"
#include "Ball.h"
#include "Goalkeeper.h"
#include "DiveCollider.h"
#include "TimeMgr.h"
#include "GoalText.h"
#include "GoalCircle.h"
#include "Scene_Stage.h"
#include "SoundMgr.h"
#include "StageMgr.h"
#include"StageData.h"
InGameUI::InGameUI()
	:explation(L"Press S to Start"),
	 winText(L"WIN!!"),
	 FailText(L"LOSE.."),
	 exitText(L"Press Space to continue."),
	 winCount(0),
	 failCount(0),
	 round(1)
{
	for (int i = 0; i < 5; i++)
	{
		pGCircle[i] = new GoalCircle;
		pGCircle[i]->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 200 + (i * 40), Core::GetInst()->GetResolution().y / 2 - 300));
		pGCircle[i]->SetScale(Vec2(2.f, 2.f));
		CreateObject(pGCircle[i], GROUP_TYPE::UI);
	}
	UISpawn();
}

InGameUI::~InGameUI()
{
}

void InGameUI::Update()
{
	if (KEY_TAP(KEY::S) && !gameStart && winCount <= 2 && failCount <= 2)
	{
		gameStart = true;
		DeleteObject(flag1);
		DeleteObject(flag2);
		DeleteObject(vsIcon);
		if (myGoldText != nullptr)
		{
			DeleteObject(myGoldText);
		}
		IngameSpawn();
	}

	if (gameStart)
	{
		if (pBObj->GetShoot())
		{
			if (pBObj->GetBlocked())
			{
				pGCircle[round - 1]->ChangeFail();
				failCount++;
			}
			else
			{
				pGCircle[round - 1]->ChangeGoal();
				winCount++;
			}


			gameStart = false;
			round++;
			myGoldText = pBObj->MyGoldText();
			DeleteObject(pPObj);
			DeleteObject(pBObj);
			DeleteObject(goalkeeper);
			DeleteObject(diveCol);
			if (winCount <= 2 && failCount <= 2)
				UISpawn();
		}
	}

	if ((winCount >= 3 || failCount >= 3) && KEY_TAP(KEY::SPACE))
	{
		SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
		SoundMgr::GetInst()->Play(L"StartBGM");
		ChangeScene(SCENE_TYPE::STAGE);
	}
}

void InGameUI::Render(HDC _dc)
{
	HFONT hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH, TEXT("궁서"));

	HFONT oldFont = (HFONT)SelectObject(_dc, hFont);
	SetBkMode(_dc, TRANSPARENT);

	SetTextColor(_dc, RGB(0, 0, 0));
	if (winCount >= 3)
	{
		TextOut(_dc, 480, 310, winText.c_str(), winText.length());
		TextOut(_dc, 330, 350, exitText.c_str(), exitText.length());
	}
	else if (failCount >= 3)
	{
		TextOut(_dc, 480, 310, FailText.c_str(), FailText.length());
		TextOut(_dc, 330, 350, exitText.c_str(), exitText.length());
	}
	else if (!gameStart)
	{

		wstring roundText = L"Round " + to_wstring(round);

		TextOut(_dc, 460, 250, roundText.c_str(), roundText.length());

		TextOut(_dc, 400, 420, explation.c_str(), explation.length());
	}

	SelectObject(_dc, oldFont);
	SetBkMode(_dc, OPAQUE);
	DeleteObject(hFont);
	Component_Render(_dc);
}

void InGameUI::UISpawn()
{
	// 대한민국 국기
	flag1 = new Flag;
	flag1->SetCheck(true);
	flag1->SetcurIndex((int)STAGE_TYPE::KOREA);
	flag1->SetIndexImage();
	flag1->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 100, Core::GetInst()->GetResolution().y / 2 + 200));
	flag1->SetScale(Vec2(0.2f, 0.2f));
	CreateObject(flag1, GROUP_TYPE::UI);

	// 경쟁 팀 국기
	flag2 = new Flag;
	flag2->SetCheck(true);
	flag2->SetcurIndex((int)StageMgr::GetInst()->GetCurStageType());
	flag2->SetIndexImage();
	flag2->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 380, Core::GetInst()->GetResolution().y / 2 + 200));
	flag2->SetScale(Vec2(0.2f, 0.2f));
	CreateObject(flag2, GROUP_TYPE::UI);

	// VS 아이콘
	vsIcon = new VSIcon;
	vsIcon->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 158, Core::GetInst()->GetResolution().y / 2 - 70));
	vsIcon->SetScale(Vec2(3.5f, 3.5f));
	CreateObject(vsIcon, GROUP_TYPE::UI);
}

void InGameUI::IngameSpawn()
{
	// -250 ~ 50
	int random = (rand() % 301) - 250;
	pPObj = new Player;
	pPObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + random, Core::GetInst()->GetResolution().y / 2));
	pPObj->SetScale(Vec2(2.f, 2.f));
	CreateObject(pPObj, GROUP_TYPE::PLAYER);

	pBObj = new Ball;
	pBObj->SetParent(pPObj);
	pBObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	pBObj->SetScale(Vec2(2.5f, 2.5f));
	pBObj->SetName(L"Ball");
	CreateObject(pBObj, GROUP_TYPE::BALL);

	float runSpeed = StageMgr::GetInst()->GetCurStageData()->RunSpeed;
	float diveSpeed = StageMgr::GetInst()->GetCurStageData()->DiveSpeed;
	float colxSize = StageMgr::GetInst()->GetCurStageData()->DiveColxSize;;
	// 골키퍼 오브젝트
	goalkeeper = new Goalkeeper(runSpeed, diveSpeed);
	goalkeeper->SetName(L"Goalkeeper");
	goalkeeper->SetFollower(pPObj);
	goalkeeper->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 100, (long)100));
	goalkeeper->SetScale(Vec2(2.f, 2.f));
	CreateObject(goalkeeper, GROUP_TYPE::AI);
	// 다이브 체크 콜라이더 오브젝트
	diveCol = new DiveCollider(colxSize);
	diveCol->SetName(L"DiveCollider");
	diveCol->SetParent(goalkeeper);
	//diveCol->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 100, (long)100));
	diveCol->SetScale(Vec2(1.f, 30.f));
	CreateObject(diveCol, GROUP_TYPE::COLLIDER);
	goalkeeper->SetDiveCollider(diveCol);
}


