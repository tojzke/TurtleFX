#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Trail
{
public:
	Trail();
	Trail(float x, float y);

	void addPoint(sf::Vertex vert);
	sf::VertexArray& getData();

	void			setColor(sf::Color color);

private:
	sf::VertexArray m_arr;
	sf::Color		m_color;
};