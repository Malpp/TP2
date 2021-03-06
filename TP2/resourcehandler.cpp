#include "stdafx.h"
#include "resourcehandler.h"
#include <windows.h>

platformer::ResourceHandler::ResourceHandler()
{

}

platformer::ResourceHandler::~ResourceHandler()
{
	for (sf::Texture* texture : textures_)
	{
		delete texture;
	}
}

sf::Texture* platformer::ResourceHandler::add_texture(std::string path)
{
	sf::Texture* texture_to_load_ = new sf::Texture;
	if (!texture_to_load_->loadFromFile( "Assets/" + path ))
	{
		delete texture_to_load_;
		throw std::invalid_argument( path + " not found" );
	}
	textures_.push_back( texture_to_load_ );
	return texture_to_load_;
}
