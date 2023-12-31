#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Grid.h"


class Game {
private:
	Grid grid;
public:
	Game();
	void draw(sf::RenderWindow& window);
	int makeMove(pieceTypes player, int position); // 0 = place piece = turn over, 1 = remove piece, 2 = invalid
	pieceTypes checkForRow();
	pieceTypes getPieceType(int position) const;
	void moveOtherPlayerPiece(pieceTypes player, int previousPosition, int newPosition);
};

#endif