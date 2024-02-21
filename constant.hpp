#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <vector>
#include <SFML/Graphics.hpp>

struct OHLCV
{
    std::vector<double> open;
    std::vector<double> close;
    std::vector<double> high;
    std::vector<double> low;
    std::vector<double> volume;
    std::vector<__int64> time;

    void insert(OHLCV &other)
    {
        this->open.insert(this->open.end(), other.open.begin(), other.open.end());
        this->close.insert(this->close.end(), other.close.begin(), other.close.end());
        this->high.insert(this->high.end(), other.high.begin(), other.high.end());
        this->low.insert(this->low.end(), other.low.begin(), other.low.end());
        this->volume.insert(this->volume.end(), other.volume.begin(), other.volume.end());
        this->time.insert(this->time.end(), other.time.begin(), other.time.end());
    }

    inline size_t size()
    {
        return this->close.size();
    }
};

namespace th
{
    struct Theme
    {
        sf::Color background;
        sf::Color body_down;
        sf::Color body_up;
        sf::Color border_down;
        sf::Color border_up;
        std::string name;
    };

    extern Theme Classic;
    extern Theme Light;
    extern Theme Dark;
    extern Theme Nature;
    extern Theme Vintage;
}

OHLCV load_data(int size);

#endif
