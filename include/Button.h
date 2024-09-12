#pragma once
#include "Clickable.hpp"


class Button final : public Clickable
{
    public:
        void setBackgroundColor(sf::Color color);
        void setTextColor(sf::Color color);
        void setSize(sf::Vector2f size);
        void setPosition(sf::Vector2f pos);
        void setFont(sf::Font font);
        void setText(const sf::String& text);
        void setFontSize(unsigned int sz);

        static std::shared_ptr<Button> createButton();


    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void handleEvent(const sf::Event& event) override;

        sf::RectangleShape background;
        sf::Font font;
        sf::Text text;

        bool WAS_PRESSED = false;
        bool IS_HOVER = false;

        void updatePositionAndSize();
        sf::Vector2f calculatePositionForText();
};