#pragma once

#include "ox/Actor.hpp"
#include "ox/intrusive_ptr.hpp"

class MainScene : public oxygine::Actor
{
public:
    MainScene();
private:
    void createTestScene();
};

typedef oxygine::intrusive_ptr<MainScene> spMainScene;