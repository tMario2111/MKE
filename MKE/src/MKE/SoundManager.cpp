#include "SoundManager.h"

namespace mke
{
	void SoundManager::loadSoundBuffer(const std::string& name, const std::string& filename)
	{
		if (sound_buffers.count(name) == 1)
			return;
		if (!sound_buffers[name].loadFromFile(filename))
		{
			std::cerr << "Error: mke::SoundManager::loadSoundBuffer(): sound buffer with name \"" << name <<
				"\" and filename \"" << filename << "\" could not be loaded\n";
			exit(-1);
		}
	}
	void SoundManager::unloadSoundBuffer(const std::string& name)
	{
		sound_buffers.erase(name);
	}
	void SoundManager::playSound(const std::string& name)
	{
		if (sounds.size() == sounds_limit)
			sounds.erase(sounds.begin());
		sounds.push_back(std::make_unique<sf::Sound>(sound_buffers[name]));
		sounds[sounds.size() - 1]->play();
	}
	void SoundManager::playSound(const std::string& name, std::function<void(sf::Sound&)> settings)
	{
		if (sounds.size() == sounds_limit)
			sounds.erase(sounds.begin());
		sounds.push_back(std::make_unique<sf::Sound>(sound_buffers[name]));
		sf::Sound& sound = *sounds[sounds.size() - 1];
		settings(sound);
		sound.play();
	}
	void SoundManager::update()
	{
		sounds.erase(std::remove_if(sounds.begin(), sounds.end(), [](std::unique_ptr<sf::Sound>& sound)
			{
				return sound->getStatus() == sf::Sound::Stopped;
			}), sounds.end());
	}
	void SoundManager::setMusicFilename(const std::string& name, const std::string& filename)
	{
		music_filenames[name] = filename;
	}
	std::string SoundManager::getMusicFilename(const std::string& name)
	{
		return music_filenames[name];
	}
	sf::Music& SoundManager::getMusic()
	{
		return music;
	}
	sf::Music& SoundManager::getMusicAs(const std::string& name)
	{
		music.stop();
		music.openFromFile(music_filenames[name]);
		return music;
	}
}
