#include <SFML/Audio.hpp>
#include "../../MKE/src/MKE/SoundManager.h"

int main()
{
	mke::SoundManager sounds;
	sounds.loadSoundBuffer("explosion", "../examples/SoundManager/explosion.wav");

	sounds.setMusicFilename("explosion", "../examples/SoundManager/explosion.wav");
	sounds.getMusic().setLoop(true);
	sounds.getMusic().setPitch(0.5f);
	sounds.getMusic().openFromFile(sounds.getMusicFilename("explosion"));
	sounds.getMusic().play();

	// or simply
	// sounds.getMusicAs("explosion").play();

	while (true)
	{
		sounds.update(); // update sounds (cleanup)

		sounds.playSound("explosion"); // play sound without settings
		
		sf::sleep(sf::seconds(0.25f));

		sounds.playSound("explosion", [](sf::Sound& sound) // play sound with settings
			{
				sound.setVolume(50.f);
				sound.setPitch(1.25f);
			});

		sf::sleep(sf::seconds(0.25f));
	}
	return 0;
}