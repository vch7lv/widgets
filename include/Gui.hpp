# pragma once
#include <SFML/Window.hpp>
#include "Widget.h"

class Gui
{
    public:
        Gui(sf::RenderWindow& window);

        void mainloop();
        void removeWidget(const sf::String& ID);

        template <typename widgetDerived>
        void addWidget(widgetDerived widget);

        void clear();
    private:
        sf::RenderWindow& window;
        std::vector<std::shared_ptr<Widget>> widgets;
        std::shared_ptr<Widget> focusedWidget {nullptr};

    private:
        void handleEvents();
        void handleEvent(const sf::Event& event);
        std::shared_ptr<Widget> getTopWidget (sf::Vector2f);
};

template <typename widgetDerived>
void Gui::addWidget(widgetDerived widget)
{
    auto newPtr = std::static_pointer_cast<Widget>(widget);
    widgets.push_back(newPtr);
}