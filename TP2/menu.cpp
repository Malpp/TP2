#include "stdafx.h"
#include "menu.h"

bool platformer::Menu::init()
{
	sf::Texture* benTexture = resource_handler_.add_texture( "ben.png" );
	ben_sprite_ = sf::Sprite( *benTexture );
	return true;
}

void platformer::Menu::input()
{
	while (window_->pollEvent( event ))
	{
		//x sur la fenêtre
		if (event.type == sf::Event::Closed)
		{
			close();
		}

		if(event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				close();
				break;
			case sf::Keyboard::Num1:
				returned_scene_ = MENU;
				isRunning = false;
				break;
			}
		}
	}
}

void platformer::Menu::update(float delta_time)
{
}

void platformer::Menu::draw()
{
	window_->clear();

	window_->draw( ben_sprite_ );

	window_->display();
}
