#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    ofHideCursor();
    
    // set position of the pentagon's vertices
    float angle = TWO_PI / PENTAGON_NUM_VERTICES;
    for (int i=0; i < PENTAGON_NUM_VERTICES; i++) {
        float a = angle * i;
        float x = 300 + cos(a) * 100;
        float y = 200 + sin(a) * 100;
        pentagon.emplace_back(glm::vec2(x,y));
    }
    
    for (auto& v : pentagon) {
        shape1.lineTo(v);
    }
    shape1.close();

    // and create the random polygon
    float a = 0;
    int i = 0;
    while (a < 360) {
        float x = cos(ofDegToRad(a)) * ofRandom(30,50);
        float y = sin(ofDegToRad(a)) * ofRandom(30,50);
        randomPoly.emplace_back(glm::vec2(x,y));
        a += ofRandom(15, 40);
        i += 1;
    }
    
    for (auto& v : randomPoly) {
        shape2.lineTo(v);
    }
    shape2.close();
}

//--------------------------------------------------------------
void ofApp::update(){
    // update random polygon to mouse position
    glm::vec2 diff = mouse - randomPoly[0];
    for (auto& v : randomPoly) {
        v += diff;
    }
    
    // update shape with new vertices
    shape2.clear();
    for (auto& v : randomPoly) {
        shape2.lineTo(v);
    }
    shape2.close();
}

//--------------------------------------------------------------
void ofApp::draw(){
    // check for collision
    // if hit, change fill color
    bool hit = polyPoly(pentagon, randomPoly);
    if (hit) shape1.setColor(ofColor(255,150,0));
    else shape1.setColor(ofColor(0,150,255));

    // draw the pentagon
    shape1.draw();

    // draw the random polygon
    shape2.setColor(ofColor(0, 150));
    shape2.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouse = glm::vec2(x, y);
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
