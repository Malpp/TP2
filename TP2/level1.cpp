#include "stdafx.h"
#include "level1.h"


bool platformer::Level1::init()
{
	player_ = new Player(sf::Vector2f(100, 100), 0, resource_handler_.add_texture("ben.png"));
	sf::Texture* map_texture = resource_handler_.add_texture( Map::get_texture_string( "1" ) );
	map_ = new Map( "1", map_texture );
	map_->load_from_file( "1", map_ );
	return true;
}

platformer::Level1::~Level1()
{
	delete player_;
	delete map_;
}

void platformer::Level1::input()
{
	while (window_->pollEvent( event ))
	{
		//x sur la fenêtre
		if (event.type == sf::Event::Closed)
		{
			close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				returned_scene_ = MENU;
				isRunning = false;
				break;
			}
		}
	}
}

void platformer::Level1::update(float delta_time)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player_->left();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player_->right();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player_->jump();
	}

	player_->update(delta_time);
}

void platformer::Level1::draw()
{
	window_->clear();

	map_->draw( window_ );
	player_->draw(*window_);

	window_->display();
}
