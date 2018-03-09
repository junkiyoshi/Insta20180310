#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	//ofBackground(39);
	//ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	ofSeedRandom(39);
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	float radius = 250;
	for (int i = 0; i < 512; i++) {

		float size = ofRandom(20.f);
		float deg = ofRandom(360.f) + ofGetFrameNum() * ofMap(size, 0, 20, 0.8, 0.15);
		float noise_value = ofMap(ofNoise(i * 0.5, ofGetFrameNum() * 0.005), 0, 1, 0.8, 1.2);
		float x = radius * noise_value * cos(deg * DEG_TO_RAD);
		float y = radius * noise_value * sin(deg * DEG_TO_RAD);
		ofPoint point = ofPoint(x, y);

		ofColor c;
		c.setHsb(i % 256, 239, 239);
		ofSetColor(c, 139);
		ofFill();
		ofDrawCircle(point, size);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}