#pragma once
class StageData // ������������ ��ȭ�ϴ� ��Ű�� ������
{
public:
	float RunSpeed; // ��Ű�� �޷����� �ӵ�
	float DiveSpeed; // ���̺� �ӵ�
	float DiveColxSize; // ���̺� ���� �ٴ� üũ 
public:
	StageData(float runSpeed, float diveSpeed, float diveColxSize)
	{
		RunSpeed = runSpeed;
		DiveSpeed = diveSpeed;
		DiveColxSize = diveColxSize;
	}
	~StageData(); 
};

