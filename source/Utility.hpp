#pragma once

#include <SFML/Graphics.hpp>

#include <math.h>

namespace mke
{
	constexpr float PI = 3.14159f;
	constexpr float SQRT2 = 1.41421f;
	constexpr float SQRT3 = 1.73205f;
    
    /**
     * @brief Convert radians into degreess
     * 
     * @param rad 
     * @return float 
     */
	float toDeg(float rad);

	/**
	 * @brief Convert degrees into radians
	 * 
	 * @param deg 
	 * @return float 
	 */
	float toRad(float deg);

	/**
	 * @brief Get the distance between 2 points
	 * 
	 * @param a First point
	 * @param b Second point
	 * @return
	 */
	float distance(sf::Vector2f a, sf::Vector2f b);

    /**
     * @brief Get the rotation / angle to a point
     * 
     * @param a First point
     * @param b Second point
     * @return float radians
     */
	float getRotationToPoint(sf::Vector2f a, sf::Vector2f b);

    /**
     * @brief Center an sf::Text with any origin on the x axis
     * 
     * @param text 
     * @param x1 
     * @param x2 
     */
	void centerTextX(sf::Text& text, float x1, float x2);

	/**
	 * @brief Center an sf::Text with any origin on the y axis
	 * 
	 * @param text 
	 * @param y1 
	 * @param y2 
	 */
	void centerTextY(sf::Text& text, float y1, float y2);

	/**
	 * @brief Center an sf::Text with any origin on the x and y axis
	 * 
	 * @param text 
	 * @param x1 
	 * @param x2 
	 * @param y1 
	 * @param y2 
	 */
	void centerTextXY(sf::Text& text, float x1, float x2, float y1, float y2);
}