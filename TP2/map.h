#pragma once
#include "stdafx.h"

namespace platformer
{
	class Map
	{
	public:
		Map(std::string level_string, sf::Texture* tile_textures);
		~Map();
		void draw( sf::RenderWindow* window );
		static void load_from_file(std::string level_string, Map* map_to_load);
		static std::string get_texture_string(std::string level_string);
		enum Tile
		{
			block = 1,
			empty = 2
		};
		static const int MAP_WIDTH = 32;
		static const int MAP_HEIGHT = 28;
		static const int MAP_PIXEL_SIZE = 8;
		static const int MAP_TILES = 2;
	private:
		std::string level_;
		sf::Texture* tile_texture_;
		Tile map_[MAP_HEIGHT][MAP_WIDTH];
		sf::IntRect tile_textures_[MAP_TILES];
		sf::Sprite map_sprite_;
	};
}