#pragma once

#include "Game.hpp"

namespace ss{
    struct ComponentLifespan: public entityx::Component <ComponentLifespan> {
        entityx::TimeDelta mTimeLeft = 0;

        ComponentLifespan(){
        }
        ComponentLifespan(entityx::TimeDelta timeLeft): mTimeLeft(timeLeft){
        }
    };
}
