#include "stdafx.h"
#include "gameobject.h"
#include "Game.h"

platformer::GameObject::GameObject(const float jump_strength, const float jump_cooldown, const float move_speed, const sf::Vector2f& pos, const float angle, sf::Texture* texture) 
: Moveable(pos, angle, texture)
{
	can_jump_ = true;
	move_direction_ = 0;
	jump_timer_ = 0;
	jump_cooldown_ = jump_cooldown;
	jump_strength_ = jump_strength;
	move_speed_ = move_speed;
}

void platformer::GameObject::update(float delta_time)
{
	if(!can_jump_)
	{
		jump_timer_ += delta_time;
		if(jump_timer_ > jump_cooldown_)
		{
			jump_timer_ = 0;
			can_jump_ = true;
		}
	}

	velocity_.y += GRAVITY * delta_time;

	velocity_.x = move_speed_ * move_direction_;

	move_direction_ = 0;

	Moveable::update(delta_time);
}

void platformer::GameObject::left()
{
	move_direction_ -= 1;
}

void platformer::GameObject::right()
{
	move_direction_ += 1;
}

void platformer::GameObject::jump()
{
	if(can_jump_)
	{
		can_jump_ = false;
		velocity_.y = -jump_strength_;
	}
}

sf::Vector2f platformer::GameObject::getNextMove(float delta_time)
{
	return velocity_;
}

bool platformer::GameObject::isAtEdge()
{
	sf::Vector2f current_pos = sprite_.getPosition();
	if (current_pos.x > platformer::Game::GAME_WIDTH + half_texture_size_.x ||
		current_pos.x < -half_texture_size_.x ||
		current_pos.y > platformer::Game::GAME_HEIGHT + half_texture_size_.y ||
		current_pos.y < -half_texture_size_.y)
		return true;

	return false;
}

void platformer::GameObject::handleEdge()
{
	sf::Vector2f current_pos = sprite_.getPosition();
	if(current_pos.x > platformer::Game::GAME_WIDTH + half_texture_size_.x)
	{
		current_pos.x -= Game::GAME_WIDTH + half_texture_size_.x * 2;
	}
	else if(current_pos.x < -half_texture_size_.x)
	{
		current_pos.x += Game::GAME_WIDTH + half_texture_size_.x * 2;
	}

	if (current_pos.y > platformer::Game::GAME_HEIGHT + half_texture_size_.y)
	{
		current_pos.y -= Game::GAME_HEIGHT + half_texture_size_.y * 2;
	}
	else if (current_pos.y < -half_texture_size_.y)
	{
		current_pos.y += Game::GAME_HEIGHT + half_texture_size_.y * 2;
	}
	sprite_.setPosition(current_pos);
}
