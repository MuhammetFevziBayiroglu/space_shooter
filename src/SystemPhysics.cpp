#include "SystemPhysics.hpp"

#include "Components.hpp"
#include "Events.hpp"

using namespace ss;

void SystemPhysics::BeginContact(b2Contact* contact){

    b2Fixture* fixtureA = NULL;
    b2Fixture* fixtureB = NULL;

    b2Body* bodyA = NULL;
    b2Body* bodyB = NULL;

    fixtureA = contact->GetFixtureA();
    if(!fixtureA)
        throw "Begin Contact: Could not get the address of the fixture.";
    fixtureB = contact->GetFixtureB();
    if(!fixtureB)
        throw "Begin Contact: Could not get the address of the fixture.";

    bodyA = fixtureA->GetBody();
    if(!bodyA)
        throw "Begin Contact: Could not get the address of the body.";
    bodyB = fixtureB->GetBody();
    if(!bodyB)
        throw "Begin Contact: Could not get the address of the body.";

    entityx::Entity entityA = *(entityx::Entity*)(bodyA->GetUserData());
    entityx::Entity entityB = *(entityx::Entity*)(bodyB->GetUserData());

    Entityx.events.emit<EventCollision>(entityA, entityB);
}

void SystemPhysics::EndContact(b2Contact* contact){
    
    b2Fixture* fixtureA = NULL;
    b2Fixture* fixtureB = NULL;

    b2Body* bodyA = NULL;
    b2Body* bodyB = NULL;

    fixtureA = contact->GetFixtureA();
    if(!fixtureA)
        throw "Begin Contact: Could not get the address of the fixture.";
    fixtureB = contact->GetFixtureB();
    if(!fixtureB)
        throw "Begin Contact: Could not get the address of the fixture.";

    bodyA = fixtureA->GetBody();
    if(!bodyA)
        throw "Begin Contact: Could not get the address of the body.";
    bodyB = fixtureB->GetBody();
    if(!bodyB)
        throw "Begin Contact: Could not get the address of the body.";

    entityx::Entity entityA = *(entityx::Entity*)(bodyA->GetUserData());
    entityx::Entity entityB = *(entityx::Entity*)(bodyB->GetUserData());
            
    Entityx.events.emit<EventCollisionEnd>(entityA, entityB);
}

void SystemPhysics::update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt){
    World.Step(dt, 8, 3);
}


