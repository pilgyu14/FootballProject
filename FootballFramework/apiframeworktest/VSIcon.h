#pragma once
#include "Object.h"
class Image;
class VSIcon :
    public Object
{
public:
    VSIcon();
    ~VSIcon();
private:
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    CLONE(VSIcon);
private:
    Image* vsImg;
};

