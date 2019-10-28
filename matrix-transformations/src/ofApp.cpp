#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    ofHideCursor();
    
    for (auto& v : square1) {
        shape1.lineTo(v);
    }
    shape1.close();
    
    for (auto& v : square2) {
        shape2.lineTo(v);
    }
    shape2.close();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // update rotation angle
    angle += 0.02;
    
    // move the origin to the position of the first square
    ofPushMatrix();
    ofTranslate(ofGetWidth()/3, ofGetHeight()/2);
    ofRotateRad(angle);
    
    // convert the square's four points to actual screen coords
    // after the matrix transform above
    std::vector<glm::vec2> square1Screen = pointsToScreenCoords(square1);
    
    // draw the square
    shape1.setColor(ofColor(0, 150));
    shape1.draw();
    ofPopMatrix();
    
    // move the origin to the position for the other square
    ofPushMatrix();
    ofTranslate(ofGetWidth()-ofGetWidth()/3, ofGetHeight()/2);
    ofRotateRad(angle);
    
    // get the screen coords for this shape too
    std::vector<glm::vec2> square2Screen = pointsToScreenCoords(square2);
    
    // check for collision, if hit, change color
    bool hit = polyPoly(square1Screen, square2Screen);
    if (hit) shape2.setColor(ofColor(255, 150, 0));
    else shape2.setColor(ofColor(0, 150, 255));
    
    // and draw this shape too
    shape2.draw();
    ofPopMatrix();
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
