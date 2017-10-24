#include "stdafx.h"
#include "map.h"
#include <fstream>


platformer::Map::Map(std::string level_string, sf::Texture* tile_textures)
{
	level_ = level_string;
	tile_texture_ = tile_textures;
	map_sprite_ = sf::Sprite( *tile_textures );
	//map_sprite_.setTexture( *tile_textures );
}

platformer::Map::~Map()
{
}

void platformer::Map::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < MAP_WIDTH; ++i)
	{
		for (int j = 0; j < MAP_HEIGHT; ++j)
		{
			map_sprite_.setPosition( i * MAP_PIXEL_SIZE, j * MAP_PIXEL_SIZE );
			map_sprite_.setTextureRect( tile_textures_[map_[j][i] - 1] );
			window->draw( map_sprite_ );
		}
	}
}

void platformer::Map::load_from_file(std::string level_string, Map* map_to_load)
{
	for (int i = 0; i < MAP_TILES; i++)
	{
		map_to_load->tile_textures_[i] = sf::IntRect(MAP_PIXEL_SIZE * i, 0, MAP_PIXEL_SIZE, MAP_PIXEL_SIZE);
	}

	std::ifstream level_file( "Assets/Levels/Data/"+ level_string + ".txt" );
	std::string content;

	int height_counter = 0;
	int width_counter = 0;

	while (level_file >> content)
	{
		//std::cout << content << "\n";
		for (char& c : content)
		{
			if(c >= '0' && c <= '9')
			{
				map_to_load->map_[height_counter][width_counter] = static_cast<Tile>(c - 48);
				++width_counter;
			}
		}

		if(width_counter != MAP_WIDTH)
		{
			throw new std::length_error( "Invalid map width" );
		}
		width_counter = 0;

		++height_counter;
	}

	if (height_counter != MAP_HEIGHT)
	{
		throw new std::length_error( "Invalid map height" );
	}
}

std::string platformer::Map::get_texture_string(std::string level_string)
{
	return "Levels/Textures/" + level_string + ".png";
}
