#pragma once
#include "State.h"
class Player;
class DiveState :
    public State
{
private:
    bool m_isRightDive; 
    wstring m_curDiveAnimName; 
    const wstring m_leftDiveAnimName = L"GoalkeeperLeftDiving";
    const wstring m_rightDiveAnimName = L"GoalkeeperRightDiving";

public:
    DiveState(Goalkeeper* owner, StateMachine* stateMachine, STATE_TYPE stateType);    // State을(를) 통해 상속됨
public:
    virtual void Enter() override;
    virtual void Stay() override;
    virtual void Exit() override;
};

