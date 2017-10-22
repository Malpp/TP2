#pragma once
#include "stdafx.h"

namespace platformer {
	class ResourceHandler
	{
	public:
		ResourceHandler();
		~ResourceHandler();
		sf::Texture* add_texture(std::string path);
	private:
		std::vector<sf::Texture*> textures_;
	};
}