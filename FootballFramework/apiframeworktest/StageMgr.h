#pragma once
#include <unordered_map>
class StageData; 
class StageMgr
{
public:
	SINGLE(StageMgr);
private:
	STAGE_TYPE m_curStageType;
	StageData* m_curStageData;
	unordered_map<STAGE_TYPE, StageData*> m_stageDataMap;
private:
	StageMgr(); 
	~StageMgr(); 
public:
	void Init(); 
	void Update(); 
public:
	STAGE_TYPE GetCurStageType(){return m_curStageType;}
	StageData* GetCurStageData() { return m_curStageData; }
	void SetCurStageData(STAGE_TYPE stageType);
	

};

