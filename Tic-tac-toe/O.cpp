#include "O.h"

O::O(int position) {
	Circle* circle = new Circle(color, PIECE_SIZE / 2);
	shapes.push_back(circle);
	setPosition(position);
	pieceType = o;
}

void O::setPosition(int position) {
	Piece::setPosition(position);
	shapes[0]->setPosition(static_cast<float>(GRID_X + (GRID_SIZE / 3 - PIECE_SIZE) / 2 + column * GRID_SIZE / 3), static_cast<float>(GRID_Y + (GRID_SIZE / 3 - PIECE_SIZE) / 2 + row * GRID_SIZE / 3));
}