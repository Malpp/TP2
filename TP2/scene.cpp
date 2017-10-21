#include "stdafx.h"
#include "scene.h"

platformer::Scene::Scene(sf::RenderWindow* window)
{
	isRunning = true;
	window_ = window;
	returned_scene_ = EXIT;
}

platformer::Scene::scenes platformer::Scene::run()
{
	init();

	while (isRunning)
	{
		input();
		float delta_time = clock.restart().asSeconds();
		update(delta_time);
		draw();
	}

	return returned_scene_;
}

void platformer::Scene::close()
{
	isRunning = false;
	returned_scene_ = EXIT;
}
