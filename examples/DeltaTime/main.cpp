#include <SFML/Graphics.hpp>
#include "../../MKE/src/MKE/DeltaTime.h"
#include <iostream>

int main()
{
	sf::RenderWindow win(sf::VideoMode(800, 800), "DeltaTime example", sf::Style::Close);
	win.setVerticalSyncEnabled(true);

	mke::DeltaTime dt;

	while (win.isOpen())
	{
		dt.update(); // update dt every frame
		std::cout << dt.get().asSeconds() << '\n'; // .get() returns an sf::Time which represents delta time
		for (sf::Event event; win.pollEvent(event);)
			switch (event.type)
			{
			case sf::Event::Closed:
				win.close();
				break;
			default:
				break;
			}
		win.clear();
		win.display();
	}
}