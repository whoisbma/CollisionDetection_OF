#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    ofSetLineWidth(5);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // check for collision
    // if hit, change line's stroke color
    ofSetLineWidth(5);
    bool hit = lineCircle(x1,y1, x2,y2, cx,cy,r);
    if (hit) {
        ofSetColor(255,150,0, 150);
    } else {
        ofSetColor(0,150,255, 150);
    }
    ofDrawLine(x1,y1, x2,y2);

    // draw the circle
    ofSetLineWidth(1);
    ofSetColor(0, 150);
    ofDrawCircle(cx, cy, r);
    
    // optionally, draw a circle at the closest
    // point on the line
    ofSetColor(255,0,0);
    ofDrawCircle(closestX, closestY, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    cx = x;
    cy = y;
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
