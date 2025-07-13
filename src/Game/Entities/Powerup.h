#pragma once

#include "Entity.h"
#include "EntityManager.h"

enum powerup{
    APPLE,
    CHERRY,
    STRAWBERRYE,
    NA
};

class Powerup{
    private:

    public:
        EntityManager* fruit;
        virtual void active() = 0;
        virtual void powerup() = 0;
        
};
