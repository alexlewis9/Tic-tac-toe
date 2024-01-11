#include <SFML/Network.hpp>
#include <iostream>
#include "Game Window.h"
using namespace std;

int main(int argc, char** argv)
{
    pieceTypes player;
    sf::TcpSocket socket;
    unsigned short port = 53000;

    if (argc == 1) {
        // server
        sf::TcpListener listener;

        if (listener.listen(port) != sf::Socket::Done)
        {
            cout << "Error binding the listener to port";
            return 0;
        }

        if (listener.accept(socket) != sf::Socket::Done)
        {
            cout << "Error accepting connection with client";
            return 0;
        }
        player = o;
    }
    else {
        // client
        string ipAddress = argv[1];

        sf::Socket::Status status = socket.connect(ipAddress, port);
        if (status != sf::Socket::Done)
        {
            cout << "Error connecting to server";
            return 0;
        }
        player = x;
    }

    socket.setBlocking(false);

    GameWindow gameWindow(player, socket);
    gameWindow.runGame();

    return 0;
}