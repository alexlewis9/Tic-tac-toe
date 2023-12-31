#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Shape.h"
#ifndef RECT_H
#define RECT_H

class Rect : public Shape {
private:
	sf::RectangleShape rect;
	float length;
	float rotation;
public:
	Rect(sf::Color color, float length, float rotation);
	void draw(sf::RenderWindow& window);
};

#endif