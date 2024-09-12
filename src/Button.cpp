#include "Button.h"
#include <iostream>

void Button::setBackgroundColor(sf::Color color) 
{
    background.setFillColor(color);
}
void Button::setTextColor(sf::Color color) 
{
    text.setFillColor(color);
}
void Button::setSize(sf::Vector2f sz) 
{
    size = sz;
    updatePositionAndSize();
}
void Button::setPosition(sf::Vector2f pos)
{
    position = pos;
    updatePositionAndSize();
}
void Button::setFont(sf::Font newfont)
{
    font = newfont;
    text.setFont(font);
}
void Button::setText(const sf::String& newText)
{
    text.setString(newText);
    updatePositionAndSize();
}
void Button::setFontSize(unsigned int sz)
{
    text.setCharacterSize(sz);
}


void Button::updatePositionAndSize() {
    background.setPosition(position);
    background.setSize(size);
    text.setPosition(calculatePositionForText());
}


void Button::handleEvent(const sf::Event& event) 
{
    switch(event.type) {
        case sf::Event::MouseMoved:
            if (isOn({event.mouseMove.x, event.mouseMove.y}))
            {   
                if (!IS_HOVER) 
                {
                    IS_HOVER = true;
                    if (onHoverCallback) onHoverCallback->invoke();
                }
            } 
            else 
            {
                if (IS_HOVER)
                {
                    IS_HOVER = false;
                    if (onStopHoverCallback) onStopHoverCallback->invoke();
                }
            }
            break;
        case sf::Event::MouseButtonPressed:
            if (isOn({event.mouseButton.x, event.mouseButton.y}))
            {
                WAS_PRESSED = true;
                if (onPressedCallback) onPressedCallback->invoke();
            }
            break;
        case sf::Event::MouseButtonReleased:
            if (WAS_PRESSED)
            {
                WAS_PRESSED = false;
                if (onReleasedCallback) onReleasedCallback->invoke();
            }
            break;
    }
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(background, states);
    target.draw(text, states);
}

std::shared_ptr<Button> Button::createButton() 
{
    return std::make_shared<Button>();
}

sf::Vector2f Button::calculatePositionForText()
{
    float width = position.x + (size.x - text.getGlobalBounds().width)/2; 
    float height = position.y + (size.y - text.getGlobalBounds().height)/2;
    return {width, height}; 
}