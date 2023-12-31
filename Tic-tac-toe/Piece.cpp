#include "Piece.h"

Piece::Piece() {
	color = sf::Color::White;
}

int Piece::getPosition() const {
	return position;
}  

void Piece::setPosition(int position) {
	this->position = position;
	column = position % 3;
	row = position / 3;
}

void Piece::draw(sf::RenderWindow& window) {
	for (Shape* shape : shapes) {
		shape->draw(window);
	}
}