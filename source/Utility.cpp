#include "Utility.hpp"

namespace mke
{
    float toDeg(float rad)
    {
        return rad * 180.f / PI;
    }

    float toRad(float deg)
    {
        return deg * PI / 180.f;
    }

    float distance(sf::Vector2f a, sf::Vector2f b)
    {
        return sqrtf((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    }

    float getRotationToPoint(sf::Vector2f a, sf::Vector2f b)
    {

        return atan2f(b.y - a.y, b.x - a.x);
    }

    void centerTextX(sf::Text& text, float x1, float x2)
    {
        sf::Vector2f position{};
        position.x = (x1 + x2) / 2.f - (text.getGlobalBounds().width / 2.f - text.getOrigin().x * text.getScale().x) -
            text.getLocalBounds().left * text.getScale().x;
        position.y = text.getPosition().y;
        text.setPosition(position);
    }

    void centerTextY(sf::Text& text, float y1, float y2)
    {
        sf::Vector2f position;
        position.x = text.getPosition().x;
        position.y = (y1 + y2) / 2.f - (text.getGlobalBounds().height / 2.f - text.getOrigin().y * text.getScale().y) -
                     text.getLocalBounds().top * text.getScale().y;
        text.setPosition(position);
    }

    void centerTextXY(sf::Text& text, float x1, float x2, float y1, float y2)
    {
        centerTextX(text, x1, x2);
        centerTextY(text, y1, y2);
    }
}