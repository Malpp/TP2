#pragma once
#include "stdafx.h"
#include "moveable.h"

namespace platformer
{
	class GameObject : public platform::Moveable
	{
	public:
		GameObject(float jump_strength, float jump_cooldown, float move_speed, const sf::Vector2f& pos, float angle, sf::Texture* texture);
		void update(float delta_time_) override;

		void left();
		void right();
		void jump();

		const float DRAG = 0.99f;
		const float GRAVITY = 1000;

	protected:
		sf::Vector2f velocity_;
		sf::Vector2f getNextMove(float delta_time_) override;
		bool can_jump_;
		float jump_timer_;
		float jump_cooldown_;
		float jump_strength_;
		float move_speed_;
		int move_direction_;
		bool isAtEdge() override;
		void handleEdge() override;
	};
}
