
#include <SFML/Graphics.hpp>
#include <iostream>

class Start {
private:
    sf::Font font;

    Start() {
        if (!font.loadFromFile("assets/DejaVuSans.ttf"))
            std::cerr << "Eroare: nu pot încărca fontul\n";
    }
    
    sf::Text startText;
public:
    Start(sf::Vector2u winSize);             
    bool showStart = true;
    void handleEvent(const sf::Event& event);   
    void draw(sf::RenderWindow& wnd) const;
};