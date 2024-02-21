#ifndef CHART_HPP
#define CHART_HPP

#include "constant.hpp"
#include "graphique.hpp"

class chart
{
private:
    float width_screen = 1280;
    float height_screen = 720;

    graphique Graphique;
public:
    chart(OHLCV _data);

    void loop();

    void draw(sf::RenderWindow& window);
};

#endif