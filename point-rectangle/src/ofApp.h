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
    
        bool pointRect(float px, float py, float rx, float ry, float rw, float rh) {
            // is the point inside the rectangle's bounds?
            if (px >= rx &&         // right of the left edge AND
                px <= rx + rw &&    // left of the right edge AND
                py >= ry &&         // below the top AND
                py <= ry + rh) {    // above the bottom
                return true;
            }
            return false;
        }
            
        float px = 0;
        float py = 0;
        
        float sx = 200;
        float sy = 100;
        float sw = 200;
        float sh = 200;
        
};
