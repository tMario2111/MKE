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
		/// convert radins into degress
		/// </summary>
		/// <param name="rad">radians</param>
		/// <returns>degrees</returns>
		float toDeg(float rad);

		/// <summary>
		/// convert degrees into radians
		/// </summary>
		/// <param name="deg">degrees</param>
		/// <returns>radians</returns>
		float toRad(float deg);

		/// <summary>
		/// distance between 2 points
		/// </summary>
		/// <param name="A">first point</param>
		/// <param name="B">second point</param>
		/// <returns>the distance between the 2 points</returns>
		float distance(sf::Vector2f A, sf::Vector2f B);

		/// <summary>
		/// get the rotation / angle to a point
		/// </summary>
		/// <param name="A">first point</param>
		/// <param name="B">second point</param>
		/// <returns>the rotation / angle in radians</returns>
		float getRotationToPoint(sf::Vector2f A, sf::Vector2f B);

		/// <summary>
		/// center an sf::Text with any origin on the X axis 
		/// </summary>
		/// <param name="text">a reference to the text</param>
		/// <param name="X1">left</param>
		/// <param name="X2">right</param>
		void centerTextX(sf::Text& text, float X1, float X2);

		/// <summary>
		/// center an sf::Text with any origin on the Y axis
		/// </summary>
		/// <param name="text">a reference to the text</param>
		/// <param name="Y1">top</param>
		/// <param name="Y2">bottom</param>
		void centerTextY(sf::Text& text, float Y1, float Y2);

		/// <summary>
		/// center an sf::Text with any origin on the X and Y axis
		/// </summary>
		/// <param name="text"><a reference to the text</param>
		/// <param name="X1">left</param>
		/// <param name="X2">right</param>
		/// <param name="Y1">top</param>
		/// <param name="Y2">bottom</param>
		void centerTextXY(sf::Text& text, float X1, float X2, float Y1, float Y2);
	}
}

