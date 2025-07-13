#pragma once

#include "EntityManager.h"

class GhostSpawner: public Entity{
    public:
        GhostSpawner(int, int, int , int, EntityManager*, ofImage);
        void spawnGhost(string);
        void keyPressed(int);
        void tick();
        std::vector<string> colors = {"red", "pink", "cyan", "orange"}; //Phase 1: Colored Ghosts - Declare vector for Ghost colors 
    private:
        EntityManager* em;
        int spawnCounter = 30*5;
        int randomnum; 
};