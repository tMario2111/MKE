#pragma once

#include <SFML/Graphics.hpp>

namespace mke
{
	/// <summary>
	/// Sprite batching class
	/// </summary>
	class SpriteBatch : public sf::Drawable
	{
	public:
		/// <summary>
		/// Default constructor
		/// </summary>
		SpriteBatch();

		/// <summary>
		/// Draw the batch
		/// </summary>
		/// <param name="target">: The render target</param>
		/// <param name="states">: The render states (the texture)</param>
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		/// <summary>
		/// Append a sprite to the batch
		/// </summary>
		/// <param name="sprite">: A constant reference to the sprite</param>
		void append(const sf::Sprite& sprite);

		/// <summary>
		/// Clear the batch
		/// </summary>
		void clear();
	private:
		sf::VertexArray batch;
	};
}


