#pragma once
#include "pch.h"

class Goalkeeper; 
class State; 
//template <typename T> 
class StateMachine
{
private:
	Object* m_target; 
	Goalkeeper* m_owner;
	map< STATE_TYPE, State* > m_stateMap;
	State* m_prevState;
	State* m_nowState;
public:

	StateMachine(Goalkeeper* owner);
	~StateMachine();
public:
	void Update(); // 현재 상태 업데이트 

public:
	void AddState(State* state); // 처음에 상태 추가하기
	// 현재 상태 반환
	State* GetCurState() {return m_nowState;}
	wstring GetCurStateName(); 
	void ChangeState(STATE_TYPE stateType); // 상태 변경 
};

