#pragma once

#include <SFML/Graphics.hpp>

#include <nlohmann/json.hpp>

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

namespace mke
{
	/// <summary>
	/// a manager class for your assets
	/// </summary>
	class AssetManager
	{
	public:

		/// <summary>
		/// load a texture from a file
		/// </summary>
		/// <param name="name">texture name</param>
		/// <param name="filename">texture filename</param>
		void loadTexture(std::string name, std::string filename);

		/// <summary>
		/// insert a texture
		/// </summary>
		/// <param name="name">texture name</param>
		/// <param name="texture">a reference to the texture that's going to be inserted</param>
		void loadTexture(std::string name, sf::Texture& texture);

		/// <summary>
		/// return a reference to a texture
		/// </summary>
		/// <param name="name">texture name</param>
		/// <returns>a reference to a texture</returns>
		sf::Texture& getTexture(std::string name);

		/// <summary>
		/// unload a texture
		/// </summary>
		/// <param name="name">texture name</param>
		void unloadTexture(std::string name);

		/// <summary>
		/// a struct that stores the atlas texture as well as its frames
		/// </summary>
		struct AtlasContent
		{
			sf::Texture texture;
			std::unordered_map<std::string, sf::IntRect> frames;
		};

		/// <summary>
		/// load an atlas from a file (the image file and the json file must be in the same directory and have the same name)
		/// </summary>
		/// <param name="name">atlas name</param>
		/// <param name="filename">atlas filename (image and json)</param>
		void loadAtlas(std::string name, std::string filename);

		/// <summary>
		/// get a reference to the contents of an atlas (texture and frames)
		/// </summary>
		/// <param name="name">atlas name</param>
		/// <returns>a reference to an atlas</returns>
		AtlasContent& getAtlas(std::string name);

		/// <summary>
		/// get the frame of an atlas
		/// </summary>
		/// <param name="atlas_name">atlas name</param>
		/// <param name="frame_name">frame name (defined in the json)</param>
		/// <returns>an sf::IntRect of the frame</returns>
		sf::IntRect getAtlasFrame(std::string atlas_name, std::string frame_name);

		/// <summary>
		/// get the texture of an atlas
		/// </summary>
		/// <param name="name">atlas name</param>
		/// <returns>a reference to the texture</returns>
		sf::Texture& getAtlasTexture(std::string name);

		/// <summary>
		/// unload an atlas
		/// </summary>
		/// <param name="name">atlas name</param>
		void unloadAtlas(std::string name);

		/// <summary>
		/// load a font
		/// </summary>
		/// <param name="name">font name</param>
		/// <param name="filename">font filename</param>
		void loadFont(std::string name, std::string filename);
		
		/// <summary>
		/// get a font
		/// </summary>
		/// <param name="name">font name</param>
		/// <returns>a reference to a font</returns>
		sf::Font& getFont(std::string name);

		/// <summary>
		/// unload a font
		/// </summary>
		/// <param name="name">font name</param>
		void unloadFont(std::string name);

		/// <summary>
		/// a manager for custom assets
		/// </summary>
		/// <typeparam name="T">your asset type</typeparam>
		template<typename T> class CustomManager
		{
		public:

			/// <summary>
			/// load a new assets
			/// </summary>
			/// <typeparam name="...Args"></typeparam>
			/// <param name="name">asset name</param>
			/// <param name="...args">asset constructor arguments (if necessary)</param>
			/// <returns></returns>
			template<typename... Args>
			T& loadNew(std::string name, Args &&... args);

			/// <summary>
			/// get an asset
			/// </summary>
			/// <param name="name">asset name</param>
			/// <returns>a reference to an asset</returns>
			T& get(std::string name);

			/// <summary>
			/// unload an asset
			/// </summary>
			/// <param name="name">asset name</param>
			void unload(std::string name);
		private:
			std::unordered_map<std::string, std::unique_ptr<T>> map;
		};
	private:
		std::unordered_map<std::string, sf::Texture> textures;
		std::unordered_map<std::string, AtlasContent> atlases;
		std::unordered_map<std::string, sf::Font> fonts;
	
	};
	template<typename T>
	template<typename ...Args>
	inline T& AssetManager::CustomManager<T>::loadNew(std::string name, Args && ...args)
	{
		if (map.count(name) == 1)
			std::exit(-1);
		map[name] = std::make_unique<T>(std::forward<Args>(args)...);
		return *map[name].get();
	}
	template<typename T>
	inline T& AssetManager::CustomManager<T>::get(std::string name)
	{
		return *map[name].get();
	}
	template<typename T>
	inline void AssetManager::CustomManager<T>::unload(std::string name)
	{
		map.erase(name);
	}
}

