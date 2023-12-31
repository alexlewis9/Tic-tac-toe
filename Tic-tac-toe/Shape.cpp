#include "Shape.h"

Shape::Shape() {
	x = 0;
	y = 0;
	thickness = 10;
}

Shape::Shape(sf::Color color):Shape() {
	this->color = color;
}

void Shape::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
}

void Shape::draw(sf::RenderWindow& window) {}