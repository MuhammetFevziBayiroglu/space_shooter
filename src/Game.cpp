#include "Game.hpp"

namespace ss{
    // sf::Clock Game::Clock;
    
    // entityx::Entity Game::Player;
    // entityx::TimeDelta Game::TimeStep;
    
    // float Game::ScaleM2P;
    // float Game::ScaleP2M;
    
    // entityx::EntityX Game::Entityx;
    
    // sf::RenderWindow Game::Window;
    
    // b2World Game::World(b2Vec2(0, 0));

    SpriteSheet Sprites;
    sf::Clock Clock;
    
    entityx::Entity Player;
    entityx::TimeDelta TimeStep;
   
    float ScaleM2P = 1000;
    float ScaleP2M = 1.f/ScaleM2P;
  
    entityx::EntityX Entityx;
 
    sf::RenderWindow Window;

    b2World World(b2Vec2(0, 0));
}
