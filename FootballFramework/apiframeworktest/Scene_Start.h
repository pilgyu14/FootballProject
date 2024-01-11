#pragma once
#include "Scene.h"
class Scene_Start :
    public Scene
{
private:
public:
    Scene_Start();
    virtual ~Scene_Start();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

