#pragma once

#include "Game.hpp"

namespace ss{
    class SystemAnimation: public entityx::System <SystemAnimation>{
        public:
            void update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt);
    };
}
