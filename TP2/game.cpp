#include "stdafx.h"
#include "Game.h"
#include "menu.h"
#include "level1.h"

platformer::Game::Game()
{
	//Init window and view
	window = new sf::RenderWindow( sf::VideoMode( WINDOW_WIDTH, WINDOW_HEIGHT ), "SFML", sf::Style::Close );
	view.setSize( CAMARA_WIDTH, CAMERA_HEIGHT );
	view.setCenter( GAME_WIDTH * 0.5f, GAME_HEIGHT * 0.5f );
	window->setView( view );
	srand( time( nullptr ) );
	rand();
	
	current_scene_ = Scene::MENU;
}

platformer::Game::~Game()
{
	delete window;
}

void platformer::Game::run()
{
	window->setActive( false );

	while (running)
	{
		std::cout << current_scene_ << "\n";
		switch (current_scene_)
		{
		case Scene::EXIT:
			running = false;
			break;
		case Scene::MENU:
			active_scene_ = new Menu( window );
			current_scene_ = active_scene_->run();
			break;
		case Scene::LEVEL1:
			active_scene_ = new Level1( window );
			current_scene_ = active_scene_->run();
			break;
		}

		delete active_scene_;
		active_scene_ = nullptr;
		
	}
}
