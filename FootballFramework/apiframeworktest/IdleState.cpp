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
	if (this->m_owner->GetIsEnd() == true) return;  // ���⼭ ���ӿ��� ����ƴٴ� �� �˾ƾ� �� 

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
