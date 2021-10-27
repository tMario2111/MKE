#pragma once

#include <SFML/Graphics.hpp>

#include <math.h>

namespace mke
{
	namespace util
	{

		constexpr float PI = 3.14159f;
		constexpr float SQRT2 = 1.41421f;
		constexpr float SQRT3 = 1.73205f;
	
		/// <summary>
		/// Convert radians into degress
		/// </summary>
		/// <param name="rad">: Radians</param>
		/// <returns>Degrees</returns>
		float toDeg(float rad);

		/// <summary>
		/// Convert degrees into radians
		/// </summary>
		/// <param name="deg">: Degrees</param>
		/// <returns>Radians</returns>
		float toRad(float deg);

		/// <summary>
		/// Distance between 2 points
		/// </summary>
		/// <param name="A">: First point</param>
		/// <param name="B">: Second point</param>
		/// <returns>The distance between the 2 points</returns>
		float distance(sf::Vector2f A, sf::Vector2f B);

		/// <summary>
		/// Get the rotation / angle to a point
		/// </summary>
		/// <param name="A">: First point</param>
		/// <param name="B">: Second point</param>
		/// <returns>The rotation / angle in radians</returns>
		float getRotationToPoint(sf::Vector2f A, sf::Vector2f B);

		/// <summary>
		/// Center an sf::Text with any origin on the X axis 
		/// </summary>
		/// <param name="text">: A reference to the text</param>
		/// <param name="X1">: Left</param>
		/// <param name="X2">: Right</param>
		void centerTextX(sf::Text& text, float X1, float X2);

		/// <summary>
		/// Center an sf::Text with any origin on the Y axis
		/// </summary>
		/// <param name="text">: A reference to the text</param>
		/// <param name="Y1">: Top</param>
		/// <param name="Y2">: Bottom</param>
		void centerTextY(sf::Text& text, float Y1, float Y2);

		/// <summary>
		/// Center an sf::Text with any origin on the X and Y axis
		/// </summary>
		/// <param name="text">: A reference to the text</param>
		/// <param name="X1">: Left</param>
		/// <param name="X2">: Right</param>
		/// <param name="Y1">: Top</param>
		/// <param name="Y2">: Bottom</param>
		void centerTextXY(sf::Text& text, float X1, float X2, float Y1, float Y2);
	}
}

