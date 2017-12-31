#pragma once

#include "Game.hpp"

namespace ss{
    struct ComponentControl{
        bool mUp = false, 
             mDown = false,
             mLeft = false,
             mRight = false,
             mJump = false,
             mAttack = false;

        sf::Time mPreviousTime;
    };
}
