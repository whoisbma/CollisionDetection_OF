#pragma once
#include "Circle.h"

class Rectangle
{
public:
    Rectangle(float _x, float _y, float _w, float _h);

    void display();
    void checkCollision(const Circle& c);
        
    float x, y;
    float w, h;
    bool hit{false};
};
