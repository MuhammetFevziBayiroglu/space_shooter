#pragma once

#include "Game.hpp"

namespace ss{
    struct ComponentParallax{
        sf::Sprite mSprite;
        
        float mSpeedScale;
        b2Vec2 mSpeed;

        ComponentParallax(){
            mSprite.setTextureRect(sf::IntRect(0, 0, Window.getSize().x, Window.getSize().y));
        }
        ComponentParallax(float speedScale): mSpeedScale(speedScale){
            mSprite.setTextureRect(sf::IntRect(0, 0, Window.getSize().x, Window.getSize().y));
        }
    };
}
