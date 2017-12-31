#pragma once

#include "Game.hpp"

namespace ss{
    struct ComponentHitpoints: public entityx::Component <ComponentHitpoints> {
        float mRemaining;
        float mMax;

        ComponentHitpoints(){
        }
        ComponentHitpoints(int max): mMax(max), mRemaining(max){
        }
    };
}
