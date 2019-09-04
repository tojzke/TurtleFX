#include "environment.h"
#include <iostream>

int main()
{
	App app;


	/*sf::Thread inputThread(&App::getInput, &app);
	inputThread.launch();
	*/
	while (app.isActive())
	{
		sf::Event e;
		app.getEvent(e);
		if (e.type == sf::Event::Closed) {
			app.shutdown();
			break;
		}
		else if (e.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				app.wow();
			}
		}
		

		app.updateWindow();

	}

	return EXIT_SUCCESS;
}