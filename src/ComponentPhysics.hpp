#pragma once

#include "Game.hpp"

namespace ss{
    struct ComponentPhysics{
        entityx::Entity mEntity;

        b2BodyDef mBodyDef;
        std::vector <b2FixtureDef> mFixtureDef;

        b2Body* mBody = NULL;
        std::vector <b2Fixture*> mFixture;

        ComponentPhysics(){}

        ComponentPhysics(entityx::Entity& entity, float radius, b2Vec2 position = b2Vec2(0, 0)){
            mEntity = entity;

            b2CircleShape circle;
            circle.m_radius = radius;
            circle.m_p = b2Vec2(0, 0);

            mBodyDef.position = position;
            mBodyDef.type = b2_dynamicBody;
            mBodyDef.userData = (void*) &mEntity;

            b2FixtureDef fixtureDef;
            fixtureDef.shape = &circle;
            fixtureDef.restitution = 0;
            fixtureDef.friction = 0;
            mFixtureDef.push_back(fixtureDef);

            mBody = World.CreateBody(&mBodyDef);

            mBody->SetUserData((void*) &mEntity);

            for(b2FixtureDef fd: mFixtureDef){
                mFixture.push_back(mBody->CreateFixture(&fd));
            }
        }
        
        ComponentPhysics(entityx::Entity& entity, float width, float height, b2Vec2 position){
            mEntity = entity;

            b2PolygonShape shape;
            shape.SetAsBox(width/2, height/2);

            mBodyDef.position = position;
            mBodyDef.type = b2_dynamicBody;
            mBodyDef.userData = (void*) &mEntity;

            b2FixtureDef fixtureDef;
            fixtureDef.shape = &shape;
            fixtureDef.restitution = 0;
            fixtureDef.friction = 0;
            mFixtureDef.push_back(fixtureDef);

            mBody = World.CreateBody(&mBodyDef);

            mBody->SetUserData((void*) &mEntity);

            for(b2FixtureDef fd: mFixtureDef){
                mFixture.push_back(mBody->CreateFixture(&fd));
            }
        }


        ComponentPhysics(const ComponentPhysics& componentPhysics){
            *this = componentPhysics; // Be careful when calling the copy assignment operator from the copy contstructor

            mBody = World.CreateBody(&mBodyDef);

            mBody->SetUserData((void*) &mEntity);
            
            mFixture.clear();
            for(b2FixtureDef fd: mFixtureDef){
                mFixture.push_back(mBody->CreateFixture(&fd));
            }
        }
        ComponentPhysics(entityx::Entity entity, b2BodyDef bodyDef, std::vector <b2FixtureDef> fixtureDef): mEntity(entity), mBodyDef(bodyDef), mFixtureDef(fixtureDef){
            mBody = World.CreateBody(&mBodyDef);

            mBody->SetUserData((void*) &mEntity);

            for(b2FixtureDef fd: mFixtureDef){
                mFixture.push_back(mBody->CreateFixture(&fd));
            }
        }

        ~ComponentPhysics(){
            for(b2Fixture* f: mFixture){
                mBody->DestroyFixture(f);
            }
            if(mBody)
                World.DestroyBody(mBody);
        }
    };

}
