#include "graphique.hpp"
#include "parametre.hpp"
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
    parametre Parametre;

    bool temp_click_resize_etat = false;

public:
    chart(OHLCV _data) :
        Graphique(100, 0, this->width_screen - 100, this->height_screen, _data), Parametre(0, 0, 100, this->height_screen) {}

    void loop()
    {
        sf::RenderWindow window(sf::VideoMode(this->width_screen, this->height_screen), "candlestick chart", sf::Style::Close | sf::Style::Titlebar);

        sf::Image icon;
        icon.loadFromFile("logo.png");
        
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

        this->Parametre.set_parametre(&window, &this->Graphique);

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
                else
                {
                    this->Parametre.manage_event(event);
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
        this->Parametre.show();
    }
};

int main()
{
    OHLCV data = load_data(20);
    chart obj(data);
    obj.loop();

    return 0;
}