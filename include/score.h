//
// Created by magicgh on 5/30/2020.
//

#pragma once

#include <math.h>
#include "shape.h"
#include "graphics.h"
#include "constant.h"
#include "speed.h"
#include <fstream>
#include <iostream>

class ScoreBoard {
private:
    Rect position;
    int score,max_score;
public:
    ScoreBoard(const int type);

    void draw();

    void update();

    void reset();

    int getScore();

    void save();
};