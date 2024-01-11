#pragma once
#include "State.h"

class Goalkeeper; 
class Player;
class RunState :
    public State
{
public:
    RunState(Goalkeeper* owner, StateMachine* stateMachine, STATE_TYPE stateType);    // State을(를) 통해 상속됨
public:
    virtual void Enter() override;
    virtual void Stay() override;
    virtual void Exit() override;
};

