#include "stdafx.h"
#include "level1.h"

bool platformer::Level1::init()
{

	return true;
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
}

void platformer::Level1::draw()
{
	window_->clear(sf::Color::Red);

	window_->display();
}
