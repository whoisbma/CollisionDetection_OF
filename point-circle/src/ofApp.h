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
    
        inline bool pointCircle(float px, float py, float cx, float cy, float r) {
            float distX = px - cx;
            float distY = py - cy;
            float distance = sqrt((distX * distX) + (distY * distY));
            if (distance <= r) {
                return true;
            }
            return false;
        }
    
        float px = 0;
        float py = 0;
        
        float cx = 300;
        float cy = 200;
        float radius = 100;
        
};
