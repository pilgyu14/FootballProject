#pragma once
#include "Object.h"
#include "State.h"

class Collider; 
class IdleState; 
class RunState;
class DiveState;
class TackleState; 
class StateMachine;
class Image; 
class DiveCollider; 
class Goalkeeper : 
	public Object
{
private:
	float m_runSpeed; 
	float m_diveSpeed; 
	float m_idleDistance; 
	float m_tackleDistance; 
	bool m_isEnd; 
	DiveCollider* m_diveCollider; // ���̺� üũ

private: 
	// FSM
	// STATE
	StateMachine* m_stateMachine;
	IdleState* m_idleState; 
	RunState* m_runState; 
	DiveState* m_diveState; 
	TackleState* m_tackleState; 
private:
	
private: // �����
	wstring m_debugText1;
	wstring m_debugText2;
	wstring m_debugText3;
public:
	Goalkeeper(float runSpeed,float diveSpeed);
	~Goalkeeper(); 
public:
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	void Render(HDC _dc) override;
	CLONE(Goalkeeper);
//	virtual Object* Clone() override;
public : // �ִϸ��̼� 
	void SetAnimations(); // �ִϸ��̼� ���� 
	void PlayAnimByName(wstring animName); // �ִϸ��̼� �̸��ް� ����
	void PlayLeftDivingAnim(); // ���� ���̺� �ִϸ��̼� �÷���
	void PlayRightDivingAnim(); // ������ ���̺� �ִϸ��̼� �÷���
	void PlayRunAnim(); // �޸��� �ִϸ��̼� �÷���  
	void PlayIdleAnim(); // �⺻ ���� �ִϸ��̼� �÷��� 
	void PlayTackleAnim(); // ��Ŭ �̹��� ���� 
public: //FSM
	// üũ 
	bool CheckIdleDistance(); 
	bool CheckDive(); 
	bool CheckTackleDistance(); 
	bool CheckIsBallRight();
	// �ൿ
	void IdleMove(); // �⺻ 
	void RunForward(); // ������ �޷����� 
	void Dive(bool isRight); // ���̺� 
	void Tackle(); // ��Ŭ
public: // �����
	void SetDebugText1(wstring str) { m_debugText1 = str;}
	void SetDebugText2(wstring str) { m_debugText2 = str; }
	void SetDebugText3(wstring str) { m_debugText3 = str; }
public:
	bool GetIsEnd() { return m_isEnd; }

	DiveCollider* GetDiveCollider() { return m_diveCollider; }
	void SetDiveCollider(DiveCollider* diveCol) { m_diveCollider = diveCol; }
	float GetTargetDistance(Vec2 target); 
	Vec2 GetTargetDir(Vec2 target);

	virtual void EnterCollision(Collider* _pOther) override; 

};
	
