#include "../../source/ShadowCaster.hpp"

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow win{ sf::VideoMode{ 800, 800 }, "ShadowCaster example", sf::Style::Close };
	win.setFramerateLimit(0);
	win.setVerticalSyncEnabled(true);

	mke::ShadowCaster shadow_caster{ win };

	shadow_caster.setRadius(static_cast<float>(win.getSize().x + win.getSize().y)); 

	shadow_caster.edges.push_back(std::make_pair(sf::Vector2f{ 100.f, 100.f }, sf::Vector2f{ 100.f, 700.f })); 
	shadow_caster.edges.push_back(std::make_pair(sf::Vector2f{ 700.f, 100.f }, sf::Vector2f{ 700.f, 700.f }));

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

		// the reference point is the center of the screen
		shadow_caster.update(sf::Vector2f{ win.getSize().x / 2.f, win.getSize().y / 2.f }); 

		win.clear(sf::Color::White);
		win.draw(shadow_caster);
		win.display();
	}
	return 0;
}