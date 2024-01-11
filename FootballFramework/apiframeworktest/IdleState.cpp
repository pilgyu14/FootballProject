#include "pch.h"
#include "IdleState.h"
#include "Goalkeeper.h"
#include "StateMachine.h"
#include "Animator.h"

IdleState::IdleState(Goalkeeper* owner, StateMachine* stateMachine,
	STATE_TYPE stateType)
	:State(owner,stateMachine,stateType)
{

}

void IdleState::Enter()
{
	this->m_owner->SetDebugText1(L"IDLE ENTER");
	this->m_owner->PlayIdleAnim();
}

void IdleState::Stay()
{
	this->m_owner->IdleMove(); 
	this->m_owner->SetDebugText2(L"IDLE STAY");
	if (this->m_owner->GetIsEnd() == true) return;  // 여기서 게임에서 종료됐다는 걸 알아야 해 

	if (this->m_owner->CheckTackleDistance() == true)
	{
		//m_stateMachine->ChangeState(STATE_TYPE::TACKLE);
	}
	if (this->m_owner->CheckDive() == true)
	{
		m_stateMachine->ChangeState(STATE_TYPE::DIVE);
	}
}

void IdleState::Exit()
{
	this->m_owner->SetDebugText3(L"IDLE EXIT");
	this->m_owner->GetAnimator()->Stop();
}
