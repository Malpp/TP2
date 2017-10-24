#pragma once
#include "stdafx.h"
#include "scene.h"
#include "player.h"
#include "map.h"

namespace platformer
{
	class Level1 : public Scene
	{
	public:
		Level1( sf::RenderWindow* window )
			: Scene( window )
		{}
		bool init() override;
		virtual ~Level1();
		void input() override;
		void update( float delta_time ) override;
		void draw() override;
	private:
		Player* player_;
		Map* map_;
	};
}
