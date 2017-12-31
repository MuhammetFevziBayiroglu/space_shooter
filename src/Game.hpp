#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include <tinyxml2/tinyxml2.h>

#include "SpriteSheet.hpp"

namespace ss{
    extern SpriteSheet Sprites;
    extern sf::Clock Clock;
    
    extern entityx::Entity Player;
    extern entityx::TimeDelta TimeStep;
   
    extern float ScaleM2P;
    extern float ScaleP2M;
  
    extern entityx::EntityX Entityx;
 
    extern sf::RenderWindow Window;

    extern b2World World;
}
