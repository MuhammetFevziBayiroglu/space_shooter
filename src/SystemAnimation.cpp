#include "SystemAnimation.hpp"

#include "Components.hpp"

#define RAD2DEG 57.29578049
#define DEG2RAD 0.01745329222

using namespace ss;

void SystemAnimation::update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt){
    entityx::ComponentHandle <ComponentAnimation> animation;
    entityx::ComponentHandle <ComponentPhysics> physics;
    
    for(auto entity: entities.entities_with_components(animation, physics)){
        auto position = physics->mBody->GetPosition();
        auto angle = physics->mBody->GetAngle() * RAD2DEG;
        position *= ScaleM2P;

        animation->GetSprite().setPosition(position.x, position.y);
        animation->GetSprite().setRotation(angle);
    }

    for(auto entity: entities.entities_with_components(animation)){
        auto row = animation->mRow;
        auto& column = animation->mColumn;
        auto& elapsedTime = animation->mElapsedTime;
        auto period = animation->mPeriod[row];
        auto isContinuous = animation->mIsContinuous[row];
        auto numberOfRows = animation->mSprite.size();
        auto numberOfColumns = animation->mSprite[row].size();

        if(numberOfRows == 1 && numberOfColumns == 1)
            continue;

        if(elapsedTime > period && column < numberOfColumns - 1){
            column++;
            if(isContinuous)
                column %= numberOfColumns;
            elapsedTime = 0;
        }
        else
            elapsedTime += dt;
    }
}
