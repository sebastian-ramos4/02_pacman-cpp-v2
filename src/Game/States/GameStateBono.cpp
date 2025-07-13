#include "GameStateBono.h"
#include "Entity.h"

GameStateBono::GameStateBono() {
	music.load("music/pacman_chomp.wav");
	//Phase 1: New Map = Change map from 1 to 2
	mapImage.load("images/CustomMap.png");
	map = MapBuilder().createMap(mapImage);
}
void GameStateBono::tick() {
	if(!music.isPlaying()){
			music.play();
	}
	map->tick();
	if(map->getPlayer()->getHealth() == 0){
		setFinished(true);
		setNextState("over");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setScore(0);
	}
	if(map->getDots() == 0) {
		setFinished(true);
		setNextState("WinBono");
		finalScore = map->getPlayer()->getScore();
	}
}
void GameStateBono::render() {
	map->render();
}

void GameStateBono::keyPressed(int key){
	map->keyPressed(key);
	//Change to Pause State
	if( key == 'p' ){
		setNextState("pause");
		setFinished(true);
	}
	if(key == 'y'){
		setNextState("WinBono");
		setFinished(true);
		finalScore = map->getPlayer()->getScore();
	}
}

void GameStateBono::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameStateBono::keyReleased(int key){
	map->keyReleased(key);
}

void GameStateBono::reset(){
	setFinished(false);
	setNextState("");
}

int GameStateBono::getFinalScore(){
	return finalScore;
}

GameStateBono::~GameStateBono(){
	delete map;
}