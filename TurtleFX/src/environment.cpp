#include <iostream>
#include <string>
#include <SFML/System.hpp>

#include "SFML/Graphics.hpp"
#include "environment.h"
#include "turtle.h"

const uint32_t App::HEIGHT = 1000;
const uint32_t App::WIDTH = 1000;

const std::string App::TITLE = "TurtleFX";


App::App():
	m_mutex()
{
	
	pWindow = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE);
	pWindow->setFramerateLimit(60);

	float radius = 20.0f;

	pTurtle = new Turtle(static_cast<float>(WIDTH) / 2 + radius,
						 static_cast<float>(HEIGHT) / 2 + radius,
						 radius);


	isRunning = true;
}

App::~App()
{
	delete pWindow;
	delete pTurtle;
}

void App::updateWindow()
{
	m_mutex.lock();
	pWindow->clear();
	auto lines = pTurtle->getTrail()->getData();
	if (lines.getVertexCount() != 0) {
		pWindow->draw(&lines[0], lines.getVertexCount(), sf::Lines);
	}
	if (pTurtle->isVisible()) {
		pWindow->draw(*(pTurtle->getShape()));
		pWindow->draw(pTurtle->getSprite());
	}
	pWindow->display();
	m_mutex.unlock();
}


void App::shutdown()
{
	isRunning = false;
	pWindow->close();
	this->~App();
	exit(EXIT_SUCCESS);
}

void App::getEvent(sf::Event& event)
{
	pWindow->pollEvent(event);
}

void App::wow()
{
	pTurtle->drawStar();
}

void App::getInput()
{

	static const char* usageMessage =
		"Usage:\n\
		help\n\
		forward <pixels>\n\
		right <angle>\n\
		left <angle>\n\
		info\n\
		toggle draw\n\
		toggle visible\n\
		draw start\n\
		draw square\n"; 

	while (isRunning) {
		std::string input;
		std::getline(std::cin, input);

		if (input.find("toggle draw") != std::string::npos) {
			pTurtle->toggleDraw();
		}

		else if (input.find("quit") != std::string::npos) {
			isRunning = false;
			this->shutdown();
		}

		else if (input.find("toggle visible") != std::string::npos) {
			pTurtle->toggleVisible();
		}

		else if (input.find("draw star") != std::string::npos) {
			pTurtle->drawStar();
		}

		else if (input.find("draw square") != std::string::npos) {
			pTurtle->drawSquareBg();
		}

		else if (input.find("info") != std::string::npos) {
			std::string info = pTurtle->getInfo();

			std::cout << info;
		}

		else if (input.find("help") != std::string::npos) {
			std::cout << usageMessage;
		}

		else if (input.find("reset") != std::string::npos) {

			float radius = 20.0f;

			pTurtle->setPosition(static_cast<float>(WIDTH) / 2 + radius,
				static_cast<float>(HEIGHT) / 2 + radius);
			pTurtle->getTrail()->setColor(sf::Color::White);
		}

		else if (input == "clear") {
			m_mutex.lock();
			pTurtle->clearTrail();
			m_mutex.unlock();
		}

		else {
			size_t pos = input.find(" ");
			if (pos == std::string::npos) {
				std::cout << usageMessage;
			}
			else if (input.substr(0, pos) == "forward") {
				pTurtle->move(std::atoi(input.substr(pos).c_str()));
			}
			else if (input.substr(0, pos) == "right") {
				pTurtle->rotateRight(std::atof(input.substr(pos).c_str()));
			}
			else if (input.substr(0, pos) == "left") {
				pTurtle->rotateLeft(std::atof(input.substr(pos).c_str()));
			}
		}
	}
}

bool App::isActive()
{
	return isRunning;
}
