#pragma once
#include "Object.h"
class Image;
class Flag;
class VSIcon;
class Player;
class Ball;
class Goalkeeper;
class DiveCollider;
class GoalText;
class GoalCircle;
class InGameUI :
    public Object
{
public:
    InGameUI();
    ~InGameUI();
private:
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    CLONE(InGameUI);
private:
    Flag* flag1;
    Flag* flag2;
    VSIcon* vsIcon;

    Player* pPObj;
    Ball*   pBObj;
    Goalkeeper* goalkeeper;
    DiveCollider* diveCol;

    GoalText* myGoldText;

    GoalCircle* pGCircle[5];

    wstring explation;
    int round;
    bool gameStart = false;

    int winCount;
    int failCount;

    wstring winText;
    wstring FailText;
    wstring exitText;
private:
    void UISpawn();
    void IngameSpawn();
};

