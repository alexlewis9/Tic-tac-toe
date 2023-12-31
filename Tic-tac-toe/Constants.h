#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <algorithm>

const int WINDOW_SIZE = 1200;
const int WINDOW_WIDTH = WINDOW_SIZE;
const int WINDOW_HEIGHT = WINDOW_SIZE;
const float GRID_X = WINDOW_WIDTH / 8;
const float GRID_Y = WINDOW_HEIGHT / 8;
const float GRID_SIZE = static_cast<float>(std::min(WINDOW_WIDTH, WINDOW_HEIGHT) * 3 / 4);
const float PIECE_SIZE = GRID_SIZE * 3 / 10;
const float LINE_WIDTH = 5;
const enum pieceTypes {x, o, p};

#endif