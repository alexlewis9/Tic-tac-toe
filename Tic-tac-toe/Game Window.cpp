#include "Game Window.h"
#include <iostream>

GameWindow::GameWindow(pieceTypes player, sf::TcpSocket& socket) {
	this->player = player;
	this->socket = &socket;
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tic-tac-toe");

	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	topText.setFont(font);
	topText.setFillColor(sf::Color::White);
	topText.setCharacterSize(80);

	bottomText.setFont(font);
	bottomText.setFillColor(sf::Color::White);
	bottomText.setCharacterSize(80);

	if (player == x) {
		topText.setString("You are X");
		bottomText.setString("Your turn");
		turn = true;
	}
	else {
		topText.setString("You are O");
		bottomText.setString("Waiting on other player");
		turn = false;
	}

}

void GameWindow::runGame() {
	int mouseX = 0;
	int mouseY = 0;
	int row = -1;
	int column = -1;
	int position = -1;
	bool otherPlayerQuit = false;
	message m;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				// send message that other player quit
				window.close();
				m.type = 1;
				packet << m;
				socket->send(packet);
				packet.clear();
			}

			if ((turn || gameOver) && event.mouseButton.button == sf::Mouse::Left) // if player's turn or game over, process mouse click
			{
				if (!otherPlayerQuit) {
					mouseX = event.mouseButton.x;
					mouseY = event.mouseButton.y;
					// if game over and click to start new game, send message to other player to start new game and start new game
					if (gameOver && mouseY > WINDOW_HEIGHT - bottomText.getGlobalBounds().height * 2) {
						m.type = 2;
						packet << m;
						socket->send(packet);
						packet.clear();
						newGame();
					}
					// if game running and click is in grid
					if (!gameOver && turn && mouseX > GRID_X && mouseX < GRID_X + GRID_SIZE && mouseY > GRID_Y && mouseY < GRID_Y + GRID_SIZE) {
						row = static_cast<int>((mouseY - GRID_Y) / 300);
						column = static_cast<int>((mouseX - GRID_X) / 300);
						position = 3 * row + column;
						if (position != previousPosition) { // can't place piece where just removed from
							turn = game.makeMove(player, position);
							if (turn == 1) { // removed piece
								previousPosition = position; // store position to compare with where placing
								window.pollEvent(event);
							}
							else if (turn == 0) { // placed piece
								winner = game.checkForRow();
								if (winner == p) {
									bottomText.setString("Waiting on other player");
								}
								else {
									endGame();
								}
								// send move
								m.previousPosition = previousPosition;
								m.newPosition = position;
								m.type = 0;
								packet << m;
								socket->send(packet);
								packet.clear();
							}
						}
					}
				}
			}
		}

		if (!turn || gameOver) {
			// recieve from other player
			sf::Socket::Status status = socket->receive(packet);
			if (status != sf::Socket::NotReady)
			{
				packet >> m;
				if (m.type == 1) {
					topText.setString("Other player quit");
					otherPlayerQuit = true;
				}
				else if (m.type == 2) {
					newGame();
				}
				else if (m.type == 0) {
					// recieve move
					game.moveOtherPlayerPiece(player, m.previousPosition, m.newPosition);
					winner = game.checkForRow();
					if (winner == p) {
						turn = true;
						bottomText.setString("Your turn");
					}
					else {
						endGame();
					}
				}
				packet.clear();
			}
		}

		window.clear();

		game.draw(window);

		topText.setPosition(static_cast<float>((WINDOW_WIDTH - topText.getGlobalBounds().width) / 2), 0);
		window.draw(topText);

		bottomText.setPosition(static_cast<float>((WINDOW_WIDTH - bottomText.getGlobalBounds().width) / 2), WINDOW_HEIGHT - bottomText.getGlobalBounds().height * 2);
		window.draw(bottomText);

		window.display();
	}
}

void GameWindow::endGame() {
	gameOver = true;
	bottomText.setString("Click here to play again");
	if (player == winner) {
		topText.setString("Congrats! You won.");
	}
	else if (winner == x) {
		topText.setString("X wins");
	}
	else {
		topText.setString("O wins");
	}
}

void GameWindow::newGame() {
	game = Game();
	gameOver = false;
	previousPosition = -1;
	if (player == winner) {
		bottomText.setString("Your turn");
		turn = true;
	}
	else {
		bottomText.setString("Waiting on other player");
		turn = false;
	}
	if (player == x) {
		topText.setString("You are X");
	}
	else {
		topText.setString("You are O");
	}
}