#include "Game.hpp"

#include "Components.hpp"
#include "Systems.hpp"
#include "SpriteSheet.hpp"

using namespace ss;

int main(int argc, char** argv){
    try{
        // Sprites.Load("../data/spaceTexturePack.png", "../data/spaceTexturePack.xml");
        Sprites.Load("/home/mfb/Desktop/krita_projects/spaceShooter/spaceTexturePack.png", "/home/mfb/Desktop/krita_projects/spaceShooter/spaceTexturePack.xml");
        
        entityx::Entity entity;

        // Parallax1
        entity = Entityx.entities.create();
        auto parallax1 = entity.assign <ComponentParallax> (0.025);
        sf::Texture texture1;
        texture1.loadFromFile("../data/spaceParallax1.png");
        texture1.setRepeated(true);
        parallax1->mSprite.setTexture(texture1);

        // Parallax2
        entity = Entityx.entities.create();
        auto parallax2 = entity.assign <ComponentParallax> (0.05);
        sf::Texture texture2;
        texture2.loadFromFile("../data/spaceParallax2.png");
        texture2.setRepeated(true);
        parallax2->mSprite.setTexture(texture2);

        // Parallax3
        entity = Entityx.entities.create();
        auto parallax3 = entity.assign <ComponentParallax> (0.1);
        sf::Texture texture3;
        texture3.loadFromFile("../data/spaceParallax4.png");
        texture3.setRepeated(true);
        parallax3->mSprite.setTexture(texture3);

        // Player
        entity = Entityx.entities.create();
        auto animation = entity.assign <ComponentAnimation> ();
        animation->AddSingleFrame("spaceShipVectorVersion.png");
        // animation->AddSingleFrame("spaceShip.png");
        auto textureRect = animation->GetSprite().getTextureRect();
        auto physics = entity.assign <ComponentPhysics> (entity, animation->GetSprite().getTextureRect().width * 0.6 * ScaleP2M);
        physics->mBody->SetAwake(true);
        auto control = entity.assign <ComponentControl> ();
        auto hp = entity.assign <ComponentHitpoints> (100);
        auto damage = entity.assign <ComponentDamage> (1000);
        Player = entity;

        Window.create(sf::VideoMode(1600, 900), "SpaceShooter", sf::Style::Close);
        Window.setFramerateLimit(60);

        Entityx.systems.add <SystemAnimation> ();
        Entityx.systems.add <SystemPhysics> ();
        Entityx.systems.add <SystemDisplay> ();
        Entityx.systems.add <SystemControl> ();
        Entityx.systems.add <SystemParallax> ();
        Entityx.systems.add <SystemEvent> ();
        Entityx.systems.add <SystemHitpoints> ();
        Entityx.systems.add <SystemLifespan> ();
        Entityx.systems.add <SystemAsteroid> (sf::seconds(1));
        Entityx.systems.configure();

        auto timeStep = 0.1;
        while(Window.isOpen()){
            Entityx.systems.update <SystemAnimation> (timeStep);
            Entityx.systems.update <SystemPhysics> (timeStep);
            Entityx.systems.update <SystemDisplay> (timeStep);
            Entityx.systems.update <SystemControl> (timeStep);
            Entityx.systems.update <SystemParallax> (timeStep);
            Entityx.systems.update <SystemEvent> (timeStep);
            Entityx.systems.update <SystemHitpoints> (timeStep);
            Entityx.systems.update <SystemAsteroid> (timeStep);
            Entityx.systems.update <SystemLifespan> (timeStep);
        }

        for(auto entity: Entityx.entities.entities_with_components (physics)){
            entity.destroy();
        }

    }
    catch(std::string error){
        std::cout << error;
    }
}
