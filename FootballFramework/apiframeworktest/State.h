#pragma once
class Goalkeeper; 
class StateMachine; 
//template <typename T> 
class State
{
protected:
	STATE_TYPE m_stateType;
	Goalkeeper* m_owner;
	StateMachine* m_stateMachine;
public:
	State(Goalkeeper* owner, StateMachine* stateMachine, STATE_TYPE stateType);

	virtual ~State();
public:
	virtual void Enter() = 0;
	virtual void Stay() = 0;
	virtual void Exit() = 0;

	STATE_TYPE GetStateType() { return m_stateType; }

};

