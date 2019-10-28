#pragma once

class Circle
{
public:
    Circle();
    Circle(float _x, float _y, float _r);

    void update(float _x, float _y);
    void display();

    float x, y;
    float r;
};
