#pragma once

#include "State.h"
#include "Player.h"
#include "MapBuilder.h"

class GameStateBono: public State{
    public: 
        GameStateBono();
		~GameStateBono();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		int getFinalScore();
	
	private:
		ofSoundPlayer music;
		ofImage mapImage;
		Map* map;
		int finalScore=0;

};