#pragma once
#include "stdafx.h"
#include "drawable.h"

namespace platform
{
	class Moveable : public platformer::Drawable
	{
	public:
		virtual void update( float delta_time_ );
	protected:
		Moveable( sf::Vector2f pos, float angle, sf::Texture* texture ) : Drawable( pos, angle, texture )
		{}
		virtual sf::Vector2f getNextMove( float delta_time_ ) = 0;
		virtual bool isAtEdge();
		virtual void handleEdge();
	};
}
