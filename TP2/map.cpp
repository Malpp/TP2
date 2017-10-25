#include "stdafx.h"
#include "map.h"
#include <fstream>


platformer::Map::Map( int level, sf::Texture* tile_textures )
{
	level_ = level;
	tile_texture_ = tile_textures;
	map_sprite_ = sf::Sprite( *tile_textures );

	debug_rect_ = sf::RectangleShape( sf::Vector2f( MAP_PIXEL_SIZE, MAP_PIXEL_SIZE ) );
	debug_rect_.setFillColor( sf::Color::Transparent );
	debug_rect_.setOutlineColor( sf::Color::Red );
	debug_rect_.setOutlineThickness( 1 );
}

platformer::Map::~Map()
{}

void platformer::Map::draw( sf::RenderWindow* window )
{
	for (int i = 0; i < MAP_WIDTH; ++i)
	{
		for (int j = 0; j < MAP_HEIGHT; ++j)
		{
			map_sprite_.setPosition( i * MAP_PIXEL_SIZE, j * MAP_PIXEL_SIZE );
			map_sprite_.setTextureRect( tile_textures_[map_[j][i]] );
			//window->draw( map_sprite_ );
		}
	}

	for (int i = 0; i < MAP_WIDTH; ++i)
	{
		for (int j = 0; j < MAP_HEIGHT; ++j)
		{
			if (collision_map_[j][i])
			{
				debug_rect_.setPosition( i * MAP_PIXEL_SIZE, j * MAP_PIXEL_SIZE );
				window->draw( debug_rect_ );
			}
		}
	}

}

bool platformer::Map::check_collision( sf::Vector2f pos )
{
	//std::cout << "Collision at: " << pos.x << ", " << pos.y << "\n";
	last_pos_.x = pos.x / 8;
	last_pos_.y = pos.y / 8;
	return collision_map_[(int)last_pos_.y][(int)last_pos_.x];
}

void platformer::Map::load_from_file( std::string level_string, Map* map_to_load )
{
	for (int i = 0; i < MAP_TILES; i++)
	{
		map_to_load->tile_textures_[i] = sf::IntRect( MAP_PIXEL_SIZE * i, 0, MAP_PIXEL_SIZE, MAP_PIXEL_SIZE );
	}

	std::ifstream level_file( "Assets/Levels/Data/" + level_string + ".txt" );
	std::string content;

	int height_counter = 0;
	int width_counter = 0;

	while (level_file >> content)
	{
		//std::cout << content << "\n";
		for (char& c : content)
		{
			if (c >= '0' && c <= '9')
			{
				map_to_load->map_[height_counter][width_counter] = c - 48;
				++width_counter;
			}
		}

		if (width_counter != MAP_WIDTH)
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

std::string platformer::Map::get_texture_string( std::string level_string )
{
	return "Levels/Textures/" + level_string + ".png";
}
