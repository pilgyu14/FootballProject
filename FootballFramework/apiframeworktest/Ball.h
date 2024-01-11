#pragma once
#include "Object.h"
class Player;
class GoalText;
class Ball :
    public Object
{
public:
    Ball();
    ~Ball();
private:
    virtual void    Update() override;
    virtual void	Render(HDC _dc) override;
    virtual void	EnterCollision(Collider* _pOther);
    CLONE(Ball);
private:
    int dir = -1;
    // -1:L 0:M 1:R
    int rot;
    float speedX;
    float speedY;
    float curDT;
    Vec2 ballPos;
    bool isCheck = false;
    bool isBlocked = false;
    bool isShoot = false;
    GoalText* pObj;
private:
    void CreateGoalText();
public:
    bool GetShoot() { return isShoot; }
    bool GetBlocked() { return isBlocked; }
    void SetShoot(bool value) { isShoot = value; }
    GoalText* MyGoldText() { return pObj; }
};