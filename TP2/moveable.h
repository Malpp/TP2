#pragma once
#include "stdafx.h"
#include "drawable.h"

namespace platformer {
	class Map;
}

namespace platform
{
	class Moveable : public platformer::Drawable
	{
	public:
		virtual void update(float delta_time_, platformer::Map* map);
	protected:
		Moveable( sf::Vector2f pos, float angle, sf::Texture* texture ) : Drawable( pos, angle, texture )
		{}
		virtual sf::Vector2f getNextMove( float delta_time_ ) = 0;
		virtual bool isAtEdge();
		virtual void handleEdge();
		virtual bool check_collision(platformer::Map* map ) = 0;
		virtual void handle_collision() = 0;
	};
}
