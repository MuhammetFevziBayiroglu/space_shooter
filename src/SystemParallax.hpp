#pragma once

#include "Game.hpp"

namespace ss{
    class SystemParallax: public entityx::System<SystemParallax>{
        public:
            void update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt);
    };
}
