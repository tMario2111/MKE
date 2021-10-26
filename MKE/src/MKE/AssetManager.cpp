#include "AssetManager.h"

namespace mke
{
	void AssetManager::loadTexture(std::string name, std::string filename)
	{
		if (textures.count(name) == 1)
			return;
		if (!textures[name].loadFromFile(filename))
		{
			std::cerr << "Error: mke::AssetManager::loadTexture(): texture with name \"" << name << 
				"\" and filename \"" << filename << "\" could not be loaded\n";
			exit(-1);
		}
	}
	void AssetManager::loadTexture(std::string name, sf::Texture& texture)
	{
		if (textures.count(name) == 1)
			return;
		textures[name] = texture;
	}
	sf::Texture& AssetManager::getTexture(std::string name)
	{
		if (textures.count(name) == 0)
		{
			std::cerr << "Error: mke::AssetManager::getTexture(): texture with name \"" << name << "\" does not exist\n";
			exit(-1);
		}
		return textures[name];
	}
	void AssetManager::unloadTexture(std::string name)
	{
		textures.erase(name);
	}
	void AssetManager::loadAtlas(std::string name, std::string filename)
	{
		if (atlases.count(name) == 1)
			return;
		if (!atlases[name].texture.loadFromFile(filename))
		{
			std::cerr << "Error: mke::AssetManager::loadAtlas(): atlas with name \"" << name <<
				"\" and filename \"" << filename << "\" could not be loaded\n";
			exit(-1);
		}
		size_t found = filename.find_last_of(".");
		filename = filename.substr(0, found) + ".json";
		std::ifstream file(filename);
		if (!file)
		{
			std::cerr << "Error: mke::AssetManager::loadAtlas(): could not find json for atlas with name \"" << name <<
				" and filename \"" << filename << '\n';
			exit(-1);
		}
		nlohmann::json json;
		file >> json;
		file.close();
		for (auto& i : json["frames"].items())
		{
			sf::IntRect& rect = atlases[name].frames[i.key()];
			rect.left = i.value()["frame"]["x"];
			rect.top = i.value()["frame"]["y"];
			rect.width = i.value()["frame"]["w"];
			rect.height = i.value()["frame"]["h"];
		}
	}
	AssetManager::AtlasContent& AssetManager::getAtlas(std::string name)
	{
		return atlases[name];
	}
	sf::IntRect AssetManager::getAtlasFrame(std::string atlas_name, std::string frame_name)
	{
		if (atlases.count(atlas_name) == 0)
		{
			std::cerr << "Error: mke::AssetManager::getAtlasFrame(): atlas with name \"" << atlas_name << "\" does not exist\n";
			exit(-1);
		}
		if (atlases[atlas_name].frames.count(frame_name) == 0)
		{
			std::cerr << "Error: mke::AssetManager::getAtlasFrame(): frame with name \"" << frame_name << "\" does not exist\n";
			exit(-1);
		}
		return atlases[atlas_name].frames[frame_name];
	}
	sf::Texture& AssetManager::getAtlasTexture(std::string name)
	{
		if (atlases.count(name) == 0)
		{
			std::cerr << "Error: mke::AssetManager::getAtlas(): atlas with name \"" << name << "\" does not exist\n";
			exit(-1);
		}
		return atlases[name].texture;
	}
	void AssetManager::unloadAtlas(std::string name)
	{
		atlases.erase(name);
	}
	void AssetManager::loadFont(std::string name, std::string filename)
	{
		if (fonts.count(name) == 1)
			return;
		if (!fonts[name].loadFromFile(filename))
		{
			std::cerr << "Error: mke::AssetManager::loadFont(): font with name \"" << name <<
				"\" and filename \"" << filename << "\" could not be loaded\n";
			exit(-1);
		}
	}
	sf::Font& AssetManager::getFont(std::string name)
	{
		return fonts[name];
	}
	void AssetManager::unloadFont(std::string name)
	{
		fonts.erase(name);
	}
}