#pragma once

#include "Game.hpp"

#include "Events.hpp"

namespace ss{
    class SystemEvent: public entityx::System <SystemEvent>, public entityx::Receiver <SystemEvent>{
        public:
            SystemEvent(){}
           
            void update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt);

            void receive(const EventCollision& collision);
            void receive(const EventCollisionEnd& collisionEnd);

            void configure(entityx::EventManager& eventManager){
                eventManager.subscribe <EventCollision> (*this);
                eventManager.subscribe <EventCollisionEnd> (*this);
            }

    };
}
