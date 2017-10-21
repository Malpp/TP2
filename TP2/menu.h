#pragma once
#include "stdafx.h"
#include "scene.h"

namespace platformer
{
	class Menu : public Scene
	{
	public:
		Menu(sf::RenderWindow* window)
			: Scene(window)
		{
		}

		bool init() override;
		void input() override;
		void update(float delta_time) override;
		void draw() override;
	private:
		sf::Sprite ben_sprite_;
	};
}
