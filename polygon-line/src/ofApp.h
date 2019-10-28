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
    
    float x1 = 0;    // line position (set by mouse)
    float y1 = 0;
    float x2 = 20;   // fixed end
    float y2 = 20;
    
    std::vector<glm::vec2> vertices;
		
    const int NUM_VERTICES = 16;
    
    ofPath shape;
    
    // POLYGON/LINE
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
    
    
};
