#include "PauseState.h"

PauseState::PauseState() {
	ResumeButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2, 64, 50, "resume");
    QuitButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2-170, 60, 50, "quit");

}
void PauseState::tick() {
    ResumeButton->tick();
    QuitButton->tick();
	if(ResumeButton->wasPressed()){
		cout << "Pressed";
		setNextState("Game");
		setFinished(true);

	}
	if(QuitButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);
		
	}
}
void PauseState::render() {
    string title = "Little Breather";
	ofDrawBitmapString(title, ofGetWidth()/2-4*title.size(), ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	ResumeButton->render();
	QuitButton->render();

}

void PauseState::keyPressed(int key){
	
}

void PauseState::mousePressed(int x, int y, int button){
	ResumeButton->mousePressed(x, y);
    QuitButton->mousePressed(x, y);
}

void PauseState::reset(){
	setFinished(false);
	setNextState("");
	ResumeButton->reset();
    QuitButton->reset();
}

PauseState::~PauseState(){
    delete ResumeButton;
    delete QuitButton;
	delete anim;
}