#pragma once
#include "Gui.hpp"
#include <iostream>

Gui::Gui(sf::RenderWindow& window) : window(window) {}

void Gui::mainloop() {
    
    while (window.isOpen())
    {
        handleEvents();

        window.clear();
        for (auto it = widgets.begin(); it != widgets.end(); ++it)
        {
            auto widget = *it;
            window.draw(*widget);
        }
        window.display();
    }
}

void Gui::removeWidget(const sf::String& ID) {
    for (auto it = widgets.begin(); it != widgets.end(); ++it)
    {
        auto widget = *it;
        if (widget->getID() == ID)
        {
            widgets.erase(it);
            break;
        }
    }
}

void Gui::handleEvents() {

    sf::Event event;
    while (window.pollEvent(event))
    {
        handleEvent(event);
    }

}

void Gui::handleEvent(const sf::Event& event) {

    switch (event.type) 
    {
        case sf::Event::Closed:
        {
            window.close();
            break;
        }
        case sf::Event::MouseButtonPressed:
        {
            sf::Vector2f point {event.mouseButton.x, event.mouseButton.y};
            auto widget = getTopWidget(point);
            focusedWidget = widget;
            break;
        }
        case sf::Event::MouseMoved:
        {
            for (auto it = widgets.begin(); it != widgets.end(); ++it)
            {
                auto widget = *it;
                if (widget != focusedWidget) widget->handleEvent(event);
            }
            break;
        }
    }

    if (focusedWidget) focusedWidget->handleEvent(event);
}

std::shared_ptr<Widget> Gui::getTopWidget (sf::Vector2f point)
{
    for (auto it = widgets.rbegin(); it != widgets.rend(); ++it)
    {
        auto curWidget = *it;
        if (curWidget->isOn(point))
            return curWidget;
    }

    return nullptr;
}
