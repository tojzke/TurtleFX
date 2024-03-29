#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "turtle.h"

class App
{
public:
	
	App();
	~App();

	void getEvent(sf::Event& event);
	void getInput();

	bool isActive();
	void updateWindow();
	void wow();

	void shutdown();

private:
	sf::RenderWindow*		pWindow;
	
	bool					isRunning;

	static const uint32_t	WIDTH;
	static const uint32_t	HEIGHT;
	static const std::string TITLE;

	Turtle*					pTurtle;
	
	sf::Mutex				m_mutex;
};