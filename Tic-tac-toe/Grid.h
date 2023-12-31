#ifndef GRID_H
#define GRID_H
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Piece.h"
#include "O.h"
#include "X.h"

class Grid {
private:
	Piece* pieces[9];
	std::vector<sf::RectangleShape> lines;
	int numX = 0;
	int numO = 0;
	void setPiece(pieceTypes piece, int position);
	void drawGrid(sf::RenderWindow& window);
public:
	Grid();
	int getNumX() const { return numX; }
	int getNumO() const { return numO; }
	pieceTypes getPieceType(int position) const;
	void addLine(sf::RectangleShape line);
	void placeX(int position);
	void placeO(int position);
	void removePiece(int position);
	void moveOtherPlayerPiece(pieceTypes player, int previousPosition, int newPosition);
	void draw(sf::RenderWindow& window);
};

#endif