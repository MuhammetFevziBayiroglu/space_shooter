#include "SystemParallax.hpp"

#include "ComponentParallax.hpp"
#include "ComponentPhysics.hpp"

using namespace ss;

void SystemParallax::update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt){
    entityx::ComponentHandle <::ComponentParallax> parallax;

    b2Vec2 playerPosition = Player.component<ComponentPhysics>()->mBody->GetPosition();
    playerPosition *= ScaleM2P; // Convert from meters to pixels

    for(entityx::Entity entity: entities.entities_with_components(parallax)){
        auto parallaxRect = parallax->mSprite.getTextureRect();

        parallaxRect.left = playerPosition.x * parallax->mSpeedScale;
        parallaxRect.top = playerPosition.y * parallax->mSpeedScale;
        
        parallax->mSprite.setTextureRect(parallaxRect);
    }
}
