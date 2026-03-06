#include "MainScene.h"

#include "ox/ColorRectSprite.hpp"

using namespace oxygine;

MainScene::MainScene()
{
    setSize(960, 640);

    createTestScene();
}

void MainScene::createTestScene()
{
    spColorRectSprite background = new ColorRectSprite();
    background->setSize(960,640);
    background->setColor(Color(70, 110, 70, 255));
    background->setPosition(0, 0);
    addChild(background);

    spColorRectSprite road = new ColorRectSprite();
    road->setSize(700, 90);
    road->setColor(Color(180, 170, 120, 255));
    road->setPosition(130, 275);
    addChild(road);

    spColorRectSprite testTower = new ColorRectSprite();
    testTower->setSize(60, 60);
    testTower->setColor(Color(100, 180, 255, 255));
    testTower->setPosition(200, 180);
    addChild(testTower);
}
