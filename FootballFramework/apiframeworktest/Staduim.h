#pragma once
#include "Object.h"
class Image;
class Staduim :
    public Object
{
private:
    Image* m_Image;
public:
    Staduim();
    ~Staduim();
public:
    virtual void    Update() override;
    virtual void	Render(HDC _dc) override;

    CLONE(Staduim);
};

