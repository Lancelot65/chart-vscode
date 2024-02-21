#include "chart.hpp"

chart::chart(OHLCV _data) :
    Graphique(0, 0, this->width_screen, this->height_screen, _data) {}

void chart::loop()
{
    sf::RenderWindow window(sf::VideoMode(this->width_screen, this->height_screen), "candlestick chart", sf::Style::Close | sf::Style::Titlebar);

    sf::Image icon;
    icon.loadFromFile("logo.png");
    
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }
        }

        window.clear(sf::Color::White);

        this->draw(window);
        

        window.display();
    }
}

void chart::draw(sf::RenderWindow& window)
{
    this->Graphique.show(window);
}