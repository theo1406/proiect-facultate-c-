#include "start.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Start::Start(sf::Vector2u winSize)
{
    if (!font.loadFromFile("assets/DejaVuSans.ttf"))
        std::cerr << "Eroare: nu pot încărca fontul\n";

    startText.setFont(font);
    startText.setString("CLICK TO START GAME");
    startText.setCharacterSize(48);
    startText.setFillColor(sf::Color::Black);

    sf::FloatRect b = startText.getLocalBounds();
    startText.setOrigin(b.width / 2.f, b.height / 2.f);
    startText.setPosition(winSize.x / 2.f, winSize.y / 2.f);
}

void Start::handleEvent(const sf::Event& ev)
{
    if (showStart && ev.type == sf::Event::MouseButtonPressed)
        showStart = false;
}

void Start::draw(sf::RenderWindow& wnd) const
{
    if (showStart)
        wnd.draw(startText);
}