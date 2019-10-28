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
    
    float cx = 0;    // position of the circle
    float cy = 0;
    float r =  30;   // circle's radius
    
    std::vector<glm::vec2> vertices =
    {
        glm::vec2(200, 100),
        glm::vec2(400, 100),
        glm::vec2(350, 300),
        glm::vec2(250, 300)
    };
    
    ofPath shape;
    
    inline bool polyCircle(const std::vector<glm::vec2>& vertices, float cx, float cy, float r)
    {
        // go through each of the vertices, plus the next vertex in the list
        int next = 0;
        for (int current = 0; current < vertices.size(); current++) {
            // get next vertex in list
            // if we've hit the end, wrap around to 0
            next = current+1;
            if (next == vertices.size()) {
                next = 0;
            }
            
            // get the vectors at our current position
            // this makes our if statement a little cleaner
            glm::vec2 vc = vertices[current];    // c for "current"
            glm::vec2 vn = vertices[next];       // n for "next"
            
            // check for collision between the circle and
            // a line formed between the two vertices
            bool collision = lineCircle(vc.x, vc.y, vn.x, vn.y, cx, cy, r);
            if (collision) {
                return true;
            }
            
            // the above algorithm only checks if the circle
            // is touching the edges of the polygon – in most
            // cases this is enough, but you can un-comment the
            // following code to also test if the center of the
            // circle is inside the polygon

            // bool centerInside = polyPoint(vertices, cx,cy);
            // if (centerInside) return true;

        }
        // otherwise, after all that, return false
        return false;
    }
		
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
        float closestX = x1 + (dot * (x2-x1));
        float closestY = y1 + (dot * (y2-y1));
        
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
    
    // only needed if you're going to check if the circle is INSIDE the polygon
    inline bool polyPoint(const std::vector<glm::vec2>& vertices, float px, float py)
    {
        bool collision = false;
        
        // go through each of the vertices, plus the next vertex in the list
        int next = 0;
        for (int current = 0; current < vertices.size(); current++) {
            // get next vertex in list
            // if we've hit the end, wrap around to 0
            
            next = current + 1;
            if (next == vertices.size()) {
                next = 0;
            }
            
            // get the vectors at our current position
            // this makes the if statement a little cleaner
            glm::vec2 vc = vertices[current];
            glm::vec2 vn = vertices[next];
                
            // compare position, flip collision variable
            if (((vc.y >= py && vn.y < py) || (vc.y < py && vn.y >= py)) &&
                 (px < (vn.x-vc.x)*(py-vc.y) / (vn.y-vc.y)+vc.x)) {
                    collision = !collision;
            }
        }
                
        return collision;
    }
};
