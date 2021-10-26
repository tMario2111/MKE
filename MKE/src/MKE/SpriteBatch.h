#pragma once

#include <SFML/Graphics.hpp>

namespace mke
{
	/// <summary>
	/// sprite batching class
	/// </summary>
	class SpriteBatch : public sf::Drawable
	{
	public:
		/// <summary>
		/// default constructor
		/// </summary>
		SpriteBatch();

		/// <summary>
		/// draw the batch
		/// </summary>
		/// <param name="target">the render target</param>
		/// <param name="states">the render states (the texture)</param>
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		/// <summary>
		/// append a sprite to the batch
		/// </summary>
		/// <param name="sprite"></param>
		void append(const sf::Sprite& sprite);

		/// <summary>
		/// clear the batch
		/// </summary>
		void clear();
	private:
		sf::VertexArray batch;
	};
}


