#include "GameState.h"
#include "Entity.h"

GameState::GameState() {
	music.load("music/pacman_chomp.wav");
	//Phase 1: New Map = Change map from 1 to 2
	mapImage.load("images/map2.png");
	map = MapBuilder().createMap(mapImage);
}
void GameState::tick() {
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
		setNextState("Win");
		finalScore = map->getPlayer()->getScore();
	}
}
void GameState::render() {
	map->render();
}

void GameState::keyPressed(int key){
	map->keyPressed(key);
	//Change to Pause State
	if( key == 'p' ){
		setNextState("pause");
		setFinished(true);
	}
	if(key == 'y'){
		setNextState("Win");
		setFinished(true);
		finalScore = map->getPlayer()->getScore();
	}
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}

int GameState::getFinalScore(){
	return finalScore;
}

GameState::~GameState(){
	delete map;
}