//
//  Circle.cpp
//  object-oriented-collision
//
//  Created by Bryan Ma on 10/27/19.
//

#include "Circle.h"
#include "ofMain.h"

Circle::Circle() :
    x(0),
    y(0),
    r(0)
{}

Circle::Circle(float _x, float _y, float _r) :
    x(_x),
    y(_y),
    r(_r)
{}

void Circle::update(float _x, float _y)
{
    x = _x;
    y = _y;
}

void Circle::display()
{
    ofSetColor(0, 150);
    ofDrawCircle(x, y, r);
}
