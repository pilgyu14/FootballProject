#include "pch.h"
#include "State.h"
#include "Goalkeeper.h"
#include "StateMachine.h"

State::State(Goalkeeper* owner, StateMachine* stateMachine, STATE_TYPE stateType)
	:m_owner(nullptr)
	, m_stateMachine(nullptr)
{
	this->m_owner = owner;
	this->m_stateMachine = stateMachine;
	this->m_stateType = stateType;
}

State::~State()
{
	if (m_owner != nullptr)
	{
		delete m_owner;
	}
	if (m_stateMachine != nullptr)
	{
		delete m_stateMachine;
	}
}


