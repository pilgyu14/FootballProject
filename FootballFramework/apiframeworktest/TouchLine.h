#pragma once
#include "Object.h"
class TouchLine :
    public Object
{
public:
    TouchLine();
    ~TouchLine();
private:
    virtual void    Update() override;
    virtual void	Render(HDC _dc) override;
    CLONE(TouchLine);
};

