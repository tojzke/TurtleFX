#define _USE_MATH_DEFINES
#include "turtle.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>

Turtle::Turtle(float x = 0.0f, float y = 0.0f, float radius = 0.0f) :
	m_x(x), m_y(y),
	m_radius(radius),
	m_isDrawing(true),
	m_angle(270.0f),
	m_isVisible(true)
{
	
	m_pShape = new sf::CircleShape(m_radius, 1);
	m_pShape->setPosition(m_x, m_y);
	m_pShape->setOrigin(m_radius, m_radius);
	m_pShape->setRotation(m_angle);

	sf::Image image;
	image.loadFromFile("lil_turtl.png");
	image.createMaskFromColor(sf::Color(255, 255, 255, 255), 0);

	if (!m_texture.loadFromImage(image)) {
		std::cout << "Can't load texture!\n";
		exit(EXIT_FAILURE);
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
	m_sprite.setPosition(m_x , 
						 m_y );

	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2,
					 m_sprite.getLocalBounds().width / 2);

	m_pTrail = new Trail();
}

Turtle::~Turtle()
{
	delete m_pShape;
	delete m_pTrail;
}


void Turtle::setPosition(float x, float y)
{
	m_x = x;
	m_y = y;

	m_pShape->setPosition(m_x, m_y);
	m_sprite.setPosition(m_x, m_y);
	
	m_angle = 270.0f;
	m_pShape->setRotation(m_angle);
	m_sprite.setRotation(0);

}

void Turtle::move(int movement)
{

	float nx = m_x + movement * cos(m_angle / 360.0f * 2.0f * M_PI);
	float ny = m_y + movement * sin(m_angle / 360.0f * 2.0f * M_PI);

	if (m_isDrawing) {
		m_pTrail->addPoint(sf::Vertex(sf::Vector2f(m_x, m_y)));
		m_pTrail->addPoint(sf::Vertex(sf::Vector2f(nx, ny)));

	}
	m_sprite.move(nx - m_x, ny - m_y);
	
	m_x = nx;
	m_y = ny;

	m_pShape->setPosition(m_x, m_y);
	
}

void Turtle::rotateLeft(float angle)
{
	m_angle -= angle;
	m_pShape->rotate(-angle);
	m_sprite.rotate(-angle);
}

bool Turtle::isDrawable()
{
	return m_isDrawing;
}

void Turtle::toggleDraw()
{
	m_isDrawing = !m_isDrawing;
}

void Turtle::drawStar()
{
	sf::Vector2f origin = { 800 / 2, 800 / 2 };
	
	for (int i = 0; i < 200; ++i) {
		this->move(200);
		this->rotateLeft(170);
	}

}

void Turtle::drawSquareBg()
{
	int size = 0;

	for (int i = 0; i < 350; ++i)
	{
		if (i % 2 == 0)
			this->getTrail()->setColor(sf::Color::Blue);
		else
			this->getTrail()->setColor(sf::Color::Red);

		this->move(size);
		this->rotateRight(91);
		size += 4;

	}
}

bool Turtle::isVisible()
{
	return m_isVisible;
}

void Turtle::toggleVisible()
{
	m_isVisible = !m_isVisible;
}

void Turtle::rotateRight(float angle)
{
	m_angle += angle;
	m_pShape->rotate(angle);
	m_sprite.rotate(angle);

}


sf::CircleShape * Turtle::getShape()
{
	return m_pShape;
}

sf::Sprite& Turtle::getSprite()
{
	return m_sprite;
}

std::string Turtle::getInfo()
{
	std::string info;

	auto pos = getSprite().getPosition();

	info += "Position: x=" + std::to_string(static_cast<int>(pos.x)) + " y=" + std::to_string(static_cast<int>(pos.y)) + '\n';

	info += "Drawing:";
	if (isDrawable())
		info += "yes\n";
	else
		info += "no\n";

	return info;
}

void Turtle::clearTrail()
{
	getTrail()->getData().clear();
}

Trail * Turtle::getTrail()
{
	return m_pTrail;
}

