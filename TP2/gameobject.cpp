#include "stdafx.h"
#include "gameobject.h"
#include "Game.h"
#include "map.h"

platformer::GameObject::GameObject(const float jump_strength, const float jump_cooldown, const float move_speed, const sf::Vector2f& pos, const float angle, sf::Texture* texture) 
: Moveable(pos, angle, texture)
{
	can_jump_ = true;
	move_direction_ = 0;
	jump_timer_ = 0;
	jump_cooldown_ = jump_cooldown;
	jump_strength_ = jump_strength;
	move_speed_ = move_speed;

	debug_location_ = sf::CircleShape( 1 );
	debug_location_.setOrigin( 0.5f, 0.5f );

	debug_rect_location_ = sf::RectangleShape( sf::Vector2f(Map::MAP_PIXEL_SIZE, Map::MAP_PIXEL_SIZE ) );
	debug_rect_location_.setFillColor( sf::Color::Transparent );
	debug_rect_location_.setOutlineColor( sf::Color::Yellow );
	debug_rect_location_.setOutlineThickness( 1 );
}

void platformer::GameObject::update(float delta_time, platformer::Map* map)
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

	map_collisions( map );

	Moveable::update(delta_time, map);
}

void platformer::GameObject::draw(sf::RenderTarget& window)
{
	//Moveable::draw( window );
	sf::Vector2f current_pos = sprite_.getPosition();
	debug_rect_location_.setPosition( (int)(current_pos.x / Map::MAP_PIXEL_SIZE) * Map::MAP_PIXEL_SIZE, (int)(current_pos.y / Map::MAP_PIXEL_SIZE) * Map::MAP_PIXEL_SIZE );
	debug_location_.setPosition( current_pos );
	window.draw( debug_rect_location_ );
	window.draw( debug_location_ );

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

void platformer::GameObject::map_collisions(Map* map)
{
	sf::Vector2f current_pos = sprite_.getPosition();
	current_pos.x += velocity_.x;
	if(map->check_collision(current_pos))
	{
		current_pos.x -= velocity_.x;
		velocity_.x = 0;
	}

	current_pos.y += velocity_.y;
	if (map->check_collision( current_pos ))
	{
		std::cout << "Collision at: " << current_pos.x << ", " << current_pos.y << "\n";
		current_pos.y -= velocity_.y;
		velocity_.y = 0;
	}

}
