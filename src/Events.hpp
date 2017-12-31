#pragma once

#include "Game.hpp"

namespace ss{
    struct EventCollision{
        entityx::Entity mEntityA;
        entityx::Entity mEntityB;

        EventCollision(entityx::Entity entityA, entityx::Entity entityB): mEntityA(entityA), mEntityB(entityB){
        }
    };

    struct EventCollisionEnd{
        entityx::Entity mEntityA;
        entityx::Entity mEntityB;

        EventCollisionEnd(entityx::Entity entityA, entityx::Entity entityB): mEntityA(entityA), mEntityB(entityB){
        }
    };
}
