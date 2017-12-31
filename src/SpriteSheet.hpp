#pragma once

#include <map>
#include <utility>

#include <tinyxml2/tinyxml2.h>
#include <SFML/Graphics.hpp>

namespace ss{
    class SpriteSheet{
        private:
            sf::Texture mTexture;
            tinyxml2::XMLDocument mDoc;
            std::map <std::string, sf::Sprite> mSprite;

        public:
            SpriteSheet(){}

            SpriteSheet(std::string imageFile, std::string xmlFile){
                Load(imageFile, xmlFile);
            }

            void Load(std::string imageFile, std::string xmlFile){
                mTexture.loadFromFile(imageFile);
                mDoc.LoadFile(xmlFile.c_str());

                mTexture.setSmooth(true);

                auto element = mDoc.FirstChildElement("TextureAtlas");
                if(!element)
                    throw std::string("\nError loading SpriteSheet. Could not find 'TextureAtlas'.");

                element = element->FirstChildElement("sprite");
                if(!element)
                    throw std::string("\nError loading SpriteSheet. Could not find 'sprite'.");

                while(element){
                    auto x = element->IntAttribute("x");
                    auto y = element->IntAttribute("y");
                    auto width = element->IntAttribute("w");
                    auto height = element->IntAttribute("h");
                    std::string name = element->Attribute("n");

                    sf::Sprite sprite;
                    sprite.setTexture(mTexture);
                    sprite.setTextureRect(sf::IntRect(x, y, width, height));
                    sprite.setOrigin(width/2, height/2);

                    mSprite[name] = sprite;

                    element = element->NextSiblingElement("sprite");
                }
            }

            sf::Sprite GetSprite(std::string name){
                auto it = mSprite.find(name);
                if(it != mSprite.end())
                    return it->second;
                else
                    throw std::string("\nCant find sprite named'" + name + "'.");
            }
    };
}
