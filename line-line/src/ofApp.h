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
		
    float x1 = 0;    // line controlled by mouse
    float y1 = 0;
    float x2 = 10;   // fixed end
    float y2 = 10;

    float x3 = 100;  // static line
    float y3 = 300;
    float x4 = 500;
    float y4 = 100;
    
    float intersectionX = 0;
    float intersectionY = 0;
    
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
