#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Constants.h"
#include "Game.h"
#include "Message.h"

class GameWindow {
private:
	sf::RenderWindow window;
	Game game;
	pieceTypes player;
	int turn;
	bool gameOver = false;
	pieceTypes winner = p;
	int previousPosition = -1;
	sf::Font font;
	sf::Text topText;
	sf::Text bottomText;
	sf::TcpSocket* socket;
	sf::Packet packet;
public:
	GameWindow(pieceTypes player, sf::TcpSocket& socket);
	void runGame();
	void newGame();
};

#endif