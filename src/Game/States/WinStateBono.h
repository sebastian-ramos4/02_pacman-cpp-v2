#pragma once

#include "State.h"
#include "Button.h"

class WinStateBono : public State {
private:
	ofImage img1;
	Button *PlayAgainButton;
    Button *QuitButton;
	int score=0;

public:
	WinStateBono();
	~WinStateBono();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	void setScore(int);
};