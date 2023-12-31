#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Piece.h"
#include "Circle.h"
#ifndef O_H
#define O_H

class O : public Piece {
public:
	O(int position);
	void setPosition(int position);
};

#endif