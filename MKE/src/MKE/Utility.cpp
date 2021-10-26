#include "Utility.h"

namespace mke
{
	namespace util
	{
		float toDeg(float rad)
		{
			return rad * 180 / PI;
		}
		float toRad(float deg)
		{
			return deg * PI / 180;
		}
		float distance(sf::Vector2f A, sf::Vector2f B)
		{
			return sqrtf((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
		}

		float getRotationToPoint(sf::Vector2f A, sf::Vector2f B)
		{
			
			return atan2f(B.y - A.y, B.x - A.x);
		}
		void centerTextX(sf::Text& text, float X1, float X2)
		{
			sf::Vector2f position;
			position.x = (X1 + X2) / 2 - (text.getGlobalBounds().width / 2 - text.getOrigin().x * text.getScale().x) - 
				text.getLocalBounds().left * text.getScale().x;
			position.y = text.getPosition().y;
			text.setPosition(position);
		}
		void centerTextY(sf::Text& text, float Y1, float Y2)
		{
			sf::Vector2f position;
			position.x = text.getPosition().x;
			position.y = (Y1 + Y2) / 2 - (text.getGlobalBounds().height / 2 - text.getOrigin().y * text.getScale().y) - 
				text.getLocalBounds().top * text.getScale().y;
			text.setPosition(position);
		}
		void centerTextXY(sf::Text& text, float X1, float X2, float Y1, float Y2)
		{
			centerTextX(text, X1, X2);
			centerTextY(text, Y1, Y2);
		}
	}
}