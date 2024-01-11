#include "pch.h"
#include "StateMachine.h"
#include "State.h"
#include "Goalkeeper.h"

StateMachine::StateMachine(Goalkeeper* owner) 
	: m_prevState(nullptr)
	, m_nowState(nullptr)
{
	this->m_owner = owner;
}

StateMachine::~StateMachine()
{
	if (m_owner != nullptr)
		delete m_owner;
	if (m_stateMap.empty() == false)
		m_stateMap.clear();
	if (m_prevState != nullptr)
		delete m_prevState;
	if (m_nowState != nullptr)
		delete m_nowState;
}
	
void StateMachine::Update()
{
	if (m_nowState != nullptr)
	{
		m_nowState->Stay();
	}
}

void StateMachine::AddState(State* state)
{
	m_stateMap.insert(make_pair(state->GetStateType(), state));
}

wstring StateMachine::GetCurStateName()
{
	wstring str; 
	if (m_nowState->GetStateType() == STATE_TYPE::IDLE)
	{
		str = L"IDLE";
	}
	else if (m_nowState->GetStateType() == STATE_TYPE::RUN)
	{
		str = L"RUN";
	}
	else if (m_nowState->GetStateType() == STATE_TYPE::DIVE)
	{
		str = L"DIVE";
	}
	else if (m_nowState->GetStateType() == STATE_TYPE::TACKLE)
	{
		str = L"TACKLE";
	}
	else
	{
		str = L"���� �� �� ����";
	}
	return str;
}

void StateMachine::ChangeState(STATE_TYPE stateType)
{
	if (m_nowState != nullptr)
	{
		m_nowState->Exit();
	}
	// ������ prevState�� ���� 
	m_prevState = m_nowState;

	// map���� stateType�� ���� nowState ���� 
	m_nowState = m_stateMap[stateType];
	m_nowState->Enter();
}


