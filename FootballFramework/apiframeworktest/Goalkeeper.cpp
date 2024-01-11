#include "pch.h"
#include "define.h"
#include "KeyMgr.h"
#include "Goalkeeper.h"
#include "StateMachine.h"
#include "State.h"
#include "IdleState.h"
#include "RunState.h"
#include "ActState.h"
#include "TackleState.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "TimeMgr.h"
#include "SelectGDI.h"
#include "Ball.h"
#include "DiveCollider.h"

Goalkeeper::Goalkeeper(float runSpeed,float diveSpeed)
	:m_stateMachine(nullptr)
	, m_idleState(nullptr)
	, m_runState(nullptr)
	, m_diveState(nullptr)
	, m_diveCollider(nullptr)
	, m_idleDistance(100)
	, m_tackleDistance(30)
{
	m_runSpeed = runSpeed;
	m_diveSpeed = diveSpeed; 
	// collider 새성
	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 30.f));
	GetCollider()->SetOffsetPos(Vec2(-8.f, -10.f));

	// FSM 초기화 및 설정 
	m_stateMachine = new StateMachine(this);
	m_idleState = new IdleState(this, m_stateMachine, STATE_TYPE::IDLE);
	m_runState = new RunState(this, m_stateMachine, STATE_TYPE::RUN);
	m_diveState = new DiveState(this, m_stateMachine, STATE_TYPE::DIVE);
	m_tackleState = new TackleState(this, m_stateMachine, STATE_TYPE::TACKLE);
	m_stateMachine->AddState(m_idleState);
	m_stateMachine->AddState(m_runState);
	m_stateMachine->AddState(m_diveState);
	m_stateMachine->AddState(m_tackleState);

	m_stateMachine->ChangeState(STATE_TYPE::RUN);
	// FSM 끝 



	// 애니메이션 설정
	SetAnimations();

}

Goalkeeper::~Goalkeeper()
{
	if (m_stateMachine != nullptr)
		DeleteObject(m_stateMachine);
	if (m_idleState != nullptr)
		DeleteObject(m_idleState);
	if (m_runState != nullptr)
		DeleteObject(m_runState);
	if (m_diveState != nullptr)
		DeleteObject(m_diveState);
	if (m_diveCollider != nullptr)
		DeleteObject(m_diveCollider);
}

void Goalkeeper::Update()
{
	//if (KEY_TAP(KEY::A))
	//{
	//	m_stateMachine->ChangeState(STATE_TYPE::IDLE);
	//}
	//else if (KEY_TAP(KEY::S))
	//{
	//	m_stateMachine->ChangeState(STATE_TYPE::RUN);
	//}
	//else if (KEY_TAP(KEY::D))
	//{
	//	m_stateMachine->ChangeState(STATE_TYPE::DIVE);
	//}
	//else if (KEY_TAP(KEY::Q))
	//{
	//	PlayLeftDivingAnim();
	//}
	//else if (KEY_TAP(KEY::W))
	//{
	//	PlayRightDivingAnim();
	//}
	//else if (KEY_TAP(KEY::E))
	//{
	//	//PlayRunAnim();
	//	PlayTackleAnim();
	//}
	m_stateMachine->Update();
	GetAnimator()->Update();

}

void Goalkeeper::Render(HDC _dc)
{
	Component_Render(_dc);

	// 디버그용 코드 시작 
	//wstring curStateName = m_stateMachine->GetCurStateName();
	//TextOut(_dc, 10, 10, curStateName.c_str(), curStateName.length()); // 현재 상태 이름 
	//TextOut(_dc, 10, 40, m_debugText1.c_str(), m_debugText1.length()); // Enter
	//TextOut(_dc, 10, 70, m_debugText2.c_str(), m_debugText2.length()); // Stay
	//TextOut(_dc, 10, 200, m_debugText3.c_str(), m_debugText3.length()); // Exit
	//if (m_diveCollider->GetIsCollision())
	//{
	//	TextOut(_dc, 10, 120, L"충돌", 2);
	//}

	//PEN_TYPE ePen = PEN_TYPE::RED;
	//SelectGDI p(_dc, ePen);
	//SelectGDI b(_dc, BRUSH_TYPE::HOLLOW);

	//Vec2 pos = GetOrigin();
	//// 멈추는 범위 디버그
	//Ellipse(_dc, pos.x - m_idleDistance,
	//	pos.y + m_idleDistance,
	//	pos.x + m_idleDistance,
	//	pos.y - m_idleDistance);

	//// 태클 범위 디버그
	//Ellipse(_dc, pos.x - m_tackleDistance,
	//	pos.y + m_tackleDistance,
	//	pos.x + m_tackleDistance,
	//	pos.y - m_tackleDistance);


	//// 골키퍼 포지션 -> 플레이어 포지션 
	//MoveToEx(_dc, GetOrigin().x, GetOrigin().y, NULL);
	//LineTo(_dc, GetFollower()->GetOrigin().x, GetFollower()->GetOrigin().y);

	//MoveToEx(_dc, GetPos().x - GetScale().x * 8, GetPos().y, NULL); 
	//LineTo(_dc, GetPos().x, GetPos().y); 
	// 디버그용 코드 끝
}

// 애니메이션 플레이 함수 

void Goalkeeper::SetAnimations()
{
	CreateAnimator();

	Image* pImg1 = ResMgr::GetInst()->ImgLoad(L"GoalkeeperLeftDiving", L"Image\\GoalkeeperFrontLeft.bmp");
	GetAnimator()->CreateAnimation(L"GoalkeeperLeftDiving", pImg1, Vec2(138.f, 0.f), Vec2(23.f, 22.f), Vec2(-23.f, 0.f), 6, 0.05f);

	Image* pImg2 = ResMgr::GetInst()->ImgLoad(L"GoalkeeperRightDiving", L"Image\\GoalkeeperFrontRight.bmp");
	GetAnimator()->CreateAnimation(L"GoalkeeperRightDiving", pImg2, Vec2(0.f, 0.f), Vec2(23.f, 22.f), Vec2(23.f, 0.f), 6, 0.05f);

	Image* pImg3 = ResMgr::GetInst()->ImgLoad(L"GoalkeeperRunFront", L"Image\\GoalkeeperRunFront.bmp");
	GetAnimator()->CreateAnimation(L"GoalkeeperRunFront", pImg3, Vec2(0.f, 0.f), Vec2(16.f, 24.f), Vec2(16.f, 0.f), 4, 0.1f);

	Image* pImg4 = ResMgr::GetInst()->ImgLoad(L"GoalkeeperTackleLeft", L"Image\\GoalkeeperTackleLeft.bmp");
	GetAnimator()->CreateAnimation(L"GoalkeeperTackleLeft", pImg4, Vec2(0.f, 0.f), Vec2(16.f, 24.f), Vec2(16.f, 0.f), 1, 0.1f);

	Image* pImg5 = ResMgr::GetInst()->ImgLoad(L"GoalkeeperIdleFront", L"Image\\GoalkeeperIdleFront.bmp");
	GetAnimator()->CreateAnimation(L"GoalkeeperIdleFront", pImg5, Vec2(0.f, 0.f), Vec2(16.f, 24.f), Vec2(16.f, 0.f), 1, 1.f);

}

void Goalkeeper::PlayAnimByName(wstring animName)
{
	GetAnimator()->Play(animName, false);
}

void Goalkeeper::PlayLeftDivingAnim()
{
	GetAnimator()->Play(L"GoalkeeperLeftDiving", false);
}

void Goalkeeper::PlayRightDivingAnim()
{
	GetAnimator()->Play(L"GoalkeeperRightDiving", false);
}

void Goalkeeper::PlayRunAnim()
{
	GetAnimator()->Play(L"GoalkeeperRunFront", true);
}

void Goalkeeper::PlayTackleAnim()
{
	GetAnimator()->Play(L"GoalkeeperTackleLeft", true);
}

void Goalkeeper::PlayIdleAnim()
{
	GetAnimator()->Play(L"GoalkeeperIdleFront", true);
}

bool Goalkeeper::CheckIdleDistance()
{
	if (GetTargetDistance(this->GetFollower()->GetPos()) < m_idleDistance)
	{
		return true;
	}
	return false;
}

bool Goalkeeper::CheckDive()
{
	if (this->GetDiveCollider()->GetTarget() == nullptr) return false;
	Vec2 tPos = this->GetDiveCollider()->GetTarget()->GetPos();
	Vec2 tpPos = this->GetDiveCollider()->GetTarget()->GetParent()->GetPos();
	float l = (tpPos - tPos).Length();
	if( l < 10) return false;

	Vec2 targetPos = this->GetDiveCollider()->GetTarget()->GetPos();
	if (targetPos.x >= GetPos().x - GetScale().x* 16 / 2 && targetPos.x <= GetPos().x ) return false;

	if (m_diveCollider->GetIsCollision() == true)
	{
		return true;
	}
	return false;
}

bool Goalkeeper::CheckIsBallRight()
{
	Vec2 dir = GetTargetDir(this->GetDiveCollider()->GetTarget()->GetPos());
	if (dir.x > 0) // 오른쪽에 있다면 
	{
		return true;
	}
	else if (dir.x <= 0) // 왼쪽에 있다면 
	{
		return false;
	}
}


bool Goalkeeper::CheckTackleDistance()
{
	if (GetTargetDistance(this->GetFollower()->GetPos()) < m_tackleDistance)
	{
		return true;
	}
	return false;
}


void Goalkeeper::IdleMove() // X축만 따라간다. 
{
	Vec2 vPos = this->GetPos();
	Vec2 dir = this->GetTargetDir(this->GetFollower()->GetPos());
	vPos.x += dir.x * m_runSpeed * 4.f * fDT;

	this->SetPos(vPos);
}

void Goalkeeper::RunForward()
{
	Vec2 vPos = GetPos();
	Vec2 dir = GetTargetDir(this->GetFollower()->GetPos());
	vPos.x += dir.x * m_runSpeed * 3.f * fDT;
	vPos.y += dir.y * m_runSpeed * fDT;
	SetPos(vPos);
}

void Goalkeeper::Dive(bool isRight)
{
	Vec2 vPos = GetPos();
	Vec2 tPos = GetDiveCollider()->GetTarget()->GetPos(); 
	if (isRight == true&& vPos.x <= tPos.x ) // 공보다 더 멀리 뛰면 안돼
	{
		vPos.x += m_diveSpeed * fDT;
	}
	else if(isRight == false && vPos.x >= tPos.x)
	{
		vPos.x -= m_diveSpeed * fDT;
	}
	SetPos(vPos);
}

void Goalkeeper::Tackle()
{
}

float Goalkeeper::GetTargetDistance(Vec2 target)
{
	Vec2 pos = this->GetPos(); // 내 위치
	return (target - pos).Length();
}

Vec2 Goalkeeper::GetTargetDir(Vec2 target)
{
	Vec2 vPos = GetPos();
	return (target - vPos).Normalize();
}

// 충돌 처리 
void Goalkeeper::EnterCollision(Collider* _pOther)
{
	Object* colObj = _pOther->GetObj();
	if (colObj->GetName() == L"Ball") // 공 건드렸으면 
	{
		// 움직이는 거 멈추고
		m_runSpeed = 0.f;
		m_diveSpeed = 0.f;
		m_isEnd =true;
		// 공 뺏어오고 
		GetDiveCollider()->GetTarget()->SetParent(this);
		// 공 멈추고 
		// 플레이어 위치, 공 위치 계산해서 튕기도록
		// -그냥 y를 음수로 x는 무작위로 해서 튕기게 
	}
}
