#pragma once

#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

namespace mke
{
	/// <summary>
	/// A manager class for your assets
	/// </summary>
	class AssetManager
	{
	public:

		/// <summary>
		/// Load a texture from a file
		/// </summary>
		/// <param name="name">: Texture name</param>
		/// <param name="filename">: Texture file path</param>
		void loadTexture(std::string name, std::string filename);

		/// <summary>
		/// Insert a texture
		/// </summary>
		/// <param name="name">: Texture name</param>
		/// <param name="texture">: A reference to the texture that's going to be inserted</param>
		void loadTexture(std::string name, sf::Texture& texture);

		/// <summary>
		/// Return a reference to a texture
		/// </summary>
		/// <param name="name">: Texture name</param>
		/// <returns>A reference to a texture</returns>
		sf::Texture& getTexture(std::string name);

		/// <summary>
		/// Unload a texture
		/// </summary>
		/// <param name="name">: Texture name</param>
		void unloadTexture(std::string name);

		/// <summary>
		/// A struct that stores the atlas texture as well as its frames
		/// </summary>
		struct AtlasContent
		{
			sf::Texture texture;
			std::unordered_map<std::string, sf::IntRect> frames;
		};

		/// <summary>
		/// Load an atlas from a file (the image file and the json file must be in the same directory and have the same name)
		/// </summary>
		/// <param name="name">: Atlas name</param>
		/// <param name="filename">: Atlas filename (image and json)</param>
		void loadAtlas(std::string name, std::string filename);

		/// <summary>
		/// Get a reference to the contents of an atlas (texture and frames)
		/// </summary>
		/// <param name="name">: Atlas name</param>
		/// <returns>A reference to an atlas</returns>
		AtlasContent& getAtlas(std::string name);

		/// <summary>
		/// Get the frame of an atlas
		/// </summary>
		/// <param name="atlas_name">: Atlas name</param>
		/// <param name="frame_name">: Frame name (defined in the json)</param>
		/// <returns>An sf::IntRect of the frame</returns>
		sf::IntRect getAtlasFrame(std::string atlas_name, std::string frame_name);

		/// <summary>
		/// Get the texture of an atlas
		/// </summary>
		/// <param name="name">: Atlas name</param>
		/// <returns>A reference to the texture</returns>
		sf::Texture& getAtlasTexture(std::string name);

		/// <summary>
		/// Unload an atlas
		/// </summary>
		/// <param name="name">: Atlas name</param>
		void unloadAtlas(std::string name);

		/// <summary>
		/// Load a font
		/// </summary>
		/// <param name="name">: Font name</param>
		/// <param name="filename">: Font file path</param>
		void loadFont(std::string name, std::string filename);
		
		/// <summary>
		/// Get a font
		/// </summary>
		/// <param name="name">: Font name</param>
		/// <returns>A reference to a font</returns>
		sf::Font& getFont(std::string name);

		/// <summary>
		/// Unload a font
		/// </summary>
		/// <param name="name">: Font name</param>
		void unloadFont(std::string name);

		/// <summary>
		/// A manager for custom assets
		/// </summary>
		/// <typeparam name="T">: Your asset type</typeparam>
		template<typename T> class CustomManager
		{
		public:

			/// <summary>
			/// Load a new asset
			/// </summary>
			/// <typeparam name="...Args">: Asset constructor arguments template</typeparam>
			/// <param name="name">: Asset name</param>
			/// <param name="...args">: Asset constructor arguments (if necessary)</param>
			/// <returns>A reference to the assets</returns>
			template<typename... Args>
			T& loadNew(std::string name, Args &&... args);

			/// <summary>
			/// Get an asset
			/// </summary>
			/// <param name="name">: Asset name</param>
			/// <returns>A reference to an asset</returns>
			T& get(std::string name);

			/// <summary>
			/// Unload an asset
			/// </summary>
			/// <param name="name">: Asset name</param>
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

