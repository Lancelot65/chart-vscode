#include "constant.hpp"

namespace th
{
    Theme Light = {
        sf::Color::White,
        sf::Color(242, 54, 69),
        sf::Color(8,153,129),
        sf::Color(242, 54, 69),
        sf::Color(8,153,129),
        "Light"
    };

    Theme Dark = {
        sf::Color(9,11,15),
        sf::Color(242, 54, 69),
        sf::Color(8,153,129),
        sf::Color(242, 54, 69),
        sf::Color(8,153,129),
        "Dark"
    };
}

OHLCV load_data(int size)
{
    if (size > 263)
    {
        throw "size is too long";
    }

    OHLCV data;

    std::ifstream file("EURUSD=X.csv");
    file.is_open();
    std::string line;
    getline(file, line);

    for (int i = 0; i < size; i++)
    {
        getline(file, line);

        std::istringstream iss(line);
        std::string token;

        std::getline(iss, token, ','); 
        std::getline(iss, token, ','); 
        data.open.push_back(std::stod(token.substr(1, token.size() - 2)));

        std::getline(iss, token, ','); 
        data.high.push_back(std::stod(token.substr(1, token.size() - 2)));

        std::getline(iss, token, ','); 
        data.low.push_back(std::stod(token.substr(1, token.size() - 2)));

        std::getline(iss, token, ','); 
        data.close.push_back(std::stod(token.substr(1, token.size() - 2)));

        data.time.push_back(0);
    }

    file.close();

    return data;
}
