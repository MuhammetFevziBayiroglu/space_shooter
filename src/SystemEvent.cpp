
#include "SystemEvent.hpp"

#include "Components.hpp"

using namespace ss;

void SystemEvent::update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt){
}

void SystemEvent::receive(const EventCollision& collision){

    entityx::Entity entityA = collision.mEntityA;
    entityx::Entity entityB = collision.mEntityB;

    if(entityA.has_component <ComponentDamage> () && entityB.component <ComponentHitpoints> ()){
        entityB.component <ComponentHitpoints> ()->mRemaining -= entityA.component <ComponentDamage>()->mDamage;
    }
    if(entityB.has_component <ComponentDamage>() && entityA.has_component <ComponentHitpoints> ()){
        entityA.component <ComponentHitpoints> ()->mRemaining -= entityB.component <ComponentDamage>()->mDamage;
    }
}

void SystemEvent::receive(const EventCollisionEnd& collision){

    // entityx::Entity entityA = collision.mEntityA;
    // entityx::Entity entityB = collision.mEntityB;

    // if(entityA.has_component <ComponentDamage> () && entityB.component <ComponentHitpoints> ()){
    //     entityB.component <ComponentHitpoints> ()->mRemaining -= entityA.component <ComponentDamage>()->mDamage;
    // }
    // if(entityB.has_component <ComponentDamage>() && entityA.has_component <ComponentHitpoints> ()){
    //     entityA.component <ComponentHitpoints> ()->mRemaining -= entityB.component <ComponentDamage>()->mDamage;
    // }
}
