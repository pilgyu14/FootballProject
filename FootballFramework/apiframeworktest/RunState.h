#pragma once
#include "State.h"

class Goalkeeper; 
class Player;
class RunState :
    public State
{
public:
    RunState(Goalkeeper* owner, StateMachine* stateMachine, STATE_TYPE stateType);    // State��(��) ���� ��ӵ�
public:
    virtual void Enter() override;
    virtual void Stay() override;
    virtual void Exit() override;
};

