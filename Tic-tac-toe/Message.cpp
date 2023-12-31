#include "Message.h"

sf::Packet& operator <<(sf::Packet& packet, const message& m)
{
    return packet << m.type << m.previousPosition << m.newPosition;
}

sf::Packet& operator >>(sf::Packet& packet, message& m)
{
    return packet >> m.type >> m.previousPosition >> m.newPosition;
}