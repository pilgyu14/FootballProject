#include "pch.h"
#include "Scene_Start.h"
#include "KeyMgr.h"
#include "Staduim.h"
#include "StartPlayer.h"
#include "StartSceneText.h"
#include "Core.h"
#include "SoundMgr.h"
Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}

void Scene_Start::Enter()
{
	// 배경음
	SoundMgr::GetInst()->LoadSound(L"StartBGM", true, L"Sound\\ForwinBgm.mp3");
	SoundMgr::GetInst()->LoadSound(L"InGameBgm", false, L"Sound\\CrowdBgm.wav");
	SoundMgr::GetInst()->LoadSound(L"SelectEff", false, L"Sound\\SelectEff.mp3");
	SoundMgr::GetInst()->LoadSound(L"CursorEff", false, L"Sound\\CursorEff.mp3");
	SoundMgr::GetInst()->LoadSound(L"KickEff", false, L"Sound\\KickEff.wav");
	SoundMgr::GetInst()->LoadSound(L"GoalEff", false, L"Sound\\GoalEff.wav");
	SoundMgr::GetInst()->LoadSound(L"StartWhistleEff", false, L"Sound\\Whistle1Eff.wav");
	SoundMgr::GetInst()->LoadSound(L"EndWhistleEff", false, L"Sound\\Whistle3Eff.wav");
	SoundMgr::GetInst()->LoadSound(L"SighEff", false, L"Sound\\SighEff.wav");
	SoundMgr::GetInst()->LoadSound(L"KoreaBgm", true, L"Sound\\KoreaBgm.mp3");

	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	SoundMgr::GetInst()->Play(L"StartBGM");

	// 맵 그리기
	Object* pObj = new Staduim;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 + 110));
	pObj->SetScale(Vec2(0.7f, 0.7f));
	AddObject
	(pObj, GROUP_TYPE::MAP);

	// 사람들 생성
	for (int i = -200; i <= 200; i = i += 100)
	{
		int dir = rand() % 2;
		int speed = (rand() % 51) + 50;
		StartPlayer* pObj = new StartPlayer;
		pObj->SetDir(dir == 1 ? 1 : -1);
		pObj->SetSpeed(speed);
		pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 + i));
		pObj->SetScale(Vec2(2.f, 2.f));
		AddObject(pObj, GROUP_TYPE::PLAYER);
	}
	pObj = new StartSceneText;
	AddObject(pObj, GROUP_TYPE::UI);
}

void Scene_Start::Exit()
{
	DeleteAll();
}

void Scene_Start::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::STAGE);
		SoundMgr::GetInst()->Play(L"SelectEff");
	}
}
