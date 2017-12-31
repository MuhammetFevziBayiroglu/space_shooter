#include "SystemControl.hpp"

#include "Components.hpp"

#define RAD2DEG 57.29578049
#define DEG2RAD 0.01745329222

using namespace ss;

void SystemControl::update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt){

    auto control = Player.component<ComponentControl>();
    auto physics = Player.component<ComponentPhysics>();
    auto animation = Player.component<ComponentAnimation>();

    while(Window.pollEvent(mEvent)){
        if(mEvent.type == sf::Event::Closed)
            Window.close();
        
        bool pressed;
        if(mEvent.type == sf::Event::KeyPressed)
            pressed = true;
        else if(mEvent.type == sf::Event::KeyReleased){
            pressed = false;
        }

        switch(mEvent.key.code){
        case sf::Keyboard::D:
            control->mRight = pressed;
            break;
        case sf::Keyboard::A:
            control->mLeft = pressed;
            break;
        case sf::Keyboard::W:
            control->mUp = pressed;
            break;
        case sf::Keyboard::S:
            control->mDown = pressed;
            break;
        case sf::Keyboard::Space:
            control->mJump = pressed;
            break;
        case sf::Keyboard::Return:
            control->mAttack = pressed;
            break;
        }
    }

    b2Vec2 currentSpeed = physics->mBody->GetLinearVelocity();
    b2Vec2 targetSpeed = physics->mBody->GetLinearVelocity();

    auto playerPosition = Player.component <ComponentPhysics>()->mBody->GetPosition();
    auto angle = physics->mBody->GetAngle();
    auto velocityMax = 0.f;

    if(control->mUp ^ control->mDown){
        if(control->mUp)
            velocityMax = 1;
        else
            velocityMax = 0;
    }
    if(control->mRight ^ control->mLeft){
        if(control->mLeft)
            physics->mBody->SetTransform(playerPosition, angle - dt * DEG2RAD * 30);
        else if(control->mRight)
            physics->mBody->SetTransform(playerPosition, angle + dt * DEG2RAD * 30);
    }
    else {
        targetSpeed.x = 0;
    }

    targetSpeed.x = velocityMax * cos(angle - 90 * DEG2RAD);
    targetSpeed.y = velocityMax * sin(angle - 90 * DEG2RAD);
    
    auto impulse = targetSpeed - currentSpeed;
    impulse *= 0.01;
    physics->mBody->ApplyLinearImpulse(impulse, physics->mBody->GetWorldCenter(), true);

    if(control->mAttack){
        b2Vec2 velocityFire;

        velocityFire.x = 2 * cos(angle - 90 * DEG2RAD);
        velocityFire.y = 2 * sin(angle - 90 * DEG2RAD);

        // velocityFire += currentSpeed;
        
        b2Vec2 positionFire;

        auto textureRect = animation->GetSprite().getTextureRect();
        positionFire.x = playerPosition.x + textureRect.height * 0.8 * ScaleP2M * cos(angle - 90 * DEG2RAD);
        positionFire.y = playerPosition.y + textureRect.height * 0.8 * ScaleP2M * sin(angle - 90 * DEG2RAD);
        auto entity = entities.create();
        auto animation = entity.assign <ComponentAnimation> ();

        animation->AddSingleFrame("spaceLaserShot.png");

        auto physics = entity.assign <ComponentPhysics> (entity, animation->GetSprite().getGlobalBounds().width * (1/3) * ScaleP2M, positionFire);
        physics->mBody->SetLinearVelocity(velocityFire);
        physics->mBody->SetTransform(positionFire, angle);
        physics->mBody->SetBullet(true);
        auto damage = entity.assign <ComponentDamage> (1000);
        auto hp = entity.assign <ComponentHitpoints> (1);
        auto lifeSpan = entity.assign <ComponentLifespan> (3);

        control->mAttack = false;
    }

}
