#pragma once
#include "Powerup.h"
#include "Player.h"

class StrawberryPowerup : public Powerup{
    public:
        void activate();
        void deactivate();
        StrawberryPowerup(Player *p);
        Player* p;
};
