
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "start.h"
#include "pesti.h"

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    sf::RenderWindow window(desktop, "SFML maximized", sf::Style::Default);
    window.setPosition({0, 0});
    
    
    sf::Texture texture;
    if (!texture.loadFromFile("/home/vboxuser/Desktop/proiectfacc++/pescar.png")){
        perror("/home/vboxuser/Desktop/proiectfacc++/pescar.png");
        return 1;
    }  

    sf::Sprite player(texture);
    player.setPosition(550.f, 70.f);
    player.setScale(0.5f, 0.5f);
    

    const float barHeight = 30.f;
    sf::RectangleShape bar;
    bar.setSize({window.getSize().x * 1.f, barHeight});
    
    float playerBottom = player.getPosition().y + player.getGlobalBounds().height;
    bar.setPosition(0.f, playerBottom + 5.f);
    bar.setFillColor(sf::Color(180, 220, 255, 200));


    sf::RectangleShape blueZone;
    blueZone.setFillColor(sf::Color(10, 30, 80)); 
    blueZone.setPosition(0.f, bar.getPosition().y + barHeight);
    blueZone.setSize({
        window.getSize().x * 1.f,
        window.getSize().y - blueZone.getPosition().y
    });

    Start startScreen(window.getSize());

    Peste pestele(window.getSize());
    Somon somonul(window.getSize());
    Cod codul(window.getSize());
    Stiuc stiucul(window.getSize());

    sf::Clock timer;

    int scor = 0;
    sf::Font font;
    font.loadFromFile("assets/DejaVuSans.ttf");
    sf::Text scoreTxt("Scorul tau: 0", font, 30);
    scoreTxt.setFillColor(sf::Color::Black);
    scoreTxt.setPosition(20.f, 10.f);

    bool prins = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type ==sf::Event::Closed)
                window.close();
            startScreen.handleEvent(event);
            if (!startScreen.showStart && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                prins=pestele.handleClick({event.mouseButton.x, event.mouseButton.y});
                if (!prins)
                    prins = somonul.handleClick({event.mouseButton.x, event.mouseButton.y});
                if (!prins)
                    prins = codul.handleClick({event.mouseButton.x, event.mouseButton.y});
                if (!prins)
                    prins = stiucul.handleClick({event.mouseButton.x, event.mouseButton.y});
                if(prins)
                {
                    ++scor;
                    scoreTxt.setString("Scorul tau: " + std::to_string(scor));
                }
                //somonul.handleClick({event.mouseButton.x, event.mouseButton.y});
                //codul.handleClick({event.mouseButton.x, event.mouseButton.y});
                //stiucul.handleClick({event.mouseButton.x, event.mouseButton.y});
            }
        }
        float dt = timer.restart().asSeconds();
        if (!startScreen.showStart)
        {
            pestele.update(dt, window.getSize());
            somonul.update(dt, window.getSize());
            codul.update(dt, window.getSize());
            stiucul.update(dt, window.getSize());
        }
        window.clear(sf::Color::White);
        window.draw(player);
        window.draw(bar);
        window.draw(blueZone);
        startScreen.draw(window);
        if (!startScreen.showStart)
        {
            pestele.draw(window);
            somonul.draw(window);
            codul.draw(window);
            stiucul.draw(window);
            window.draw(scoreTxt);
        }
        
        
        window.display();
    }
    return 0;
}