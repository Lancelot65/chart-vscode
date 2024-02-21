#include "../chart.hpp"
#include <fstream>
#include <sstream>

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

int main()
{
    OHLCV data = load_data(15);
    chart obj(data);
    obj.loop();

    return 0;
}