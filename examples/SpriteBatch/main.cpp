#include "../../source/SpriteBatch.hpp"

#include <SFML/Graphics.hpp>

#include <vector>

int main()
{
	sf::RenderWindow win{ sf::VideoMode{ 800, 800 }, "SpriteBatch example", sf::Style::Close };
	win.setFramerateLimit(0);
	win.setVerticalSyncEnabled(true);

	sf::Texture texture{};
	if (!texture.loadFromFile("examples/SpriteBatch/circle.png"))
		return EXIT_FAILURE;
	
	std::vector<sf::Sprite> vec{}; // dummy sprites
	for (int i = 0; i < 100; i++)
	{
		sf::Sprite sprite{ texture };
		sprite.setScale(0.25f, 0.25f);
		sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
		// Only using rand() because I don't really care about the position
		// For real random please use mke::Random
		sprite.setPosition(static_cast<float>(rand() % win.getSize().x), static_cast<float>(rand() % win.getSize().y));
		vec.push_back(sprite);
	}

	mke::SpriteBatch batch{};

	while (win.isOpen())
	{
		for (sf::Event event{}; win.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				win.close();
				break;
			default:
				break;
			}
		}
		
		batch.clear();
		for (const auto& i : vec)
			batch.append(i);

		win.clear();
		win.draw(batch, &texture);
		win.display();
	}
	return 0;
}