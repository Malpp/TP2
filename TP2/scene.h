#pragma once
#include "stdafx.h"
#include "resourcehandler.h"

/// <summary>
/// The abstract scene
/// </summary>
namespace platformer
{
	class Scene
	{
	public:
		//Scene types
		enum scenes
		{
			MENU, LEVEL1, EXIT
		};

		Scene(sf::RenderWindow* window);
		virtual ~Scene()
		{}  //Pour que le destructeur de l'objet en mémoire soit apellé
		virtual scenes run();

		//La boucle de jeu est maintenant gérée par la scène
		virtual bool init() = 0;
		virtual void input() = 0;
		virtual void update(float delta_time) = 0;
		virtual void draw() = 0;

	protected:

		void close();

		sf::RenderWindow* window_;
		sf::Event event;

		scenes returned_scene_;
		ResourceHandler resource_handler_;
		bool isRunning;
		sf::Clock clock;
	};
}