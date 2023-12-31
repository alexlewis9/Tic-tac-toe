#include "X.h"

X::X(int position) {
	Rect* rect1 = new Rect(color, static_cast<float>(PIECE_SIZE * sqrt(2)), 45);
	Rect* rect2 = new Rect(color, static_cast<float>(PIECE_SIZE * sqrt(2)), -45);
	shapes.push_back(rect1);
	shapes.push_back(rect2);
	setPosition(position);
	pieceType = x;
}

void X::setPosition(int position) {
	Piece::setPosition(position);
	shapes[0]->setPosition(static_cast<float>(GRID_X + (GRID_SIZE / 3 - PIECE_SIZE) / 2 + column * GRID_SIZE / 3), static_cast<float>(GRID_Y + (GRID_SIZE / 3 - PIECE_SIZE) / 2 + row * GRID_SIZE / 3));
	shapes[1]->setPosition(static_cast<float>(GRID_X + (GRID_SIZE / 3 - PIECE_SIZE) / 2 + column * GRID_SIZE / 3), static_cast<float>(GRID_Y + (GRID_SIZE / 3 - PIECE_SIZE) / 2 + row * GRID_SIZE / 3 + PIECE_SIZE));
}