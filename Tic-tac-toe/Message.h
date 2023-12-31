#ifndef MESSAGE_H
#define MESSAGE_H
#include "Constants.h"
#include <SFML/Network.hpp>

struct message {
    int type; // 0 for sending a move, 1 if window closed, 2 if new Game
    int previousPosition;
    int newPosition;
};

sf::Packet& operator <<(sf::Packet& packet, const message& m);
sf::Packet& operator >>(sf::Packet& packet, message& m);

#endif