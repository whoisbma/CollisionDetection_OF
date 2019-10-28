#include "Rectangle.h"
#include "ofMain.h"
#include "ofApp.h"

Rectangle::Rectangle(float _x, float _y, float _w, float _h) :
    x(_x),
    y(_y),
    w(_w),
    h(_h)
{}

void Rectangle::checkCollision(const Circle& c)
{
    hit = ofApp::circleRect(c.x, c.y, c.r, x, y, w, h);
}

void Rectangle::display()
{
    if (hit) {
        ofSetColor(255,150,0);
    } else {
        ofSetColor(0,150,255);
    }
    
    ofDrawRectangle(x,y, w,h);
}
