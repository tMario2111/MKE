#include <SFML/Graphics.hpp>
#include "../../MKE/src/MKE/MKE.h"
#include <string>
#include <iostream>

int main()
{
	sf::RenderWindow win(sf::VideoMode(800, 800), "Animation example", sf::Style::Close);
	win.setVerticalSyncEnabled(true);

	mke::AssetManager assets;
	assets.loadAtlas("run_right", "../examples/Animation/spritesheet.png");

	sf::Sprite sprite;
	
	mke::Animation animation(sprite);
	animation.setAtlas(assets.getAtlas("run_right"));
	animation.setSpriteFrame("RunRight01.png");

	animation.loadFromFile("../examples/Animation/animation.json"); // load animation from json file
	/* or initialize animation directly in code
	for (int i = 1; i <= 4; i++)
		animation.addFrame("RunRight0" + std::to_string(i) + ".png", sf::seconds(0.15f));
	*/

	mke::DeltaTime dt;

	while (win.isOpen())
	{
		dt.update();
		for (sf::Event event; win.pollEvent(event);)
			switch (event.type)
			{
			case sf::Event::Closed:
				win.close();
				break;
			default:
				break;
			}

		animation.run(dt.get());
		std::cout << animation.getLoopCount() << '\n';

		win.clear();
		win.draw(sprite);
		win.display();
	}
	return 0;
}