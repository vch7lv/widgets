#include "Widget.h"


sf::String Widget::getID() const {
    return ID;
}

sf::String Widget::setID(const sf::String& newID) {
    ID = newID;
}

bool Widget::isOn(sf::Vector2f point) const {
    return (point.x >= position.x &&
            point.y >= position.y &&
            point.x <= position.x + size.x &&
            point.y <= position.y + size.y);
}