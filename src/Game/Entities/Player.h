#pragma once

#include "Animation.h"
#include "EntityManager.h"
#include "MenuState.h"

enum MOVING {
	MUP,
	MDOWN,
	MLEFT,
	MRIGHT,
};
class Player: public Entity{

    private:
        int spawnX, spawnY;
        unsigned int health=3;
        int score=0;
        bool canMoveUp, canMoveDown, canMoveRight, canMoveLeft;
        int speed = 4;
        bool walking = false;
        //Phase 2: Choose Player State
        bool yellow;
        bool Teletransport = false;
        string imagePath;
        MOVING moving;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;
        MenuState* menustate;

    public:
        Player(int, int, int , int, EntityManager*,const std::string&); //Add image file
        ~Player();
        int getHealth();
        int getScore();
        FACING getFacing();
        void setHealth(int);
        void setScore(int);
        void setFacing(FACING facing);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void checkCollisions();
        void die();
        bool getTeletransport();
        void setTeletransport(bool);
};