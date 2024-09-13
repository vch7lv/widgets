#include <SFML/Graphics.hpp>
#include "Gui.hpp"
#include "Button.h"
#include "Picture.h"
#include <iostream>

void changeButtonColor(std::shared_ptr<Button> button, sf::Color color)
{
    button->setBackgroundColor(color);
    std::cout << "Button color changed\n";
}

void printToConsole(const std::string& message)
{
    std::cout << message << std::endl;
}

int main()
{

    sf::RenderWindow window{ {900, 800}, "MY GUI" };
    Gui gui{window};


    auto button = Button::createButton();
    button->setBackgroundColor(sf::Color::White);
    button->setTextColor(sf::Color::Red);
    button->setSize(sf::Vector2f{150, 80});
    button->setPosition(sf::Vector2f{10, 10});

    sf::Font font;
    font.loadFromFile("resources/OpenSans-Bold.ttf");   

    button->setFont(font); 
    button->setText("button1");

    button->onHover(&changeButtonColor, button, sf::Color::Green);
    button->onStopHover(&changeButtonColor, button, sf::Color::White);
    button->onPressed(&printToConsole, "mouse pressed");
    button->onReleased(&printToConsole,"mouse released");
    button->setID("newbutton");
    button->setFontSize(24);

    gui.addWidget(button);


    auto pic = Picture::createPicture("resources/imgs/img2.jpg");
    pic->setPosition({300, 100});
    pic->setID("picture");
    gui.addWidget(pic);


    gui.mainloop();
}