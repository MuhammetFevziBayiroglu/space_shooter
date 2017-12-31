#pragma once

#include "Game.hpp"

namespace ss{
    class SystemLifespan: public entityx::System<SystemLifespan>{
        
        std::list <entityx::Entity> mDestroyList;
        sf::SoundBuffer mSoundBuffer;
        sf::Sound mSound;

        public:
            SystemLifespan(){
                if(!mSoundBuffer.loadFromFile("../data/Explosion+1.wav")){
                    throw (std::string) "\nCan't load sound '../data/Explosion+1.wav'";
                }
                mSound.setBuffer(mSoundBuffer);
            }
            void update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt);
    };
}
