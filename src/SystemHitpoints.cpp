#include "SystemHitpoints.hpp"

#include "ComponentHitpoints.hpp"
#include "ComponentLifespan.hpp"

using namespace ss;

void SystemHitpoints::update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt){
    entityx::ComponentHandle <ComponentHitpoints> hitpoints;

    for(entityx::Entity entity: entities.entities_with_components(hitpoints)){
        if(hitpoints->mRemaining <= 0){
            if(entity.has_component <ComponentLifespan>())
                entity.component<ComponentLifespan>()->mTimeLeft = 0;
            else 
                entity.assign <ComponentLifespan> (0);
        }
    }
}
