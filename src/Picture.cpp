#include "Picture.h" 

Picture::Picture (const std::string& pathToImg) 
{
    texture.loadFromFile(pathToImg);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
}

void Picture::handleEvent(const sf::Event& event) {}

std::shared_ptr<Picture> Picture::createPicture(const std::string& pathToImg)
{
    return std::make_shared<Picture>(pathToImg);
}

void Picture::setPosition(sf::Vector2f pos) 
{
    sprite.setPosition(pos);
    position = pos;
}

void Picture::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}
