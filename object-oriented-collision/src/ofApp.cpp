#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    ofHideCursor();
    
    // copy construct Circle with 30px radius
    circle = Circle(0, 0, 30);
    
    // generate rectangles in random locations
    // but snap to grid!
    for (int i = 0; i < NUM_RECTS; i++) {
      float x = int(ofRandom(50,ofGetWidth()-50)/50) * 50;
      float y = int(ofRandom(50,ofGetHeight()-50)/50) * 50;
      rects.emplace_back(Rectangle(x,y, 50,50));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // go through all rectangles...
    for (auto& r : rects) {
      r.checkCollision(circle);  // check for collision
      r.display();               // and draw
    }

    // update circle’s position and draw
    circle.update(ofGetMouseX(), ofGetMouseY());
    circle.display();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
