#include "WinState.h"
#include "GameState.h"

WinState::WinState() {
	PlayAgainButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2, 64, 50, "Play again");
  	QuitButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2-170, 60, 50, "quit");
	NextLevelButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2+170, 60, 50, "NextLevel"); 
}
void WinState::tick() {
	PlayAgainButton->tick();
  	QuitButton->tick();
	if(PlayAgainButton->wasPressed()){
		setNextState("NewGame");
		setFinished(true);

	}
    if(QuitButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
	if(NextLevelButton->wasPressed()){
		setNextState("GameStateBono");
		setFinished(true);
	}
}
void WinState::render() {
	ofDrawBitmapString("Score: " + to_string(score), ofGetWidth()/2, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	PlayAgainButton->render();
  	QuitButton->render();
	NextLevelButton->render();
}

void WinState::keyPressed(int key){
	
}

void WinState::mousePressed(int x, int y, int button){
	PlayAgainButton->mousePressed(x, y);
  	QuitButton->mousePressed(x, y);
	NextLevelButton->mousePressed(x, y);
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
	PlayAgainButton->reset();
  	QuitButton->reset();
	NextLevelButton->reset();
}

void WinState::setScore(int sc){
    score = sc;
}

WinState::~WinState(){
	delete PlayAgainButton;
  	delete QuitButton;
	delete NextLevelButton;
}