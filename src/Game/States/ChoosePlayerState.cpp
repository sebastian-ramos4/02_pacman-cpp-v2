#include "ChoosePlayerState.h"

bool ChoosePlayerState::getPacmanColor(){
    return yellow;
}
void ChoosePlayerState::setPacmanColor(bool color){
	yellow = color;
}
ChoosePlayerState::ChoosePlayerState() {
	yellowPacmanButton = new Button(ofGetWidth()/2+200, ofGetHeight()/2, 64, 50, "Yellow Pacman");
	greenPacmanButton = new Button(ofGetWidth()/2-200, ofGetHeight()/2, 64, 50, "Green Pacman");
	//Animate Yellow pacman
	img1.load("images/pacman.png");
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<3; i++){
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
	animyellow = new Animation(10,rightAnimframes);

	//Animate Green pacman
	img2.load("images/Custompacman.png");
	vector<ofImage> leftAnimframes;
    ofImage temp2;
	for(int i=0; i<3; i++){
        temp2.cropFrom(img2, i*16, 0, 16, 16);
        leftAnimframes.push_back(temp2);
    }
	animgreen = new Animation(10,leftAnimframes);

}
void ChoosePlayerState::tick() {
	yellowPacmanButton->tick();
	greenPacmanButton->tick();
	animyellow->tick();
	animgreen->tick();
	if(yellowPacmanButton->wasPressed()){
		setPacmanColor(true);
		setNextState("Game");
		setFinished(true);

	}
	if(greenPacmanButton->wasPressed()){
		setPacmanColor(false);
		setNextState("Game");
		setFinished(true);

	}
}
void ChoosePlayerState::render() {
	string title = "Pacman Project";
	ofDrawBitmapString(title, ofGetWidth()/2-4*title.size(), ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	animyellow->getCurrentFrame().draw(ofGetWidth()/2+200, ofGetHeight()/2-100, 100, 100);
	animgreen->getCurrentFrame().draw(ofGetWidth()/2-200, ofGetHeight()/2-100, 100, 100);
	yellowPacmanButton->render();
	greenPacmanButton->render();


}

void ChoosePlayerState::keyPressed(int key){
	
}

void ChoosePlayerState::mousePressed(int x, int y, int button){
	yellowPacmanButton->mousePressed(x, y);
	greenPacmanButton->mousePressed(x, y);
}

void ChoosePlayerState::reset(){
	setFinished(false);
	setNextState("");
	yellowPacmanButton->reset();
	greenPacmanButton->reset();
}

ChoosePlayerState::~ChoosePlayerState(){
	delete yellowPacmanButton;
	delete greenPacmanButton;
	delete animyellow;
	delete animgreen;
}