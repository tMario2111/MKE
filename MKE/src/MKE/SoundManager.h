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
		/// Load a sound buffer
		/// </summary>
		/// <param name="name">: Sound buffer name</param>
		/// <param name="filename">: Sound buffer file path</param>
		void loadSoundBuffer(const std::string& name, const std::string& filename);

		/// <summary>
		/// Unload a sound buffer
		/// </summary>
		/// <param name="name">: Sound buffer name</param>
		void unloadSoundBuffer(const std::string& name);

		/// <summary>
		/// Play a sound
		/// </summary>
		/// <param name="name">: Sound buffer name</param>
		void playSound(const std::string& name);

		/// <summary>
		/// Play a sound
		/// </summary>
		/// <param name="name">: Sound buffer name</param>
		/// <param name="settings">: Lambda for sound settings</param>
		void playSound(const std::string& name, std::function<void(sf::Sound&)> settings);

		/// <summary>
		/// Must be called at the start of the main loop so that sounds can be disposed of
		/// </summary>
		void update();

		/// <summary>
		/// Set music filename
		/// </summary>
		/// <param name="name">: Music name</param>
		/// <param name="filename">: Music file path</param>
		void setMusicFilename(const std::string& name, const std::string& filename);

		/// <summary>
		/// Get music filename
		/// </summary>
		/// <param name="name">: Music name</param>
		/// <returns>A string with the music file path</returns>
		std::string getMusicFilename(const std::string& name);

		/// <summary>
		/// Get the music
		/// </summary>
		/// <returns>A reference to the music</returns>
		sf::Music& getMusic();

		/// <summary>
		/// Get the music
		/// </summary>
		/// <param name="name">: Music name (to open from file)</param>
		/// <returns>A reference to the music (that opens from file)</returns>
		sf::Music& getMusicAs(const std::string& name);
	private:
		const unsigned int sounds_limit = 255;
		std::unordered_map<std::string, sf::SoundBuffer> sound_buffers;
		std::vector<std::unique_ptr<sf::Sound>> sounds;
		std::map<std::string, std::string> music_filenames;
		sf::Music music;
	};
}

