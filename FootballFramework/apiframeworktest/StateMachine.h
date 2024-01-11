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
	void Update(); // ���� ���� ������Ʈ 

public:
	void AddState(State* state); // ó���� ���� �߰��ϱ�
	// ���� ���� ��ȯ
	State* GetCurState() {return m_nowState;}
	wstring GetCurStateName(); 
	void ChangeState(STATE_TYPE stateType); // ���� ���� 
};

