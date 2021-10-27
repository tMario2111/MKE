#pragma once

#include <SFML/Graphics.hpp>

#include <map>

namespace mke
{

	/// <summary>
	/// A class that manager input
	/// </summary>
	class Input
	{
	public:

		/// <summary>
		/// Process keyboard and mouse events
		/// </summary>
		/// <param name="event">: Currently polled event</param>
		void processEvent(const sf::Event& event);

		/// <summary>
		/// Update the input (must be called before handling events)
		/// </summary>
		void update();

		/// <summary>
		/// Check if a keyboard key is pressed
		/// </summary>
		/// <param name="key">: Keyboard key</param>
		/// <returns>True if pressed, otherwise false</returns>
		bool isKeyPressed(sf::Keyboard::Key key);

		/// <summary>
		/// Check if a keyboard key is released
		/// </summary>
		/// <param name="key">: Keyboard key</param>
		/// <returns>True if released, otherwise false</returns>
		bool isKeyReleased(sf::Keyboard::Key key);

		/// <summary>
		/// Check if a mouse button is pressed
		/// </summary>
		/// <param name="button">: Mouse button</param>
		/// <returns>True if pressed, otherwise false</returns>
		bool isMouseButtonPressed(sf::Mouse::Button button);

		/// <summary>
		/// Check if a mouse button is released
		/// </summary>
		/// <param name="button">: Mouse button</param>
		/// <returns>True if released, otherwise false</returns>
		bool isMouseButtonReleased(sf::Mouse::Button button);

	private:
		enum KeyState
		{
			None,
			Pressed,
			Released
		};
		std::map<sf::Keyboard::Key, KeyState> keyboard_input;
		std::map<sf::Mouse::Button, KeyState> mouse_input;
	};
}

