#include "world.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Sleep.hpp>
#include <algorithm>
#include <cmath>
#include <limits>
#include "states/game_state.h"
#include "circle.h"
#include "application.h"
#include <iostream>

World::World(sf::RenderWindow& outputTarget)
    : mTarget(outputTarget)
    , mTextures()
{
    loadTextures();
    onUserCreated();
}

World::~World()
{
}

void World::update(sf::Time time)
{
    for (auto& unit : vecUnits)
    {
        float fAngleToNewTarget = atan2(unit.vPosition.y - vTarget.y, unit.vPosition.x - vTarget.x) + 3.14159f;
        float delta = circ_shortdiff(unit.fHeading, fAngleToNewTarget, 0.0f, 2.0f * 3.14159f);
        unit.fHeading = circ_add(unit.fHeading, delta * 0.1f * 10.0f, 0.0f, 2.0f * 3.14159f);
        unit.sprite.setOrigin(0, 0);
        unit.sprite.setPosition(unit.vPosition.x, unit.vPosition.y);
        unit.sprite.setOrigin(16, 15);
        unit.sprite.setRotation(unit.fHeading * (180.0f/3.14f));
    }

}

void World::draw()
{
    mTarget.clear();
    drawEyes();
    drawHero();
    mTarget.display();
}

void World::processInput(const sf::Event &event)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        vTarget = sf::Vector2f(sf::Mouse::getPosition(mTarget));
    }
}


void World::loadTextures()
{
    mTextures.load(Textures::Eye,  "res/eye.png");
    mTextures.load(Textures::Hero, "res/hero.png");
}

void World::loadFonts()
{

}

void World::onUserCreated()
{
    int nUnits = 60;
    for (int i = 0; i < nUnits; i++)
    {
        vecUnits.push_back(
                    //angle, pos, target, sf::sprite
                    { 0.0f, sf::Vector2f(rand()%Application::SCREEN_WIDTH, rand()% Application::SCREEN_HEIGHT), sf::Vector2f(0.0f, 0.0f), sf::Sprite(mTextures.get(Textures::Eye))});


    }
}

void World::drawEyes()
{
    for(const Unit &u : vecUnits)
    {
        mTarget.draw(u.sprite);
    }
}

void World::drawHero()
{
    sf::Sprite heroSprite;
    heroSprite.setTexture(mTextures.get(Textures::Hero));
    heroSprite.setOrigin(16, 16);
    heroSprite.setPosition(vTarget.x, vTarget.y);
    mTarget.draw(heroSprite);
}
