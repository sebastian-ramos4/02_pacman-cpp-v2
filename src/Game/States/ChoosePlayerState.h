#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 

class ChoosePlayerState : public State {
private:
	ofImage img1;
	ofImage img2;
	Button *yellowPacmanButton;
	Button *greenPacmanButton;
	Animation* animyellow;
	Animation* animgreen;
	bool yellow = true;

public:
	ChoosePlayerState();
	~ChoosePlayerState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	void setPacmanColor(bool color);
	bool getPacmanColor();
};
