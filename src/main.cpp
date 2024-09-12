#include <SFML/Graphics.hpp>
#include "Gui.hpp"
#include "Button.h"
#include <iostream>

void changeButtonColor(std::shared_ptr<Button> button, sf::Color color)
{
    button->setBackgroundColor(color);
    std::cout << "Button color changed\n";
}

void printToConsole(const sf::String& message)
{
    std::cout << message.toAnsiString() << std::endl;
}
void onButtonReleased()
{
    std::cout << "Button released\n";
}

int main()
{

    sf::RenderWindow window{ {800, 600}, "MY GUI" };
    Gui gui{window};


    auto button = Button::createButton();
    button->setBackgroundColor(sf::Color::White);
    button->setTextColor(sf::Color::Red);
    button->setSize(sf::Vector2f{150, 80});
    button->setPosition(sf::Vector2f{120, 120});

    sf::Font font;
    font.loadFromFile("font.ttf");   

    button->setFont(font); 
    button->setText("but");

    button->onHover(&changeButtonColor, button, sf::Color::Green);
    button->onStopHover(&changeButtonColor, button, sf::Color::White);
    button->onPressed(&printToConsole, "mouse pressed");
    button->onReleased(&printToConsole,"mouse released");
    button->setID("newbutton");
    button->setFontSize(24);

    gui.addWidget(button);

    gui.mainloop();
}