#pragma once
#include "Object.h"
class Image;
class Arrow :
    public Object
{
public:
    Arrow();
    ~Arrow();
private:
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    CLONE(Arrow);
private:
    Image* a_curImg;
    Dir arrowDir;
    int alpha;
public:
    void SetDir(Dir setDir);
    void ChangeImg();
    void CheckAlpha(int index);
};

