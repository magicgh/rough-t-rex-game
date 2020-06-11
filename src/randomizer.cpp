//
// Created by magicgh on 6/4/2020.
//

#include "randomizer.h"
std::default_random_engine generator(time(nullptr));
Sigmoid obs_v(5,20);
int getObsType(const int &type_number, const double &diff) {
    const double para = obs_v.getPenalty()*diff/FPS;
    std::bernoulli_distribution bernoulli(para);
    if(!bernoulli(generator)) return -1;
    else {
        obs_v.reset();
        return generator()%3;
    }
}