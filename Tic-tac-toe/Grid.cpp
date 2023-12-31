#include "Grid.h"

Grid::Grid() {
	for (int i = 0; i < 4; i++) {
		sf::RectangleShape line(sf::Vector2f(GRID_SIZE, LINE_WIDTH));
		line.setPosition(static_cast<float>(GRID_X), static_cast<float>(WINDOW_HEIGHT * (1 + 2 * i) / 8 - LINE_WIDTH / 2));
		lines.push_back(line);
	}
	for (int i = 0; i < 4; i++) {
		sf::RectangleShape line(sf::Vector2f(GRID_SIZE + LINE_WIDTH, LINE_WIDTH));
		line.setPosition(static_cast<float>(WINDOW_WIDTH * (1 + 2 * i) / 8), static_cast<float>(GRID_Y - LINE_WIDTH / 2));
		line.rotate(90);
		lines.push_back(line);
	}
	for (int i = 0; i < 9; i++) {
		pieces[i] = new Piece();
	}
}

void Grid::drawGrid(sf::RenderWindow& window) {
	for (sf::RectangleShape line : lines) {
		window.draw(line);
	}
}

void Grid::draw(sf::RenderWindow& window) {
	drawGrid(window);
	for (Piece* piece : pieces) {
		piece->draw(window);
	}
}

pieceTypes Grid::getPieceType(int position) const {
	return pieces[position]->getType();
}

void Grid::addLine(sf::RectangleShape line) {
	lines.push_back(line);
}

void Grid::placeX(int position) {
	X* x = new X(position);
	pieces[position] = x;
	numX++;
}

void Grid::placeO(int position) {
	O* o = new O(position);
	pieces[position] = o;
	numO++;
}

void Grid::removePiece(int position) {
	pieceTypes pieceType = getPieceType(position);
	if (pieceType == x) {
		numX--;
	}
	else if (pieceType == o) {
		numO--;
	}
	pieces[position] = new Piece();
}

void Grid::setPiece(pieceTypes piece, int position) {
	if (piece == x) {
		placeX(position);
	}
	else if (piece == o) {
		placeO(position);
	}
}

// update grid with other player's move
void Grid::moveOtherPlayerPiece(pieceTypes player, int previousPosition, int newPosition) {
	if (player == o) {
		if (numX == 3)
			removePiece(previousPosition);
		setPiece(x, newPosition);
	}
	else if (player == x) {
		if (numO == 3)
			removePiece(previousPosition);
		setPiece(o, newPosition);
	}
}