#pragma once 

#include "Game.hpp"

namespace ss{
    struct ComponentDamage{
        int mDamage = 0;
        ComponentDamage(){
        }
        ComponentDamage(int damage): mDamage(damage){
        }
    };
}
