#pragma once

#include "Game.hpp"

namespace ss{
    struct SystemHitpoints: public entityx::System <SystemHitpoints>{
        void update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt);
    };
}
