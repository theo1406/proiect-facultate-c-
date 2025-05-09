#include "pesti.h"
#include <iostream>
#include <SFML/Graphics.hpp>


float Peste::nextspawnY = 0.f;

Peste::Peste(sf::Vector2u winSize)
{
    if(!texturapeste.loadFromFile("/home/vboxuser/Desktop/proiectfacc++/peste.png"))
        std::cerr << "Nu pot încarca pestele.\n";

    sprite.setTexture(texturapeste);
    float barHeight = 30.f;
    if (nextspawnY == 0.f) {
        
        nextspawnY = winSize.y - barHeight;
    }

    spawnY = nextspawnY - sprite.getGlobalBounds().height -30.f;
    //nextspawnY = spawnY - 5.f;

    float fishY = winSize.y - barHeight - texturapeste.getSize().y;
    //spawnY = winSize.y - 30.f - texturapeste.getSize().y;

    
    sprite.setPosition(0.f, spawnY);

    // for (int i=0; i<10; ++i)
    // {
    //     sf::Sprite s(texturapeste);
        
    //     s.setPosition(50.f + i * 70, fishY);
    //     //s.setPosition(50.f + i * 70, winSize.y - 120.f);
    //     vectorpeste.push_back(s);
    // }
}

void Peste::draw(sf::RenderWindow& wnd) const
{
    if(alive)
        wnd.draw(sprite);
}

void Peste::update(float dt, sf::Vector2u winSize)
{
    if(!alive)
    {
        respawnTimer -= dt;
        if (respawnTimer <= 0.f){
            //float fishY = winSize.y - 30.f - texturapeste.getSize().y;
            sprite.setPosition(0.f, spawnY);
            dir = 1;
            alive = true;
        }
        return;
    }
    
    sprite.move(speed * dir * dt, 0.f);
    if (sprite.getGlobalBounds().left <= 0.f)    
        dir = 1;
    if (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width >= winSize.x) 
        dir = -1;
}

bool Peste::handleClick(sf::Vector2i mousePos)
{
    sf::Vector2f mp(mousePos);
    if (alive && sprite.getGlobalBounds().contains(mp))
    {
        //float newY = sprite.getPosition().y;
        
        alive = false;
        respawnTimer = 2.f;
        sprite.setPosition(-1000.f, -1000.f);
        //sprite.setPosition(0.f, newY);
        //dir = 1;
        return true;
    }
    return false;
}