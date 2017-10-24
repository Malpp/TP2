#include "stdafx.h"
#include "map.h"
#include <fstream>


platformer::Map::Map(int level, sf::Texture* tile_textures)
{
	level_ = level;
	tile_texture_ = tile_textures;
	map_sprite_ = sf::Sprite( *tile_textures );
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
			map_sprite_.setTextureRect( tile_textures_[map_[j][i]] );
			window->draw( map_sprite_ );
		}
	}
}

bool platformer::Map::check_colliion(sf::Vector2f pos)
{
	return collision_map_[(int)pos.y][(int)pos.x];
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
				map_to_load->map_[height_counter][width_counter] = c - 48;
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

	for (int i = 0; i < MAP_WIDTH; ++i)
	{
		for (int j = 0; j < MAP_HEIGHT; ++j)
		{
			map_to_load->collision_map_[j][i] = map_to_load->map_[j][i] != 0;
		}
	}
}

std::string platformer::Map::get_texture_string(std::string level_string)
{
	return "Levels/Textures/" + level_string + ".png";
}
