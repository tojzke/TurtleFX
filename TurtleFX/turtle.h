#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "Trail.h"

class Turtle 
{
public:

	Turtle(float x, float y, float radius);

	~Turtle();

	void setPosition(float x, float y);
	void move(int movement);
	void rotateRight(float angle);
	void rotateLeft(float angle);
	void toggleDraw();

	void drawStar();

	bool isVisible();
	void toggleVisible();


	sf::CircleShape* getShape();
	Trail*			 getTrail();
	sf::Sprite&		 getSprite();


private:
	
	sf::CircleShape* m_pShape;
	Trail*			 m_pTrail;
	sf::Texture		 m_texture;
	sf::Sprite       m_sprite;


	float m_x;
	float m_y;
	float m_angle;

	float m_radius;

	bool m_isDrawing;
	bool m_isVisible;
};