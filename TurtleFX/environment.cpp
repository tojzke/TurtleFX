#include "SFML/Graphics.hpp"
#include "environment.h"
#include "turtle.h"

const uint32_t App::HEIGHT = 800;
const uint32_t App::WIDTH = 640;

const std::string App::TITLE = "TurtleFX";

App::App()
{
	
	pWindow = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE);
	pWindow->setFramerateLimit(60);

	float radius = 20.0f;

	pTurtle = new Turtle(static_cast<float>(WIDTH) / 2 + radius / 2,
						 static_cast<float>(HEIGHT) / 2 + radius / 2,
						 radius);


	isRunning = true;
}

void App::draw()
{
	pWindow->clear();
	pWindow->draw(*(pTurtle->getShape()));
	pWindow->display();
}

void App::shutdown()
{
	isRunning = false;
	pWindow->close();
	delete pWindow;
}

void App::getEvent(sf::Event& event)
{
	pWindow->pollEvent(event);
}

void App::getInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		auto line = pTurtle->move(1.0f);
		sf::Vertex temp_line[2];
		temp_line[0] = line[0];
		temp_line[1] = line[1];
		pWindow->draw(temp_line, 2, sf::Lines);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		pTurtle->rotateLeft(2.0f);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		pTurtle->rotateRight(2.0f);
	}
}

bool App::isActive()
{
	return isRunning;
}
