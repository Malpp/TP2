#pragma once
#include "stdafx.h"
#include "gameobject.h"

namespace platformer
{
	class Player : public GameObject
	{
	public:
		Player(const sf::Vector2f& pos, float angle, sf::Texture* texture);
		static const float move_speed_;
		static const float jump_strength_;
		static const float jump_cooldown_;
	};
}
