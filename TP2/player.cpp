#include "stdafx.h"
#include "player.h"

const float platformer::Player::move_speed_ = 500;
const float platformer::Player::jump_strength_ = 1200;
const float platformer::Player::jump_cooldown_ = 0.5f;

platformer::Player::Player(const sf::Vector2f& pos, float angle, sf::Texture* texture)
	: GameObject(jump_strength_, jump_cooldown_, move_speed_, pos, angle, texture)
{

}
