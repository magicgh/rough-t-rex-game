//
// Created by magicgh on 5/25/2020.
//

#pragma once

#include <math.h>
#include <vector>
#include <deque>
#include <algorithm>
#include "sprite.h"
#include "shape.h"
#include "randomizer.h"
#include "speed.h"

class Cactus : public Sprite {
private:
    std::vector<Vec> img_size; //角色图片大小
    std::vector<PIMAGE> img_file; //角色图片
    std::deque<Rect> cac_list; //障碍物列表
    std::deque<int> cac_type; //障碍物类型
    double diff = 1.0; //难度系数

public:
    Cactus(const int type, const double diff);

    Cactus() = default; //构造函数

    ~Cactus() = default;

    void draw(); //画障碍物

    void move(); //移动

    void generate(); //生成障碍物

    double getDiff(); //获取难度系数

    void setDiff(const double &diff); //设置难度系数

    Rect frontRect(); //获取障碍物前方位置

    void reset(); //重置函数

    bool empty();

};
