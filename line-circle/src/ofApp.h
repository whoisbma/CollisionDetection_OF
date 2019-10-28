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
    
        float cx = 0;      // circle position (set by mouse)
        float cy = 0;
        float r =  30;     // circle radius

        float x1 = 100;    // coordinates of line
        float y1 = 300;
        float x2 = 500;
        float y2 = 100;
    
    float closestX = 0;
    float closestY = 0;
    
    // line/circle
    inline bool lineCircle(float x1, float y1, float x2, float y2, float cx, float cy, float r)
    {
        // is either end inside the circle?
        bool inside1 = pointCircle(x1,y1, cx,cy,r);
        bool inside2 = pointCircle(x2,y2, cx,cy,r);
        if (inside1 || inside2) return true;
        
        // get length of the line
        float distX = x1 - x2;
        float distY = y1 - y2;
        float len = sqrt( (distX*distX) + (distY*distY) );
        
        // get dot product of the line and circle
        float dot = ( ((cx-x1)*(x2-x1)) + ((cy-y1)*(y2-y1)) ) / pow(len,2);
        
        // find the closest point on the line
        closestX = x1 + (dot * (x2-x1));
        closestY = y1 + (dot * (y2-y1));
        
        // is this point actually on the line segment?
        // if so keep going, but if not, return false
        bool onSegment = linePoint(x1,y1,x2,y2, closestX,closestY);
        if (!onSegment) {
            return false;
        }
        
        // get distance to closest point
        distX = closestX - cx;
        distY = closestY - cy;
        float distance = sqrt( (distX*distX) + (distY*distY) );
        
        return distance <= r;
    }
    
    // point/circle
    inline bool pointCircle(float px, float py, float cx, float cy, float r)
    {
        // get distance between the point and circle's center
        // using the Pythagorean Theorem
        float distX = px - cx;
        float distY = py - cy;
        float distance = sqrt( (distX*distX) + (distY*distY) );
        
        // if the distance is less than the circle's
        // radius the point is inside!
        if (distance <= r) {
          return true;
        }
        return false;
    }
    
    // line/point
    inline bool linePoint(float x1, float y1, float x2, float y2, float px, float py)
    {
        // get distance from the point to the two ends of the line
        float d1 = ofDist(px,py, x1,y1);
        float d2 = ofDist(px,py, x2,y2);
        
        // get the length of the line
        float lineLen = ofDist(x1,y1, x2,y2);
        
        // since floats are so minutely accurate, add
        // a little buffer zone that will give collision
        float buffer = 0.1;    // higher # = less accurate
        
        // if the two distances are equal to the line's
        // length, the point is on the line!
        // note we use the buffer here to give a range,
        // rather than one #
        if (d1+d2 >= lineLen-buffer && d1+d2 <= lineLen+buffer) {
          return true;
        }
        return false;
    }
};
