#include "pch.h"
#include "StageMgr.h"
#include "StageData.h"
StageMgr::StageMgr()
	:m_curStageData(nullptr)
{
}

StageMgr::~StageMgr()
{
	DeleteObject(m_curStageData);
	if (m_stageDataMap.empty() == false)
		m_stageDataMap.clear(); 
}

void StageMgr::Init()
{
	m_stageDataMap.insert(make_pair(STAGE_TYPE::GHANA, new StageData(70.f, 400.f, 50.f)));
	m_stageDataMap.insert(make_pair(STAGE_TYPE::JAPAN, new StageData(80.f, 500.f, 50.f)));
	m_stageDataMap.insert(make_pair(STAGE_TYPE::USA, new StageData(90.f, 600.f, 60.f)));
	m_stageDataMap.insert(make_pair(STAGE_TYPE::FRANCE, new StageData(150.f, 400.f, 70.f)));
	m_stageDataMap.insert(make_pair(STAGE_TYPE::ARGENTINA, new StageData(110.f, 700.f, 90.f)));
	
	SetCurStageData(STAGE_TYPE::GHANA);
}

void StageMgr::Update()
{
}

void StageMgr::SetCurStageData(STAGE_TYPE stageType)
{
	m_curStageType = stageType;
	m_curStageData = m_stageDataMap[stageType];
}
