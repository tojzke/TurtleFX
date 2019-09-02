#include "environment.h"

int main()
{
	App app;

	while (app.isActive())
	{
		sf::Event e;
		app.getEvent(e);
		if (e.type == sf::Event::Closed) {
			app.shutdown();
			break;
		}
		else if (e.type == sf::Event::KeyPressed) {
			app.getInput();
		}

		app.draw();

	}

	return EXIT_SUCCESS;
}