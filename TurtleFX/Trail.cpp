#include "Trail.h"

Trail::Trail()
{
	m_arr.resize(100);
}

Trail::Trail(float x, float y)
{
	m_arr.append(sf::Vertex(sf::Vector2f(x, y)));
}

void Trail::addPoint(const sf::Vertex& vert)
{
	m_arr.append(vert);
}

sf::VertexArray& Trail::getData()
{
	return m_arr;
}
