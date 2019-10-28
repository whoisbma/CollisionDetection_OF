#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofHideCursor();
    ofSetBackgroundColor(255);
    
    // set position of the vertices - a regular polygon!
    // based on this example:
    // https://processing.org/examples/regularpolygon.html
    float angle = TWO_PI / NUM_VERTICES;
    for (int i = 0; i < NUM_VERTICES; i++) {
        float a = angle * i;
        float x = 300 + cos(a) * 100;
        float y = 200 + sin(a) * 100;
        vertices.emplace_back(glm::vec2(x,y));
    }
    
    for (auto& v : vertices) {
        shape.lineTo(v);
    }
    shape.close();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // check for collision
    // if hit, change fill color
    bool hit = polyLine(vertices, x1, y1, x2, y2);
    if (hit) {
        shape.setColor(ofColor(255, 150, 0));
    } else {
        shape.setColor(ofColor(0, 150, 255));
    }
    // draw the polygon
    ofSetLineWidth(1);
    shape.draw();

    // draw line
    ofSetLineWidth(5);
    ofSetColor(0, 150);
    ofDrawLine(x1, y1, x2, y2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    x1 = x;
    y1 = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
