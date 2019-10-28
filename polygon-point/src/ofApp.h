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
		
    float px = 0;
    float py = 0;
    
    std::vector<glm::vec2> vertices =
    {
        glm::vec2(200, 100),
        glm::vec2(400, 130),
        glm::vec2(350, 300),
        glm::vec2(250, 300)
    };
    
    ofPath shape;
    
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
