#pragma once

#include "Game.hpp"

namespace ss{
    class SystemAsteroid: public entityx::System <SystemAsteroid>{
        sf::Time mPreviousTime;
        sf::Time mPeriod;
        public:
            SystemAsteroid(){}
            SystemAsteroid(sf::Time period): mPeriod(period){}
            void update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt);
    };
}
