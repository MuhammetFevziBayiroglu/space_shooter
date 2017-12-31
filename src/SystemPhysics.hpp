#pragma once

#include "Game.hpp"

namespace ss{
    class SystemPhysics: public entityx::System <SystemPhysics>, public entityx::Receiver <SystemPhysics>, public b2ContactListener{

        void BeginContact(b2Contact* contact);
        void EndContact(b2Contact* contact);
        // void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse );

        public:
            SystemPhysics(){
                World.SetContactListener(this);
            }
            void update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt);
    };
}
