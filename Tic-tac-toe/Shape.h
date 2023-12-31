#include <SFML/Graphics.hpp>
#include "Constants.h"
#ifndef SHAPE_H
#define SHAPE_H

class Shape {
protected:
	sf::Color color;
	float x;
	float y;
	int thickness;
public:
	Shape();
	Shape(sf::Color color);
	void setPosition(float x, float y);
	virtual void draw(sf::RenderWindow& window);
};

#endif