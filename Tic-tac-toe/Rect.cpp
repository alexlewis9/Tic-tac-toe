#include "Rect.h"

Rect::Rect(sf::Color color, float length, float rotation):Shape(color){
	this->length = length;
	this->rotation = rotation;
	rect = sf::RectangleShape(sf::Vector2f(length, thickness));
	rect.setFillColor(color);
	rect.rotate(rotation);
}

void Rect::draw(sf::RenderWindow& window) {
	rect.setPosition(x, y);
	window.draw(rect);
}