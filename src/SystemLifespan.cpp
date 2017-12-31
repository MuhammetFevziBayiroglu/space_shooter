#include "SystemLifespan.hpp"

#include "Components.hpp"

using namespace ss;

void SystemLifespan::update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt){
    entityx::ComponentHandle <ComponentLifespan> lifespan;
    
    for(entityx::Entity entity: entities.entities_with_components(lifespan)){
        if(entity.has_component<ComponentControl>())
            continue;
        if(lifespan->mTimeLeft <= 0){
            if(entity.has_component <ComponentHitpoints>()){
                auto hp = entity.component <ComponentHitpoints> ();

                // If the object is not a laser beam (hp > 1)
                if(hp->mMax > 10){
                    auto explosion = Entityx.entities.create();
                    auto animation = explosion.assign <ComponentAnimation>();
                    animation->AddAnimation("explosion", false, 0.3);
        
                    // Gotta create predifined components and a few other constructors, doing things like this is pretty stupid!
                    for(auto& spriteVector: animation->mSprite){
                        for(auto& sprite: spriteVector){
                            auto pos = entity.component<ComponentAnimation>()->GetSprite().getPosition();
                            sprite.setPosition(pos);
                        }
                    }
       
                    // Did the object get destroyed by an external effect or did it die of natural causes 
                    if(hp->mRemaining <= 0){
                        mSound.play();
                    }

                    auto lifespan = explosion.assign <ComponentLifespan> (2.1);
                }
            }
            entity.destroy();
        }
        else 
            lifespan->mTimeLeft -= dt;        
    }

}
