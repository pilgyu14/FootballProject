#pragma once
class StageData // 스테이지마다 변화하는 골키퍼 데이터
{
public:
	float RunSpeed; // 골키퍼 달려오는 속도
	float DiveSpeed; // 다이빙 속도
	float DiveColxSize; // 다이빙 먼저 뛰는 체크 
public:
	StageData(float runSpeed, float diveSpeed, float diveColxSize)
	{
		RunSpeed = runSpeed;
		DiveSpeed = diveSpeed;
		DiveColxSize = diveColxSize;
	}
	~StageData(); 
};

