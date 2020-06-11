

//
// Modified by magicgh on 6/4/2020.
//

#include "speed.h"
Timer::Timer() {
    start_time = clock();
}

void Timer::reset() {
    start_time = clock();
}

double Timer::getTime() {
    return static_cast<double> (clock() - start_time) / CLOCKS_PER_SEC;
}

FreeFall::FreeFall(const double &a, const double &v0) :a(a),v0(v0),Speed(){};

int FreeFall::getSpeed() {
    double t = static_cast<double> (clock() - start_time) / CLOCKS_PER_SEC;
    return static_cast<int>(round(v0*t+0.5*a*t*t));
}

LogSpeed::LogSpeed(const double &a, const double &b,const double &c) :a(a), b(b), c(c), Speed(){};

int LogSpeed::getSpeed() {
    double t = static_cast<double> (clock() - start_time) / CLOCKS_PER_SEC;
    return static_cast<int>(round(a*log(b*t)+c));
}

PowSpeed::PowSpeed(const double &a, const double &b, const double &c) :a(a), b(b), c(c), Speed(){};

int PowSpeed::getSpeed() {
    double t = static_cast<double> (clock() - start_time) / CLOCKS_PER_SEC;
    return static_cast<int>(c*round(pow(a*t,b)));
}



Sigmoid::Sigmoid(const double &a, const double &b) :a(a), b(b) {};

double Sigmoid::getPenalty() {
    double t = static_cast<double> (clock() - start_time) / CLOCKS_PER_SEC;
    return 1/(1+exp(-a*t+b));
}

auto uniform = [](int v){return v;};







