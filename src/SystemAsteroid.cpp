#include "SystemAsteroid.hpp"

#include "Components.hpp"

#define RAD2DEG 57.29578049
#define DEG2RAD 0.01745329222
#define rand(max, min) (std::rand()%(max-min+1) + min)

using namespace ss;

void SystemAsteroid::update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt){

    if(Clock.getElapsedTime() - mPreviousTime < mPeriod)
        return;
    else
        mPreviousTime = Clock.getElapsedTime();

    auto entity = Entityx.entities.create();

    auto animation = entity.assign <ComponentAnimation> ();
    animation->AddSingleFrame("meteor" + std::to_string(rand(6, 4)) + ".png");
    auto sprite = animation->GetSprite();

    auto playerPosition = b2Vec2(0, 0);

    if(Player.valid())
        playerPosition = Player.component <ComponentPhysics>()->mBody->GetPosition();
    
    auto asteroidPosition = b2Vec2(0, 0);
    auto asteroidSpeed = b2Vec2(0, 0);
    auto windowSize = Window.getSize();

    auto radius = (windowSize.x > windowSize.y) ? windowSize.x:windowSize.y;
    radius *= ScaleP2M;
    radius = rand(radius * 2, radius);
    radius *= 8;

    auto angle = rand(360, 0) * DEG2RAD;

    asteroidPosition.x = std::cos(angle) * radius;
    asteroidPosition.y = std::sin(angle) * radius;

    asteroidPosition = asteroidPosition + playerPosition;
    
    auto sign = pow(-1, rand(10, 0));
    asteroidSpeed = playerPosition - asteroidPosition;
    asteroidSpeed.x *= 1 + sign * rand(50, 20) / 100;
    asteroidSpeed.y *= 1 + sign * rand(50, 20) / 100;
    
    auto length = asteroidSpeed.Length();
    asteroidSpeed *= 1/length;
    asteroidSpeed *= 0.1f;

    std::vector <b2FixtureDef> fixtureDef(1);
    b2BodyDef bodyDef;

    bodyDef.linearVelocity = asteroidSpeed;
    bodyDef.position = asteroidPosition;
    bodyDef.type = b2_dynamicBody;
    bodyDef.active = true;

    b2CircleShape circle;
    circle.m_radius = sprite.getTextureRect().width * 0.4 * ScaleP2M;
    fixtureDef[0].shape = &circle;
    // fixtureDef[0].density = 200;

    auto physics = entity.assign <ComponentPhysics> (entity, bodyDef, fixtureDef);
    physics->mBody->SetTransform(asteroidPosition, rand(359, 0) * DEG2RAD);

    auto hp = entity.assign <ComponentHitpoints> (1000);
    auto damage = entity.assign <ComponentDamage> (20);
    // std::cout << "\ncircle's radius: " << circle.m_radius;
    // std::cout << "\nx: " << std::setw(5) << asteroidSpeed.x << " y: " << std::setw(5) << asteroidSpeed.y;
    // std::cout << "\nx: " << std::setw(5) << playerPosition.x << " y: " << std::setw(5) << playerPosition.y;
    // std::cout << "\nx: " << std::setw(5) << asteroidPosition.x << " y: " << std::setw(5) << asteroidPosition.y;
    // std::cout << "\nx: " << std::setw(5) << playerPosition.x << " y: " << std::setw(5) << playerPosition.y;
}
