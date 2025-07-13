#pragma once
#include "Powerup.h"
#include "Player.h"

class ApplePowerup : public Powerup{
    public:
        void activate();
        void deactivate();
        ApplePowerup(Player *p);
        Player* p;
};