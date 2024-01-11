#include "pch.h"
#include "ActState.h"
#include "Goalkeeper.h"
#include "StateMachine.h"
#include "Animator.h"
#include "Animation.h"
DiveState::DiveState(Goalkeeper* owner, StateMachine* stateMachine, STATE_TYPE stateType)
	:State(owner, stateMachine, stateType)
	, m_isRightDive(false)
{
}

void DiveState::Enter()
{
	// ���̺� �ִϸ��̼� 
	// �̵� 
	this->m_owner->SetDebugText1(L"DIVE_ENTER");
	if (this->m_owner->CheckIsBallRight() == true) // ���̺��� ���� ���ϱ�, �ִϸ��̼� ����  
	{
		m_isRightDive = true; 
		m_curDiveAnimName = m_rightDiveAnimName; 
	}
	else
	{
		m_isRightDive = false; 
		m_curDiveAnimName = m_leftDiveAnimName;
	}
	this->m_owner->PlayAnimByName(m_curDiveAnimName);
	
}

void DiveState::Stay()
{
	this->m_owner->Dive(m_isRightDive);
	if (this->m_owner->GetAnimator()->FindAnimation(m_curDiveAnimName)->IsFinish() == true)
	{
		this->m_stateMachine->ChangeState(STATE_TYPE::IDLE);
	}
	this->m_owner->SetDebugText1(L"DIVE_STAY");
}

void DiveState::Exit()
{
	this->m_owner->GetAnimator()->Stop();
	this->m_owner->SetDebugText1(L"DIVE_EXIT");
}
