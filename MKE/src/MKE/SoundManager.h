#pragma once

#include <SFML/Audio.hpp>

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace mke
{
	class SoundManager
	{
	public:

		/// <summary>
		/// load a sound buffer
		/// </summary>
		/// <param name="name">sound buffer name</param>
		/// <param name="filename">sound buffer filename</param>
		void loadSoundBuffer(std::string name, std::string filename);

		/// <summary>
		/// unload a sound buffer
		/// </summary>
		/// <param name="name">sound buffer name</param>
		void unloadSoundBuffer(std::string name);

		/// <summary>
		/// play a sound
		/// </summary>
		/// <param name="name">sound buffer name</param>
		void playSound(std::string name);

		/// <summary>
		/// play a sound
		/// </summary>
		/// <param name="name">sound buffer name</param>
		/// <param name="settings">lambda for sound settings</param>
		void playSound(std::string name, std::function<void(sf::Sound&)> settings);

		/// <summary>
		/// must be called at the start of the main loop so that sounds can be disposed of
		/// </summary>
		void update();

		/// <summary>
		/// set music filename
		/// </summary>
		/// <param name="name">music name</param>
		/// <param name="filename">music filename</param>
		void setMusicFilename(std::string name, std::string filename);

		/// <summary>
		/// get music filename
		/// </summary>
		/// <param name="name">music name</param>
		/// <returns>a string with the music filename</returns>
		std::string getMusicFilename(std::string name);

		/// <summary>
		/// get the music
		/// </summary>
		/// <returns>a reference to the music</returns>
		sf::Music& getMusic();

		/// <summary>
		/// get the music
		/// </summary>
		/// <param name="name">music name (to open from file)</param>
		/// <returns>a reference to the music (that opens from file)</returns>
		sf::Music& getMusicAs(std::string name);
	private:
		const unsigned int sounds_limit = 255;
		std::unordered_map<std::string, sf::SoundBuffer> sound_buffers;
		std::vector<std::unique_ptr<sf::Sound>> sounds;
		std::map<std::string, std::string> music_filenames;
		sf::Music music;
	};
}

