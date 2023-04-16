#ifndef WORLD_H
#define WORLD_H
#include "utils/resource_holder.h"
#include "utils/resource_identifiers.h"
#include "unit.h"
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>
#include <array>
#include <queue>


// Forward declaration
namespace sf
{
    class RenderTarget;
    class Event;
}

class World : private sf::NonCopyable
{
    public:
                                            World(sf::RenderWindow& outputTarget);
                                            ~World();
        void								update(sf::Time);
        void								draw();

        void processInput(const sf::Event& event);
        bool isWinActivated();
    private:
        void								loadTextures();
        void                                loadFonts();
        void                                onUserCreated();
        void                                drawEyes();
        void                                drawHero();

        sf::Vector2f vTarget;
        std::vector<Unit> vecUnits;

    private:
        sf::RenderWindow&					mTarget;
        TextureHolder						mTextures;
};
#endif // WORLD_H
