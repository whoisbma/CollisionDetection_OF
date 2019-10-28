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
    
        inline bool circleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh) {
            // temporary variables to set edges for testing
            float testX = cx;
            float testY = cy;
            
            // which edge is closest?
            if (cx < rx)            testX = rx;
            else if (cx > rx+rw)    testX = rx+rw;
            
            if (cy < ry)            testY = ry;
            else if (cy > ry+rh)    testY = ry+rh;
            
            // ofDrawLine(cx, cy, testX, testY);
            
            // get distance from closest edges
            float distX = cx - testX;
            float distY = cy - testY;
            float distance = sqrt((distX * distX) + (distY * distY));
            
            // if the distance is less than the radius, collision
            if (distance <= radius) {
                return true;
            }
            return false;
        }
    
        float cx = 0;      // circle position (set with mouse)
        float cy = 0;
        float r = 30;      // circle radius

        float sx = 200;    // square position
        float sy = 100;
        float sw = 200;    // and dimensions
        float sh = 200;
		
};
