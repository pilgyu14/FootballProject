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
	DiveCollider* m_diveCollider; // 다이빙 체크

private: 
	// FSM
	// STATE
	StateMachine* m_stateMachine;
	IdleState* m_idleState; 
	RunState* m_runState; 
	DiveState* m_diveState; 
	TackleState* m_tackleState; 
private:
	
private: // 디버그
	wstring m_debugText1;
	wstring m_debugText2;
	wstring m_debugText3;
public:
	Goalkeeper(float runSpeed,float diveSpeed);
	~Goalkeeper(); 
public:
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	void Render(HDC _dc) override;
	CLONE(Goalkeeper);
//	virtual Object* Clone() override;
public : // 애니메이션 
	void SetAnimations(); // 애니메이션 설정 
	void PlayAnimByName(wstring animName); // 애니메이션 이름받고 실행
	void PlayLeftDivingAnim(); // 왼쪽 다이빙 애니메이션 플레이
	void PlayRightDivingAnim(); // 오른쪽 다이빙 애니메이션 플레이
	void PlayRunAnim(); // 달리기 애니메이션 플레이  
	void PlayIdleAnim(); // 기본 상태 애니메이션 플레이 
	void PlayTackleAnim(); // 태클 이미지 변경 
public: //FSM
	// 체크 
	bool CheckIdleDistance(); 
	bool CheckDive(); 
	bool CheckTackleDistance(); 
	bool CheckIsBallRight();
	// 행동
	void IdleMove(); // 기본 
	void RunForward(); // 앞으로 달려가기 
	void Dive(bool isRight); // 다이빙 
	void Tackle(); // 태클
public: // 디버그
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
	
