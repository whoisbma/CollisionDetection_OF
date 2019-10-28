#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLineWidth(5);
    ofSetBackgroundColor(255);
    ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    bool hit = linePoint(x1,y1, x2,y2, px,py);
    if (hit) {
        ofSetColor(255, 150, 0, 150);
    } else {
        ofSetColor(0, 150, 255, 150);
    }
    
    ofDrawLine(x1, y1, x2, y2);
    
    ofFill();
    ofSetColor(0, 150);
    ofDrawCircle(px, py, 10);
    
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
