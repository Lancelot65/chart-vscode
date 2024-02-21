#include "graphique.hpp"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <string>


#include "constant.hpp"



class chart
{
private:
    float width_screen = 1280;
    float height_screen = 720;

    graphique Graphique;
public:
    chart(OHLCV _data) :
        Graphique(0, 0, this->width_screen, this->height_screen, _data) {}

    void loop()
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

    void draw(sf::RenderWindow& window)
    {
        this->Graphique.show(window);
    }
};

int main()
{
    OHLCV data = load_data(20);
    chart obj(data);
    obj.loop();

    return 0;
}