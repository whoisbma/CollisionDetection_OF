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
		
        /*
        Is the RIGHT edge of r1 to the RIGHT of the LEFT edge of r2?
        Is the LEFT edge of r1 to the LEFT of the RIGHT edge of r2?
        Is the BOTTOM edge of r1 BELOW the TOP edge of r2?
        Is the TOP edge of r1 ABOVE the BOTTOM edge of r2?
        */
    
        inline bool rectRect(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h) {
            // are the sides of one rectangle touching the other?

            if (r1x + r1w >= r2x &&    // r1 right edge past r2 left
                r1x <= r2x + r2w &&    // r1 left edge past r2 right
                r1y + r1h >= r2y &&    // r1 top edge past r2 bottom
                r1y <= r2y + r2h) {    // r1 bottom edge past r2 top
                  return true;
            }
            return false;
        }
    
    float s1x = 0;
    float s1y = 0;
    float s1w = 30;
    float s1h = 30;
    
    float s2x = 200;
    float s2y = 100;
    float s2w = 200;
    float s2h = 200;

};
