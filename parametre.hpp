#ifndef PARAMETRE_HPP
#define PARAMETRE_HPP

#include <SFML/Graphics.hpp>
#include "graphique.hpp"

class parametre
{
private:
    sf::RectangleShape rect;

    bool visible = true;
    bool on_click_resize = false;

    int min_width = 15;
    int max_width = 140;

    sf::Cursor cursor_resize;
    sf::Cursor cursor_default;

    graphique *Graphique;
    sf::RenderWindow *window;
public:
    parametre(float x, float y, float width, float height):
        rect(sf::Vector2f(width, height))
        {
            rect.setPosition(sf::Vector2f(x, y));
            rect.setFillColor(sf::Color::Black);

            this->cursor_default.loadFromSystem(sf::Cursor::Arrow);
            this->cursor_resize.loadFromSystem(sf::Cursor::SizeHorizontal);
        }
    void show()
    {
        this->window->draw(this->rect);
    }

    void set_parametre(sf::RenderWindow *window, graphique *Graphique)
    {
        this->Graphique = Graphique;
        this->window = window;
    }

    void manage_event(sf::Event event)
    {
        if (this->visible)
        {
            switch (event.type)
            {
            case sf::Event::MouseMoved:
                if (sf::Mouse::getPosition(*this->window).x > this->rect.getSize().x - 3 && sf::Mouse::getPosition(*this->window).x < this->rect.getSize().x + 3)
                {
                    window->setMouseCursor(this->cursor_resize);
                }
                else
                {
                    window->setMouseCursor(this->cursor_default);
                }
                break;
            case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        this->on_mouse_press(event.mouseButton.x);
                    }
                    break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    this->on_mouse_release(event.mouseButton.x);
                }
                
            default:
                break;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->on_mouse_drag(sf::Mouse::getPosition(*window).x);
            }
        }
    }

    void on_mouse_press(int x)
    {
        if (x > this->rect.getSize().x - 3 and x < this->rect.getSize().x + 3)
        {
            this->on_click_resize = true;
        }
    }

    void on_mouse_release(int x)
    {
        if (this->on_click_resize)
        {
            this->on_click_resize = false;
            this->rect.setSize(sf::Vector2f(this->check_size(x), this->rect.getSize().y));
            this->Graphique->set_size(this->rect.getSize().x, 0,
                        this->window->getSize().x - this->rect.getSize().x,
                        this->window->getSize().y);
        }
    }

    void on_mouse_drag(int x)
    {
        if (this->on_click_resize)
        {
            this->rect.setSize(sf::Vector2f(this->check_size(x), this->rect.getSize().y));
            this->Graphique->set_size(this->rect.getSize().x, 0,
                        this->window->getSize().x - this->rect.getSize().x,
                        this->window->getSize().y);
        }
    }

    int check_size(int x)
    {
        if (x <= this->min_width)
        {
            return this->min_width;
        }
        else if (x >= this->max_width)
        {
            return this->max_width;
        }
        return x;
    }
};

#endif