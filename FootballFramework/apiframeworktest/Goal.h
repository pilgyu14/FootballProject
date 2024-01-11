#pragma once
#include "Object.h"
class Image;
class Goal :
    public Object
{
private:
    Image* m_pImage;
public:
    Goal();
    ~Goal();
private:
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    CLONE(Goal);
};

