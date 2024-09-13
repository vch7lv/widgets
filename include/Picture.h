#include <SFML/Graphics.hpp>
#include "Widget.h"

class Picture : public Widget
{
    public:
        Picture (const std::string& pathToImg);
        void setPosition(sf::Vector2f pos);
        static std::shared_ptr<Picture> createPicture(const std::string& pathToImg);

    private:
        sf::Sprite sprite;
        sf::Texture texture;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void handleEvent(const sf::Event& event);
};