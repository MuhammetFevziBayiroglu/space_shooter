#pragma once

#include "Game.hpp"

namespace ss{
    class SystemDisplay: public entityx::System<SystemDisplay>{
        sf::View mViewParallax;
        sf::View mViewAnimation;
        sf::View mViewUI;

        public:
            SystemDisplay(){
                mViewParallax.setViewport(sf::FloatRect(0, 0, 1, 1));
                mViewParallax.setSize(Window.getSize().x, Window.getSize().y);
                mViewParallax.setCenter(Window.getSize().x/2, Window.getSize().y/2);

                mViewAnimation.setViewport(sf::FloatRect(0, 0, 1, 1));
                mViewAnimation.setSize(Window.getSize().x, Window.getSize().y);
                mViewAnimation.zoom(7);
                // mViewAnimation.setCenter(Window.getSize().x/2, Window.getSize().y/2); // Set to player position every cycle

                mViewUI.setViewport(sf::FloatRect(0, 0, 1, 1));
                mViewUI.setSize(Window.getSize().x, Window.getSize().y);
                mViewUI.setCenter(0, 0);
            }
            void update(entityx::EntityManager& entities, entityx::EventManager& events, entityx::TimeDelta dt);
    };
}
