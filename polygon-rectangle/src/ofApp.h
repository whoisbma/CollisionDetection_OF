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
		
    float sx = 0;    // a square, controlled by the mouse
    float sy = 0;
    float sw = 30;   // width and height
    float sh = 30;
    
    std::vector<glm::vec2> vertices =
    {
        glm::vec2(100, 100),
        glm::vec2(400, 100),
        glm::vec2(500, 300),
        glm::vec2(200, 300)
    };

    ofPath shape;
    
    inline bool polyRect(const std::vector<glm::vec2>& vertices, float rx, float ry, float rw, float rh)
    {
        // go through each of the vertices, plus the next
        // vertex in the list
        int next = 0;
            
        for (int current=0; current<vertices.size(); current++) {

            // get next vertex in list
            // if we've hit the end, wrap around to 0
            next = current+1;
            if (next == vertices.size()){
                next = 0;
            }

            // get the PVectors at our current position
            // this makes our if statement a little cleaner
            glm::vec2 vc = vertices[current];    // c for "current"
            glm::vec2 vn = vertices[next];       // n for "next"

            // check against all four sides of the rectangle
            bool collision = lineRect(vc.x,vc.y,vn.x,vn.y, rx,ry,rw,rh);
            if (collision) {
                return true;
            }

            // optional: test if the rectangle is INSIDE the polygon
            // note that this iterates all sides of the polygon
            // again, so only use this if you need to
            bool inside = polyPoint(vertices, rx,ry);
            if (inside) {
                return true;
            }
        }
        return false;
    }
    
    inline bool lineRect(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh)
    {
        // check if the line has hit any of the rectangle's sides
        bool left =   lineLine(x1,y1,x2,y2, rx,ry,rx, ry+rh);
        bool right =  lineLine(x1,y1,x2,y2, rx+rw,ry, rx+rw,ry+rh);
        bool top =    lineLine(x1,y1,x2,y2, rx,ry, rx+rw,ry);
        bool bottom = lineLine(x1,y1,x2,y2, rx,ry+rh, rx+rw,ry+rh);
        return (left || right || top || bottom);
    }
    
    inline bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
    {
        // calculate the distance to intersection point:
        float uA = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
        float uB = ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
        
        // if uA and uB are between 0-1, lines are colliding
        if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
            float intersectionX = x1 + (uA * (x2-x1));
            float intersectionY = y1 + (uA * (y2-y1));
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
