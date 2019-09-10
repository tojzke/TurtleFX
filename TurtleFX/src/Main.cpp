#include "environment.h"
#include <iostream>

int main()
{
	App app;


	sf::Thread inputThread(&App::getInput, &app);
	inputThread.launch();

	while (app.isActive())
	{
		sf::Event e;
		app.getEvent(e);
		if (e.type == sf::Event::Closed) {
			app.shutdown();
		}

		app.updateWindow();

	}

	return EXIT_SUCCESS;
}