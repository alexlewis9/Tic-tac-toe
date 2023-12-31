#include "Game.h"

Game::Game() {}

void Game::draw(sf::RenderWindow& window) {
	grid.draw(window);
}

pieceTypes Game::getPieceType(int position) const {
	return grid.getPieceType(position);
}

void Game::moveOtherPlayerPiece(pieceTypes player, int previousPosition, int newPosition) {
	grid.moveOtherPlayerPiece(player, previousPosition, newPosition);
}

int Game::makeMove(pieceTypes player, int position) {
	if (player == x) {
		if (grid.getNumX() < 3 && grid.getPieceType(position) == p) {
			grid.placeX(position);
			return 0;
		}
		else if (grid.getNumX() == 3 && grid.getPieceType(position) == x) {
			grid.removePiece(position);
			return 1;
		}
		
	}
	else if (player == o) {
		if (grid.getNumO() < 3 && grid.getPieceType(position) == p) {
			grid.placeO(position);
			return 0;
		}
		else if (grid.getNumO() == 3 && grid.getPieceType(position) == o) {
			grid.removePiece(position);
			return 1;
		}
	}
	return 2;
}

pieceTypes Game::checkForRow() {
	sf::RectangleShape line(sf::Vector2f(GRID_SIZE, 2 * LINE_WIDTH));
	if (grid.getPieceType(0) != p && grid.getPieceType(0) == grid.getPieceType(1) && grid.getPieceType(1) == grid.getPieceType(2)) {
		sf::RectangleShape line(sf::Vector2f(GRID_SIZE, 2 * LINE_WIDTH));
		line.setPosition(static_cast<float>(GRID_X + (GRID_SIZE / 3 - PIECE_SIZE) / 2), static_cast<float>(GRID_Y + GRID_SIZE / 6) - LINE_WIDTH);
		grid.addLine(line);
		return grid.getPieceType(0);
	} else if (grid.getPieceType(3) != p && grid.getPieceType(3) == grid.getPieceType(4) && grid.getPieceType(4) == grid.getPieceType(5)) {
		sf::RectangleShape line(sf::Vector2f(GRID_SIZE, 2 * LINE_WIDTH));
		line.setPosition(static_cast<float>(GRID_X + (GRID_SIZE / 3 - PIECE_SIZE) / 2), static_cast<float>(GRID_Y + GRID_SIZE * 3 / 6) - LINE_WIDTH);
		grid.addLine(line);
		return grid.getPieceType(3);
	} else if (grid.getPieceType(6) != p && grid.getPieceType(6) == grid.getPieceType(7) && grid.getPieceType(7) == grid.getPieceType(8)) {
		sf::RectangleShape line(sf::Vector2f(GRID_SIZE, 2 * LINE_WIDTH));
		line.setPosition(static_cast<float>(GRID_X + (GRID_SIZE / 3 - PIECE_SIZE) / 2), static_cast<float>(GRID_Y + GRID_SIZE * 5 / 6) - LINE_WIDTH);
		grid.addLine(line);
		return grid.getPieceType(6);
	} else if (grid.getPieceType(0) != p && grid.getPieceType(0) == grid.getPieceType(3) && grid.getPieceType(3) == grid.getPieceType(6)) {
		sf::RectangleShape line(sf::Vector2f(2 * LINE_WIDTH, GRID_SIZE));
		line.setPosition(static_cast<float>(GRID_X + GRID_SIZE / 6) - LINE_WIDTH, static_cast<float>(GRID_Y + (GRID_SIZE / 3 - PIECE_SIZE) / 2));
		grid.addLine(line);
		return grid.getPieceType(0);
	} else if (grid.getPieceType(1) != p && grid.getPieceType(1) == grid.getPieceType(4) && grid.getPieceType(4) == grid.getPieceType(7)) {
		sf::RectangleShape line(sf::Vector2f(2 * LINE_WIDTH, GRID_SIZE));
		line.setPosition(static_cast<float>(GRID_X + GRID_SIZE * 3 / 6) - LINE_WIDTH, static_cast<float>(GRID_Y + (GRID_SIZE / 3 - PIECE_SIZE) / 2));
		grid.addLine(line);
		return grid.getPieceType(1);
	} else if (grid.getPieceType(2) != p && grid.getPieceType(2) == grid.getPieceType(5) && grid.getPieceType(5) == grid.getPieceType(8)) {
		sf::RectangleShape line(sf::Vector2f(2 * LINE_WIDTH, GRID_SIZE));
		line.setPosition(static_cast<float>(GRID_X + GRID_SIZE * 5 / 6) - LINE_WIDTH, static_cast<float>(GRID_Y + (GRID_SIZE / 3 - PIECE_SIZE) / 2));
		grid.addLine(line);
		return grid.getPieceType(2);
	} else if (grid.getPieceType(0) != p && grid.getPieceType(0) == grid.getPieceType(4) && grid.getPieceType(4) == grid.getPieceType(8)) {
		sf::RectangleShape line(sf::Vector2f((GRID_SIZE - (GRID_SIZE / 3 - PIECE_SIZE) / 2) * sqrt(2), 2 * LINE_WIDTH));
		line.rotate(45);
		line.setPosition(static_cast<float>(GRID_X + (GRID_SIZE / 3 - PIECE_SIZE) / 2), static_cast<float>(GRID_Y + (GRID_SIZE / 3 - PIECE_SIZE) / 2));
		grid.addLine(line);
		return grid.getPieceType(0);
	} else if (grid.getPieceType(2) != p && grid.getPieceType(2) == grid.getPieceType(4) && grid.getPieceType(4) == grid.getPieceType(6)) {
		sf::RectangleShape line(sf::Vector2f((GRID_SIZE - (GRID_SIZE / 3 - PIECE_SIZE) / 2) * sqrt(2), 2 * LINE_WIDTH));
		line.rotate(-45);
		line.setPosition(static_cast<float>(GRID_X + (GRID_SIZE / 3 - PIECE_SIZE) / 2), static_cast<float>(GRID_Y + (GRID_SIZE / 3 - PIECE_SIZE) / 2) + (GRID_SIZE - (GRID_SIZE / 3 - PIECE_SIZE) / 2));
		grid.addLine(line);
		return grid.getPieceType(2);
	}
	return p;
}