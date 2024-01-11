#pragma once
#include "Scene.h"
class Scene_Stage :
    public Scene
{
public:
    Scene_Stage();
    virtual ~Scene_Stage();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

