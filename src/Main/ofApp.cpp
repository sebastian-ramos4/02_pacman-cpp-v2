#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofSetWindowTitle("C++ Game Box");
	//States
	menuState = new MenuState();
	choosePlayerState = new ChoosePlayerState();
	gameState = new GameState();
	gameStateBono = new GameStateBono();
	gameOverState = new GameOverState();
	pauseState = new PauseState();
	winState = new WinState();
	winStateBono = new WinStateBono();
	// Initial State
	currentState = menuState;
}

//--------------------------------------------------------------
void ofApp::update(){
	// State machine 
	if (currentState != nullptr){
		currentState->tick();
		if(currentState->hasFinished()){
			if(currentState->getNextState() == "Menu"){
				gameState = new GameState();
				currentState = menuState;
			}else if(currentState->getNextState() == "Choose"){
				currentState = choosePlayerState;
			}else if(currentState->getNextState() == "Game"){
				currentState = gameState;
			}else if(currentState->getNextState() == "GameStateBono"){
				currentState = gameStateBono;
			}else if(currentState->getNextState() == "over"){
				gameOverState->setScore(gameState->getFinalScore());
				currentState = gameOverState;
			}else if(currentState->getNextState() == "pause"){
				currentState = pauseState;
			}
			else if(currentState->getNextState() == "Win"){
				winState->setScore(gameState->getFinalScore());
				currentState = winState;
			}
			else if(currentState->getNextState() == "WinBono"){
				winState->setScore(gameState->getFinalScore());
				currentState = winStateBono;
			}
			else if(currentState->getNextState() == "NewGame"){
				gameState = new GameState();
				currentState = gameState;
				
			}
			currentState->reset();
		}
	}
		
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr)
		currentState->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr){
		currentState->keyPressed(key);
	}
	//Turn Volume Down (Mute)	
	if( key == '-' ){
		ofSoundSetVolume(0);
	}
	
	//Turn Volume Back Up
	if( key == '=' ){
		ofSoundSetVolume(1);
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}
