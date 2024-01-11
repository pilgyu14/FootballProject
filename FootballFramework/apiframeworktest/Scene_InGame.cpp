#include "pch.h"
#include "Scene_InGame.h"
#include "Object.h"
#include "Staduim.h"
#include "Goal.h"
#include "Outline.h"
#include "TouchLine.h"
#include "InGameUI.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
Scene_InGame::Scene_InGame()
{
}

Scene_InGame::~Scene_InGame()
{
}
void Scene_InGame::Enter()
{
	//SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	//SoundMgr::GetInst()->Play(L"BGM");
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	SoundMgr::GetInst()->Play(L"KoreaBgm");
	// �� �׸���
	Object* pObj = new Staduim;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 + 110));
	pObj->SetScale(Vec2(0.7f, 0.7f));
	AddObject(pObj, GROUP_TYPE::MAP);

	pObj = new Goal;
	pObj->SetName(L"Goal");
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 80, Core::GetInst()->GetResolution().y / 8 - 10));
	pObj->SetScale(Vec2(2.f, 2.f));
	AddObject(pObj, GROUP_TYPE::Goal);

	//�� ������
	pObj = new Outline;
	pObj->SetName(L"Outline");
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 50, Core::GetInst()->GetResolution().y / 2 - 320));
	AddObject(pObj, GROUP_TYPE::Outline);

	//�� ����
	pObj = new Outline;
	pObj->SetName(L"Outline");
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 450, Core::GetInst()->GetResolution().y / 2 - 320));
	AddObject(pObj, GROUP_TYPE::Outline);

	// ����
	pObj = new TouchLine;
	pObj->SetName(L"Outline");
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 350, Core::GetInst()->GetResolution().y / 2));
	AddObject(pObj, GROUP_TYPE::Outline);

	pObj = new TouchLine;
	pObj->SetName(L"Outline");
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 130, Core::GetInst()->GetResolution().y / 2));
	AddObject(pObj, GROUP_TYPE::Outline);

	// Object �߰�
	pObj = new InGameUI();
	AddObject(pObj, GROUP_TYPE::UI);
 

	// �浹 ����
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BALL, GROUP_TYPE::Goal);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BALL, GROUP_TYPE::Outline);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BALL, GROUP_TYPE::AI);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::AI, GROUP_TYPE::PLAYER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::COLLIDER, GROUP_TYPE::BALL);
}

void Scene_InGame::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_InGame::Update()
{  
	Scene::Update();
}
