//
// Created by magicgh on 5/25/2020.
//
#pragma once

#include <graphics.h>
#include <vector>
#include <math.h>
#include "elephant.h"
#include "obstacle.h"
#include "score.h"
#include "shape.h"


class SceneObj : public Sprite {
protected:
    Rect pos;
    Vec square;
    PIMAGE img = newimage();
    int length;
public:
    SceneObj() = default;

};

class Ground : public SceneObj {
public:
    Ground() = default;

    void draw();

    void drawLoop();

    void reset();

    void init();

    void setType(const int type);
};

class Cloud : public SceneObj {
public:
    Cloud() = default;

    void draw();

    void drawLoop();

    void init();

    void reset();

    void setType(const int type);
};

class GameOver : public SceneObj {
public:
    GameOver();

    void draw();
};


class Scene {
protected:
    Cloud cloud;
    Ground ground;
    GameOver game_over;
public:
    Scene() = default;
    ~Scene() = default;
    virtual void draw(Elephant &ele, Cactus &cac, ScoreBoard &sb)=0;
};

class StartScene : public Scene {
public:
    StartScene(const int type);

    void draw(Elephant &ele, Cactus &cac, ScoreBoard &sb) override;
};

class GameScene : public Scene {
public:
    GameScene(const int type);

    void draw(Elephant &ele, Cactus &cac, ScoreBoard &sb) override;
};

class EndScene : public Scene {
public:
    EndScene(const int type);

    void draw(Elephant &ele, Cactus &cac, ScoreBoard &sb) override;

    void restart(Elephant &ele, Cactus &cac, ScoreBoard &sb);
};

