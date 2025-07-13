#pragma once
#include "Powerup.h"
#include "Player.h"

class CherryPowerup : public Powerup{
    public:
        void activate();
        void deactivate();
        CherryPowerup(Player *p);
        Player* p;
};
