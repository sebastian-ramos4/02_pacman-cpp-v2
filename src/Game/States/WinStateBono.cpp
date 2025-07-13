#include "WinStateBono.h"
#include "GameState.h"

WinStateBono::WinStateBono() {
	PlayAgainButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2, 64, 50, "Play again from level 1");
  	QuitButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2-170, 60, 50, "quit");
}
void WinStateBono::tick() {
	PlayAgainButton->tick();
  	QuitButton->tick();
	if(PlayAgainButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
    if(QuitButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
}
void WinStateBono::render() {
	ofDrawBitmapString("Score: " + to_string(score), ofGetWidth()/2, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	PlayAgainButton->render();
  	QuitButton->render();
}

void WinStateBono::keyPressed(int key){
	
}

void WinStateBono::mousePressed(int x, int y, int button){
	PlayAgainButton->mousePressed(x, y);
  	QuitButton->mousePressed(x, y);
}

void WinStateBono::reset(){
	setFinished(false);
	setNextState("");
	PlayAgainButton->reset();
  	QuitButton->reset();
}

void WinStateBono::setScore(int sc){
    score = sc;
}

WinStateBono::~WinStateBono(){
	delete PlayAgainButton;
  	delete QuitButton;
}