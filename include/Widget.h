#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <map>

class Widget : public sf::Drawable, public std::enable_shared_from_this<Widget>
{
    protected:
        Widget() = default;
        virtual ~Widget() = default;
        
    public:

        virtual void handleEvent(const sf::Event& event) = 0;

        bool isOn(sf::Vector2f point) const;

        std::string getID() const;
        void setID(const std::string& newID);

        Widget(const Widget&) = delete;
        Widget& operator = (const Widget&) = delete;

    protected:
        sf::Vector2f position;
        sf::Vector2f size;
        std::string ID;
};