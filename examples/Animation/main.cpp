#include "../../source/Animation.hpp"
#include "../../source/AssetManager.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

int main()
{
	sf::RenderWindow win{ sf::VideoMode{ 800, 800 }, "Animation example", sf::Style::Close };
	win.setFramerateLimit(0);
	win.setVerticalSyncEnabled(true);

	mke::AssetManager assets{};
	assets.loadAtlas("run_right", "examples/Animation/spritesheet.png");

	sf::Sprite sprite{};
	
	mke::Animation animation{};
	animation.setSprite(sprite);
	animation.setAtlas(assets.getAtlas("run_right"));
	animation.setSpriteFrame("RunRight01.png");

	// load animation from json file
	animation.loadFromFile("examples/Animation/animation.json");

	// or initialize animation directly in code
	/*
	for (int i = 1; i <= 4; i++)
		animation.addFrame("RunRight0" + std::to_string(i) + ".png", sf::seconds(0.15f));
	*/

	sf::Time dt{};
	sf::Clock clock{};

	while (win.isOpen())
	{
		dt = clock.restart();
		for (sf::Event event; win.pollEvent(event);)
			switch (event.type)
			{
			case sf::Event::Closed:
				win.close();
				break;
			default:
				break;
			}

		animation.run(dt);
		std::cout << animation.getLoopCount() << '\n';

		win.clear();
		win.draw(sprite);
		win.display();
	}
	return 0;
}