#include "Circle.h"

Circle::Circle(sf::Color color, float radius):Shape(color){
	this->radius = radius;
	circle = sf::CircleShape(radius);
	circle.setFillColor(sf::Color::Black);
	circle.setOutlineColor(color);
	circle.setOutlineThickness(static_cast<float>(-1 * thickness));
}

void Circle::setPosition(float x, float y) {
	circle.setPosition(x, y);
}

void Circle::draw(sf::RenderWindow& window) {
	circle.setPosition(x, y);
	window.draw(circle);
}