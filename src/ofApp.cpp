#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    if (XML.load("settings.xml") ){
        ofLog() << "XML loaded" << endl;
    }
    
    else {
        // if nonexistent, create
        XML.addChild("SETTINGS");
        XML.setTo("SETTINGS");
    }
    
    
    if(XML.exists("//HOST")) {
        HOST = XML.getValue<string>("//HOST");
        ofLog() << "loaded HOST: " << ofToString(HOST) << endl;
    } else {
        HOST = "192.168.2.3";
    }
    
    if(XML.exists("//PORT")) {
        PORT = XML.getValue<int>("PORT");
        ofLog() << "loaded PORT: " << ofToString(PORT) << endl;
    } else {
        PORT = 9998;
    }
    
    
    if(XML.exists("//HOST2")) {
        HOST2 = XML.getValue<string>("//HOST2");
        ofLog() << "loaded HOST2: " << ofToString(HOST2) << endl;
    } else {
        HOST2 = "192.168.2.3";
    }
    
    if(XML.exists("//PORT2")) {
        PORT2 = XML.getValue<int>("PORT2");
        ofLog() << "loaded PORT2: " << ofToString(PORT2) << endl;
    } else {
        PORT2 = 9998;
    }
    
    
    sender.setup(HOST, PORT);
    sender2.setup(HOST2, PORT2);
    
    
    brightness = 255;
    prevBrightness = -1;
    ofBackground(brightness);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (prevBrightness != brightness){
        ofxOscMessage m;
        
        m.setAddress("/led");
        m.addIntArg(0);
        m.addIntArg(brightness);
        m.addIntArg(brightness);
        m.addIntArg(brightness);
        
        sender.sendMessage(m);
        sender2.sendMessage(m);
        
        prevBrightness = brightness;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(brightness);
    string stateString;
    if(brightness > 0){
        stateString = "LIGHT IS ON";
        ofSetColor(0);
    }
    else{
        stateString = "LIGHT IS OFF";
        ofSetColor(255);
    }
    
    ofDrawBitmapString(stateString, ofGetWidth()/2, ofGetHeight()/2);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch(key) {
        case ' ':
            
            if(brightness == 0){
                brightness = 255;
            }
            else {
                brightness = 0;
            }
            break;
    }
    
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
    if(brightness == 0){
        brightness = 255;
    }
    else {
        brightness = 0;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
