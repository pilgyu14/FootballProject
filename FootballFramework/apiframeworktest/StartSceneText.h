#pragma once
#include "Object.h"
class StartSceneText :
    public Object
{
public:
    StartSceneText();
    ~StartSceneText();
private:
    virtual void    Update() override;
    virtual void	Render(HDC _dc) override;
    CLONE(StartSceneText);
private:
    wstring m_subtitleText;
    wstring m_subtitleText2;
    wstring m_explanationText;
};

