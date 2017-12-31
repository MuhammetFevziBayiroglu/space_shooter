#pragma once

#include "Game.hpp"

namespace ss{
    class SystemControl: public entityx::System<SystemControl>{

        sf::Event mEvent;

        public:
        SystemControl(){
        }

        void update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt);
    };
}
