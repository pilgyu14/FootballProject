#include "pch.h"
#include "Scene_Stage.h"
#include "KeyMgr.h"
#include "Staduim.h"
#include "Flag.h"
#include "Arrow.h"
#include "Core.h"
#include "SoundMgr.h"

Scene_Stage::Scene_Stage()
{
}

Scene_Stage::~Scene_Stage()
{
}

void Scene_Stage::Enter()
{
	// 맵 그리기
	Object* pObj = new Staduim;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 + 110));
	pObj->SetScale(Vec2(0.7f, 0.7f));
	AddObject(pObj, GROUP_TYPE::MAP);

	pObj = new Flag;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 245, Core::GetInst()->GetResolution().y / 2 + 200));
	pObj->SetScale(Vec2(0.2f, 0.2f));
	AddObject(pObj, GROUP_TYPE::UI);
}

void Scene_Stage::Exit()
{
	DeleteAll();
}

void Scene_Stage::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::INGAME);
		SoundMgr::GetInst()->Play(L"SelectEff");
		// 무엇을 선택했는지 기억 
		// flags[curIndex]
	}
}
