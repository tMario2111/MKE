#include <SFML/Graphics.hpp>
#include "../../MKE/src/MKE/ParticleManager.h"
#include "../../MKE/src/MKE/DeltaTime.h"

int main()
{
	sf::RenderWindow win(sf::VideoMode(800, 800), "ParticleManager example", sf::Style::Close);
	win.setVerticalSyncEnabled(true);

	mke::DeltaTime dt;

	mke::ParticleManager particle_manager;
	
	mke::ParticleManager::Emitter emitter1;
	emitter1.active = true;
	emitter1.position = sf::Vector2f(win.getSize().x / 2.f, win.getSize().y / 2.f);
	emitter1.direction = 0.f;
	emitter1.direction_offset = std::make_pair(-60.f, 60.f);
	emitter1.lifetime_range = std::make_pair(sf::seconds(0.5f), sf::seconds(2.f));
	emitter1.particles_per_second = std::make_pair(100, 1000);
	emitter1.speed_range = std::make_pair(50.f, 200.f);
	emitter1.colors = {sf::Color::Red, sf::Color::Yellow, sf::Color::Blue};
	particle_manager.addEmitter(emitter1);

	mke::ParticleManager::Emitter emitter2(emitter1); // copy settings from first emitter
	emitter2.active = true;
	emitter2.direction = 180.f;
	particle_manager.addEmitter(emitter2);

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

		particle_manager.update(dt.get());

		win.clear();
		win.draw(particle_manager);
;		win.display();
	}
	particle_manager.eraseEmitter(emitter1);
	particle_manager.eraseEmitter(emitter2);
	return 0;
}