#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    float x1 = 0;      // points for line (controlled by mouse)
    float y1 = 0;
    float x2 = 0;      // static point
    float y2 = 0;

    float sx = 200;    // square position
    float sy = 100;
    float sw = 200;    // and size
    float sh = 200;
    
    float intersectionX = 0;
    float intersectionY = 0;
    
    inline bool lineRect(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh)
    {
        // check if the line has hit any of the rectangle's sides
        bool left =   lineLine(x1,y1,x2,y2, rx,ry,rx, ry+rh);
        bool right =  lineLine(x1,y1,x2,y2, rx+rw,ry, rx+rw,ry+rh);
        bool top =    lineLine(x1,y1,x2,y2, rx,ry, rx+rw,ry);
        bool bottom = lineLine(x1,y1,x2,y2, rx,ry+rh, rx+rw,ry+rh);
        return (left || right || top || bottom);
    }
    
    inline bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
    {
        // calculate the distance to intersection point:
        float uA = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
        float uB = ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
        
        // if uA and uB are between 0-1, lines are colliding
        if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
            intersectionX = x1 + (uA * (x2-x1));
            intersectionY = y1 + (uA * (y2-y1));
            return true;
        }
        
        return false;
    }
};
