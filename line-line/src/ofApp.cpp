#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofHideCursor();
    ofSetBackgroundColor(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    bool hit = lineLine(x1, y1, x2, y2, x3, y3, x4, y4);
    
    if (hit) {
        ofSetColor(255, 150, 0, 150);
    } else {
        ofSetColor(0, 150, 255, 150);
    }
    ofSetLineWidth(5);
    ofDrawLine(x3, y3, x4, y4);
    
    ofSetColor(0, 150);
    ofDrawLine(x1, y1, x2, y2);
    
    // optionally, draw a circle where the lines meet
    ofSetColor(255,0,0);
    ofSetLineWidth(1);
    ofDrawCircle(intersectionX,intersectionY, 10);
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
