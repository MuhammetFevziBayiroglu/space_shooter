#include "SystemDisplay.hpp"

#include "Components.hpp"

#define RAD2DEG 57.29578049
#define DEG2RAD 0.01745329222

using namespace ss;

void SystemDisplay::update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt){

    if(!Player.valid())
        throw std::string("\nPlayer not initialised");

    auto playerPosition = Player.component <ComponentPhysics>()->mBody->GetPosition();
    playerPosition *= ScaleM2P;

    // auto playerAngle = Player.component <ComponentPhysics>()->mBody->GetAngle() * RAD2DEG;

    entityx::ComponentHandle <ComponentAnimation> animation;
    entityx::ComponentHandle <ComponentParallax> parallax;

    Window.clear(sf::Color(20, 20, 40));

    Window.setView(mViewParallax);
    for(entityx::Entity entity: entities.entities_with_components(parallax)){
        Window.draw(parallax->mSprite);
    }

    mViewAnimation.setCenter(playerPosition.x, playerPosition.y);
    Window.setView(mViewAnimation);
    for(entityx::Entity entity: entities.entities_with_components(animation)){
        Window.draw(animation->GetSprite());
    }
    
    Window.display();
}
