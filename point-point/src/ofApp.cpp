#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLineWidth(6);
    ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    bool colliding = pointPoint(px, py, targetX, targetY);
    
    if (colliding) {
        ofBackground(255, 150, 0);
    } else {
        ofBackground(255);
    }
    
    ofSetColor(0, 150, 255);
    ofDrawEllipse(targetX, targetY, 15, 15);
    
    ofSetColor(0);
    ofDrawEllipse(px, py, 15, 15);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    px = x;
    py = y;
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
