#pragma once
#include "Object.h"
class GoalText :
    public Object
{
public:
    GoalText();
    ~GoalText();
private:
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    CLONE(GoalText);
};

