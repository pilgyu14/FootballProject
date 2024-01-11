#pragma once
#include "State.h"

class Goalkeeper;
class TackleState :
    public State
{
public:
    TackleState(Goalkeeper* owner, StateMachine* stateMachine, STATE_TYPE stateType);    // State��(��) ���� ��ӵ�

    // State��(��) ���� ��ӵ�
    virtual void Enter() override;
    virtual void Stay() override;
    virtual void Exit() override;
};

