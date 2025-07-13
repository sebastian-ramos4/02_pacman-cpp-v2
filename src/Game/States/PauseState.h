#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 

class PauseState : public State {
private:
	
	Button *ResumeButton;
	Button *QuitButton;
	Animation* anim;

public:
	PauseState();
	~PauseState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};