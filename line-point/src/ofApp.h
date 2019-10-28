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
		
    
    float px = 0;
    float py = 0;
    
    float x1 = 100;
    float y1 = 300;
    float x2 = 500;
    float y2 = 100;
    
    inline bool linePoint(float x1, float y1, float x2, float y2, float px, float py)
    {
        // get the distance from the point to the two ends of the line
        float d1 = ofDist(px, py, x1, y1);
        float d2 = ofDist(px, py, x2, y2);
        
        // get the length of the line
        float lineLen = ofDist(x1, y1, x2, y2);
        
        // add a buffer - higher number = less accurate
        float buffer = 0.1f;
        
        // if the two distances are equal to the line's length, the point is on the line
        if (d1 + d2 >= lineLen - buffer && d1 + d2 <= lineLen + buffer) {
            return true;
        }
        return false;
    }
};
