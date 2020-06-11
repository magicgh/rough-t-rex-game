//
// Created by magicgh on 5/25/2020.
//

#include "shape.h"


Point::Point() : x(0), y(0) {};

Point::Point(const Point &t) : x(t.x), y(t.y) {};

Point::Point(const int &x, const int &y) : x(x), y(y) {};

Rect::Rect() : position(Point()), length(Vec()) {};

Rect::Rect(const Point &position, const Vec &length) :
       position(position), length(length) {};

Rect::Rect(const Rect &t) :
        position(t.position), length(t.length) {};

Point operator+(const Point &a,const Point &b) {
    return Point(a.x+b.x,a.y+b.y);
}

Point operator-(const Point &a,const Point &b) {
    return Point(a.x-b.x,a.y-b.y);
}

Point & Point::operator=(const Point &t) {
    this->x =t.x, this->y=t.y;
    return *this;
}

Point Point::operator+=(const Point &t) {
    *this = *this +t;
    return *this;
}

Point Point::operator-=(const Point &t) {
    *this = *this -t;
    return *this;
}


void Rect::move(const Vec &direction) {
    this->position+=direction;
}




void Rect::set(const Point &position, const Vec &length) {
    this->position = position;
    this->length = length;
}

void Rect::setLen(const Vec &length) {
    this->length =length;
}

bool operator&(const Rect &a, const Rect &b) {
    return a.position.x + a.length.x > b.position.x &&
           b.position.x + b.length.x > a.position.x &&
           a.position.y + a.length.y > b.position.y &&
           b.position.y + b.length.y > a.position.y;
}