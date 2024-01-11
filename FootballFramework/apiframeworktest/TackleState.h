#pragma once
#include "State.h"

class Goalkeeper;
class TackleState :
    public State
{
public:
    TackleState(Goalkeeper* owner, StateMachine* stateMachine, STATE_TYPE stateType);    // State을(를) 통해 상속됨

    // State을(를) 통해 상속됨
    virtual void Enter() override;
    virtual void Stay() override;
    virtual void Exit() override;
};

