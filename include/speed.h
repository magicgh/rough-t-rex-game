
//
// Modified by magicgh on 6/4/2020.
//

#pragma once

#include <time.h>
#include <math.h>
#include "constant.h"
#include <cmath>
#include "obstacle.h"

class Timer{
protected:
    clock_t start_time;
public:
    Timer();

    void reset();

    double getTime();

};

class Speed : public Timer {

    virtual int getSpeed() = 0;

};



class FreeFall : public Speed {
private:
    double a,v0;
public:
    FreeFall(const double &a, const double &v0);

    int getSpeed() override;
};


class LogSpeed: public Speed{
private:
    double a,b,c;
public:
    LogSpeed(const double &a, const double &b,const double &c);

    int getSpeed() override;
};

class PowSpeed: public Speed{
private:
    double a,b,c;
public:
    PowSpeed(const double &a, const double &b, const double &c);

    int getSpeed() override;
};

class Sigmoid: public Timer{
private:
    double a,b;
public:
    Sigmoid(const double &a, const double &b);

    double getPenalty() ;
};