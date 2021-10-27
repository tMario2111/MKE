#pragma

#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>

#include "AssetManager.h"

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
		/// <param name="sprite">: Sprite that's going to be animated</param>
		Animation(sf::Sprite& sprite);

		/// <summary>
		/// Set the atlas
		/// </summary>
		/// <param name="atlas">: Atlas that's going to be used</param>
		void setAtlas(mke::AssetManager::AtlasContent& atlas);

		/// <summary>
		/// Load an animation from a json file
		/// </summary>
		/// <param name="filename">: Path to json file that contains animation data</param>
		void loadFromFile(std::string filename);

		/// <summary>
		/// Load an animation from a json object 
		/// </summary>
		/// <param name="json">: Json object that contains animation data</param>
		void loadFromJson(nlohmann::json& json);

		/// <summary>
		/// Add a new frame 
		/// </summary>
		/// <param name="frame_name">: Frame name (the one defined in the json file)</param>
		/// <param name="duration">: Frame duration</param>
		void addFrame(std::string frame_name, sf::Time duration);

		/// <summary>
		/// Set the sprite frame manually (useful if animation is not running)
		/// </summary>
		/// <param name="frame_name">: Frame name</param>
		void setSpriteFrame(std::string frame_name);

		/// <summary>
		/// Set the sprite frame manually (useful if animation is not running)
		/// </summary>
		/// <param name="index">: Frame index (depends of the order in which the frames were added)</param>
		void setSpriteFrame(unsigned int index);

		/// <summary>
		/// Reset the animation
		/// </summary>
		void reset();

		/// <summary>
		/// Run the animation
		/// </summary>
		/// <param name="dt">: Delta time </param>
		void run(sf::Time dt);

		/// <summary>
		/// Get the number of loops that the animation went through
		/// </summary>
		/// <returns>How many times the animation looped</returns>
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