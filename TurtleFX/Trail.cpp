#include "Trail.h"

Trail::Trail():
	m_color(sf::Color::White)
{
	m_arr.resize(100);
}

Trail::Trail(float x, float y)
{
	m_arr.append(sf::Vertex(sf::Vector2f(x, y), m_color));
}

void Trail::addPoint(sf::Vertex vert)
{
	vert.color = m_color;
	m_arr.append(vert);
}

sf::VertexArray& Trail::getData()
{
	return m_arr;
}

void Trail::setColor(sf::Color color)
{
	m_color = color;
}
