#include "pch.h"
#include "TackleState.h"
#include "Goalkeeper.h"
#include "StateMachine.h"
#include "Animator.h"
#include "Animation.h"
#include "Player.h"
#include "DiveCollider.h"

TackleState::TackleState(Goalkeeper* owner, StateMachine* stateMachine, STATE_TYPE stateType)
	:State(owner, stateMachine, stateType)
{
}

void TackleState::Enter()
{
	this->m_owner->SetDebugText1(L"TACKLE_ENTER");
	this->m_owner->PlayTackleAnim();
}

void TackleState::Stay()
{
	this->m_owner->SetDebugText2(L"TACKLE_STAY");
	
	// 애니메이션 끝났으면 
	if (this->m_owner->GetAnimator()->FindAnimation(L"GoalkeeperTackleLeft")->IsFinish() == true)
	{
		//this->m_stateMachine->ChangeState(STATE_TYPE::IDLE);
	}
}

void TackleState::Exit()
{
	this->m_owner->SetDebugText3(L"TACKLE_EXIT");
}
