//
// Created by magicgh on 5/30/2020.
//

#include "score.h"


PowSpeed score_kernel(1,1.5,8.5);

ScoreBoard::ScoreBoard(const int type){

    setcolor(type == 2 ? WHITE : BLACK);
    setfont(20, 0, "Press Start 2P");
    score_kernel.reset();

    std::ifstream input;
    input.open("score.txt",std::ios::in);
    if(!input.is_open()) max_score=0;
    else input >> max_score;
    input.close();
}

void ScoreBoard::reset() {
    score_kernel.reset();
}

void ScoreBoard::draw() {
    update();
    xyprintf(380 , 10, "HI %05d %05d", max_score, score);
}

void ScoreBoard::update() {
    score = score_kernel.getSpeed();
}

int ScoreBoard::getScore() {
    return score;
}

void ScoreBoard::save() {
    std::ofstream output;
    output.open("score.txt",std::ios::out);
    if(score > max_score) max_score = score;
    output << max_score;
    output.close();
}
