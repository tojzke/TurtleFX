#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Trail
{
public:
	Trail();
	Trail(float x, float y);

	void addPoint(const sf::Vertex& vert);
	sf::VertexArray& getData();


private:
	sf::VertexArray m_arr;
};