#include "Widget.h"


std::string Widget::getID() const {
    return ID;
}

void Widget::setID(const std::string& newID) {
    ID = newID;
}

bool Widget::isOn(sf::Vector2f point) const {
    return (point.x >= position.x &&
            point.y >= position.y &&
            point.x <= position.x + size.x &&
            point.y <= position.y + size.y);
}