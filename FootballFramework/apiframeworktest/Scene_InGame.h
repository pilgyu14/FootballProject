#pragma once
#include "Scene.h"
class Scene_InGame :
    public Scene
{
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
public:
    Scene_InGame();
    virtual ~Scene_InGame();
};

