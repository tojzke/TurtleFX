#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class Turtle 
{
public:

	Turtle(float x, float y, float radius);

	~Turtle();

	void setPosition(float x, float y);
	std::vector<sf::Vertex> move(float dist);
	void rotateRight(float angle);
	void rotateLeft(float angle);

	sf::CircleShape* getShape();


private:
	
	sf::CircleShape* m_pShape;

	float m_x;
	float m_y;
	float m_angle;

	float m_radius;

	bool m_isDrawing;
};