#include "../../source/Input.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
	sf::RenderWindow win{ sf::VideoMode{ 800, 800 }, "Input example", sf::Style::Close };
	win.setFramerateLimit(0);
	win.setVerticalSyncEnabled(true);

	mke::Input input{};

	while (win.isOpen())
	{
		// update the input at the start of each frame
		input.update();

		for (sf::Event event; win.pollEvent(event);)
		{
			// process key and mouse events
			input.processEvent(event);

			switch (event.type)
			{
			case sf::Event::Closed:
				win.close();
				break;
			default:
				break;
			}
		}

		if (input.isKeyPressed(sf::Keyboard::Space))
			std::cout << "Space pressed\n";
		else if (input.isKeyReleased(sf::Keyboard::Space))
			std::cout << "Space released\n";
			
		if (input.isMouseButtonPressed(sf::Mouse::Left))
			std::cout << "Left mouse button pressed\n";
		else if (input.isMouseButtonReleased(sf::Mouse::Left))
			std::cout << "Left mouse button released\n";

		win.clear();
		win.display();
	}
	return 0;
}