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
    
        inline bool circleCircle(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r) {
            // get distance between the circle's centers
            // use the pythagorean theorem to compute the distance
            float distX = c1x - c2x;
            float distY = c1y - c2y;
            float distance = sqrt((distX * distX) + (distY * distY));
            
            // if the distance is less than the sum of the circle's radii,
            // the circles are touching
            if (distance <= c1r + c2r) {
                return true;
            }
            return false;
        }
        
        float c1x = 0;
        float c1y = 0;
        float c1r = 30;
        
        float c2x = 300;
        float c2y = 200;
        float c2r = 100;
		
};
