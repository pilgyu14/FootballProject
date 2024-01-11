#pragma once
#include "Object.h"

class Image;
class Player :
    public Object
{
private:
    Image* m_pImage;
public:
    Player();
    //Player(const Player& _origin) 
    //    : Object(_origin)
    //    , m_pImage(_origin.m_pImage)
    //{}
    ~Player();
private:
//    Player* Clone{ return new Player(*this); }
    CLONE(Player);
private:
    float hSpeed;
    float vSpeed;
    bool isShoot;
public:
    void Update()       override;
    void Render(HDC _dc) override;
    void EnterCollision(Collider* collider) override;
};

