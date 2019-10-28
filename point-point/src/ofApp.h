#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{

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
		
        inline bool pointPoint(int x1, int y1, int x2, int y2) {
            if (x1 == x2 && y1 == y2) {
                return true;
            }
            return false;
        }
    
        int px, py;
        int targetX = 300;
        int targetY = 200;
};
