#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Shape.h"
#ifndef PIECE_H
#define PIECE_H

class Piece {
	protected:
		sf::Color color;
		std::vector<Shape*> shapes;
		int position; // -1 = not played yet, grid:
		// 0 1 2
		// 3 4 5
		// 6 7 8
		int row;
		int column;
		pieceTypes pieceType = p;
	public:
		Piece();
		int getPosition() const;
		virtual void setPosition(int position);
		void draw(sf::RenderWindow& window);
		pieceTypes getType() { return pieceType; }
};

#endif