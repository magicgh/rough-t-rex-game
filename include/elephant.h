//
// Created by magicgh on 5/25/2020.
//
#pragma once

#include <vector>
#include "graphics.h"
#include "sprite.h"
#include "shape.h"
#include "speed.h"

class Elephant : public Sprite {
private:
    std::vector<PIMAGE>img_file;
    std::vector<Vec>img_size;
    Rect ele_rect;
    bool side=0, jumping=0;
    MUSIC jump_music;
public:
    Elephant(int type);

    void draw();

    void drawDead();

    void run();

    void jump(bool type);

    void drawStand();

    void reset();

    Rect getRect();

};