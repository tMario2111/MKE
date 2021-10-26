#pragma

#include <SFML/Graphics.hpp>

#include "AssetManager.h"

#include <nlohmann/json.hpp>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace mke
{
	class Animation
	{
	public:

		/// <summary>
		/// Default constructor 
		/// </summary>
		/// <param name="sprite">sprite that's going to be animated</param>
		Animation(sf::Sprite& sprite);

		/// <summary>
		/// Set the atlas
		/// </summary>
		/// <param name="atlas">the atlas that's going to be used</param>
		void setAtlas(mke::AssetManager::AtlasContent& atlas);

		/// <summary>
		/// Load an animation from a json file (check documentation for format)
		/// </summary>
		/// <param name="filename"></param>
		void loadFromFile(std::string filename);

		/// <summary>
		/// Load an animation from a json object 
		/// </summary>
		/// <param name="json"></param>
		void loadFromJson(nlohmann::json& json);

		/// <summary>
		/// Add a new frame 
		/// </summary>
		/// <param name="frame_name">the frame name (the one defined in the json file)</param>
		/// <param name="duration">the frame duration</param>
		void addFrame(std::string frame_name, sf::Time duration);

		/// <summary>
		/// Set the sprite frame manually (useful if animation is not running)
		/// </summary>
		/// <param name="frame_name">the frame name</param>
		void setSpriteFrame(std::string frame_name);

		/// <summary>
		/// Set the sprite frame manually (useful if animation is not running)
		/// </summary>
		/// <param name="index">the frame index (depends of the order in which the frames were added)</param>
		void setSpriteFrame(unsigned int index);

		/// <summary>
		/// Reset the animation
		/// </summary>
		void reset();

		/// <summary>
		/// Run the animation
		/// </summary>
		/// <param name="dt"></param>
		void run(sf::Time dt);

		/// <summary>
		/// Get the number of loops that the animation went through
		/// </summary>
		/// <returns>how many times the animation looped</returns>
		unsigned int getLoopCount();
	private:
		sf::Sprite& sprite;
		mke::AssetManager::AtlasContent* atlas = nullptr;
		sf::Time clock = sf::seconds(0.f);
		struct Frame
		{
			std::string name;
			sf::Time duration;
		};
		std::vector<Frame> frames;
		unsigned int frames_index = 0;
		unsigned int loops = 0;
	};
}