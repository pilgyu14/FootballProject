#pragma once
#include "Object.h"
class Outline :
    public Object
{
public:
    Outline();
    ~Outline();
private:
    virtual void    Update() override;
    virtual void	Render(HDC _dc) override;
    CLONE(Outline);
};

