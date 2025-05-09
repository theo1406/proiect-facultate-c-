#include <SFML/Graphics.hpp>
#include <iostream>

class Peste{
public:
    explicit Peste(sf::Vector2u winSize);
    void draw(sf::RenderWindow& wnd) const;
    void update(float dt, sf::Vector2u winSize);
    bool handleClick(sf::Vector2i mousePos);
    bool alive = true;
protected:
    int dir = 1;
    sf::Sprite  sprite;
    float spawnY;
    static float nextspawnY;
    float speed = 400.f;
private:
    sf::Texture texturapeste;
    std::vector<sf::Sprite> vectorpeste;
    
    float respawnTimer = 0.f;
};

class Somon: public Peste{
public:
    explicit Somon(sf::Vector2u winSize)
        : Peste(winSize)
    {
        if (!texturasomon.loadFromFile("/home/vboxuser/Desktop/proiectfacc++/somon.png"))
            std::cerr << "Nu pot încărca somon.png\n";

        sprite.setTexture(texturasomon);
        sprite.setScale(0.5f, 0.5f);
        float h = sprite.getGlobalBounds().height;
        spawnY = nextspawnY - h + 75.f;
        nextspawnY = spawnY - (h + 5.f);
        sprite.setPosition(0.f, spawnY);
        speed = 1000.f;
    }
private:
    sf::Texture texturasomon;
};


class Cod: public Peste{
public:
    explicit Cod(sf::Vector2u winSize)
        : Peste(winSize)
    {
        if (!texturacod.loadFromFile("/home/vboxuser/Desktop/proiectfacc++/cod.png"))
            std::cerr << "Nu pot încărca cod.png\n";

        sprite.setTexture(texturacod);
        sprite.setScale(0.7f, 0.7f);
        float h = sprite.getGlobalBounds().height;
        spawnY = nextspawnY - h;
        nextspawnY = spawnY - (h + 5.f); 
        nextspawnY = spawnY - 10.f;
        sprite.setPosition(0.f, spawnY);
        speed = 500.f;
    }
private:
    sf::Texture texturacod;
};


class Stiuc: public Peste{
public:
    explicit Stiuc(sf::Vector2u winSize)
        : Peste(winSize)
    {
        if (!texturastiuc.loadFromFile("/home/vboxuser/Desktop/proiectfacc++/stiuc.png"))
            std::cerr << "Nu pot încărca cod.png\n";

        sprite.setTexture(texturastiuc);
        sprite.setScale(0.7f, 0.7f);
        float h = sprite.getGlobalBounds().height;
        spawnY = nextspawnY - h + 60.f;
        //nextspawnY = spawnY - (h + 5.f); 
        //nextspawnY = spawnY - 10.f;
        sprite.setPosition(0.f, spawnY);
        speed = 900.f;
    }
private:
    sf::Texture texturastiuc;
};