//
// Created by magicgh on 5/25/2020.
//
#pragma once

#include "graphics.h"
#include "constant.h"

class Sprite {
protected:
    int id;
public:
    Sprite() = default;

    virtual void draw() = 0;
};