#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Shape.h"
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape {
private:
	sf::CircleShape circle;
	float radius;
public:
	Circle(sf::Color color, float radius);
	void setPosition(float x, float y);
	void draw(sf::RenderWindow& window);
};

#endif