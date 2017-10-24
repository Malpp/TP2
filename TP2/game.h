#pragma once
#include "stdafx.h"
#include "resourcehandler.h"
#include "scene.h"

namespace platformer
{

	class Game
	{

	public:
		//Add new vars here

	private:
		//Add new vars here
		Scene::scenes current_scene_;
		Scene* active_scene_;
		bool running = true;


	//
	//TEMPLATE STUFF BELOW
	//

	public:
		//Template variables
		Game();
		~Game();
		void run();
		static const int GAME_WIDTH = 256;
		static const int GAME_HEIGHT = 224;
		static const int CAMARA_WIDTH = 256;
		static const int CAMERA_HEIGHT = 224;
		static const int WINDOW_WIDTH = 768;
		static const int WINDOW_HEIGHT = 672;

	private:
		//Template variables
		sf::RenderWindow* window;
		sf::View view;
	};
}