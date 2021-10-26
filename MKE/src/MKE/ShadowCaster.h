#pragma once

#include <SFML/Graphics.hpp>

#include "Utility.h"

#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <utility>
#include <vector>

namespace mke
{
	/// <summary>
	/// a shadow caster class
	/// </summary>
	class ShadowCaster : public sf::Drawable
	{
	public:

		/// <summary>
		/// Default constructor
		/// </summary>
		/// <param name="win">a RenderWindow</param>
		ShadowCaster(sf::RenderWindow& win);

		/// <summary>
		/// The vector of edges that are used by the shadow caster. Modify this vector
		/// according to your edges
		/// </summary>
		std::vector<std::pair<sf::Vector2f, sf::Vector2f>> edges;

		/// <summary>
		/// Set the rays' radius
		/// </summary>
		/// <param name="radius">the maximum lenght of every ray</param>
		void setRadius(float radius);

		/// <summary>
		/// Get the radius
		/// </summary>
		/// <returns>the radius</returns>
		float getRadius();

		/// <summary>
		/// Update the ShadowCaster (must be called every frame)
		/// </summary>
		/// <param name="reference_point">the point that the rays are casted from (player's position etc.)</param>
		void update(sf::Vector2f reference_point);

		/// <summary>
		/// Draw function (inherited from sf::Drawable)
		/// </summary>
		/// <param name="target">the sf::RenderTarget</param>
		/// <param name="states">the sf::RenderStates</param>
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	private:
		struct Ray
		{
			float angle;
			sf::Vector2f position;
		};
		std::vector<Ray> rays;
		float radius;
		std::string shader_data;
		sf::Shader shader;
		sf::VertexArray vision_triangle_fan;
		sf::RenderTexture render_texture;
		bool getLineIntersection(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f p4, sf::Vector2f& p5);
		void calculateVisibility(sf::Vector2f reference_point);
		void createTriangleFan(sf::Vector2f reference_point);
		void drawToRenderTexture();
	};
}

