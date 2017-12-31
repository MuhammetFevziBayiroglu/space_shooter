#pragma once

#include "Game.hpp"

namespace ss{
    struct ComponentAnimation{
        std::vector <std::vector<sf::Sprite>> mSprite;
        std::vector <bool> mIsContinuous;
        std::vector <entityx::TimeDelta> mPeriod;
        entityx::TimeDelta mElapsedTime;

        unsigned int mRow = 0;
        unsigned int mColumn = 0;

        void AddSingleFrame(std::string name, bool isContinuous = false, entityx::TimeDelta period = 0.1){
            std::vector <sf::Sprite> sprites;
            try{
                sprites.push_back(Sprites.GetSprite(name));
            }
            catch(std::string error){
                return;
            }

            if(!sprites.empty()){
                mSprite.push_back(sprites);
                mIsContinuous.push_back(isContinuous);
                mPeriod.push_back(period);
            }
        }

        void AddAnimation(std::string baseName, bool isContinuous = false, entityx::TimeDelta period = 0.1){
            std::vector <sf::Sprite> sprites;
            std::stringstream ss;

            for(int i=0; i<1000; i++){
                ss.str("");
                ss << baseName << std::setfill('0') << std::setw(4) << i << ".png";
                
                try{
                    sprites.push_back(Sprites.GetSprite(ss.str()));
                }
                catch(std::string error){
                    // std::cout << error;
                    break;
                }
            }

            if(!sprites.empty()){
                mSprite.push_back(sprites);
                mIsContinuous.push_back(isContinuous);
                mPeriod.push_back(period);
            }
            else
                throw std::string ("\nNo sprites with base name ''" + baseName + "'' found.");
        }

        sf::Sprite& GetSprite(){
            return mSprite[mRow][mColumn];
        }
    };
}
