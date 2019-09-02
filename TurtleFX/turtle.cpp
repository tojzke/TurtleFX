#define _USE_MATH_DEFINES
#include "turtle.h"
#include <cmath>
#include <vector>
#include <iostream>

Turtle::Turtle(float x = 0.0f, float y = 0.0f, float radius = 0.0f) :
	m_x(x), m_y(y), 
	m_radius(radius),
	m_isDrawing(true)
{
	m_pShape = new sf::CircleShape(m_radius);
	m_pShape->setPosition(m_x, m_y);
}

Turtle::~Turtle()
{
	delete m_pShape;
}

void Turtle::setPosition(float x, float y)
{
	m_x = x;
	m_y = y;
}

std::vector<sf::Vertex> Turtle::move(float movement)
{

	float nx = m_x + movement * cos(m_angle / 360.0f * 2.0f * M_PI);
	float ny = m_y + movement * sin(m_angle / 360.0f * 2.0f * M_PI);

	if (m_isDrawing) {
		std::vector<sf::Vertex> line
		{
			sf::Vector2f(m_x, m_y),
			sf::Vector2f(nx, nx)
		};

		m_x = nx;
		m_y = ny;
		m_pShape->setPosition(m_x, m_y);

		return line;
	}
	else
		return std::vector<sf::Vertex>(0);

}

void Turtle::rotateLeft(float angle)
{
	m_angle -= angle;
}

sf::CircleShape * Turtle::getShape()
{
	return m_pShape;
}

void Turtle::rotateRight(float angle)
{
	m_angle += angle;
}
