#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Piece.h"
#include "Rect.h"
#ifndef X_H
#define X_H

class X : public Piece {
public:
	X(int position);
	void setPosition(int position);
};

#endif