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
		
    std::vector<glm::vec2> pentagon;
    const int PENTAGON_NUM_VERTICES = 5;
    
    std::vector<glm::vec2> randomPoly;
    const int RANDOM_POLY_NUM_VERTICES = 8;
    
    ofPath shape1;
    ofPath shape2;
    
    glm::vec2 mouse{0,0};

    inline bool polyPoly(const std::vector<glm::vec2>& p1, const std::vector<glm::vec2>& p2)
    {
        // go through each of the vertices, plus the next
        // vertex in the list
        int next = 0;
        for (int current=0; current < p1.size(); current++) {

            // get next vertex in list
            // if we've hit the end, wrap around to 0
            next = current+1;
            if (next == p1.size()) next = 0;

            // get the vectors at our current position
            // this makes our if statement a little cleaner
            glm::vec2 vc = p1[current];    // c for "current"
            glm::vec2 vn = p1[next];       // n for "next"

            // now we can use these two points (a line) to compare
            // to the other polygon's vertices using polyLine()
            bool collision = polyLine(p2, vc.x,vc.y,vn.x,vn.y);
            if (collision) return true;

            // optional: check if the 2nd polygon is INSIDE the first
            collision = polyPoint(p1, p2[0].x, p2[0].y);
            if (collision) return true;
        }
        return false;
    }
    
    inline bool polyLine(const std::vector<glm::vec2>& vertices, float x1, float y1, float x2, float y2) {

      // go through each of the vertices, plus the next
      // vertex in the list
      int next = 0;
      for (int current=0; current<vertices.size(); current++) {

        // get next vertex in list
        // if we've hit the end, wrap around to 0
        next = current+1;
        if (next == vertices.size()) next = 0;

        // get the PVectors at our current position
        // extract X/Y coordinates from each
        float x3 = vertices[current].x;
        float y3 = vertices[current].y;
        float x4 = vertices[next].x;
        float y4 = vertices[next].y;

        // do a Line/Line comparison
        // if true, return 'true' immediately and
        // stop testing (faster)
        bool hit = lineLine(x1, y1, x2, y2, x3, y3, x4, y4);
        if (hit) {
          return true;
        }
      }

      // never got a hit
      return false;
    }


    // LINE/LINE
    inline bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {

      // calculate the direction of the lines
      float uA = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
      float uB = ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));

      // if uA and uB are between 0-1, lines are colliding
      if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
        return true;
      }
      return false;
    }
    
    // used only to check if the second polygon is INSIDE the first
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
