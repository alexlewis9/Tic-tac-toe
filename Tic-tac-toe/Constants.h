#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <algorithm>

const float WINDOW_SIZE = 1200;
const float WINDOW_WIDTH = WINDOW_SIZE;
const float WINDOW_HEIGHT = WINDOW_SIZE;
const float GRID_X = WINDOW_WIDTH / 8;
const float GRID_Y = WINDOW_HEIGHT / 8;
const float GRID_SIZE = std::min(WINDOW_WIDTH, WINDOW_HEIGHT) * 3 / 4;
const float PIECE_SIZE = GRID_SIZE * 3 / 10;
const float LINE_WIDTH = 5;
const enum pieceTypes {x, o, p};

#endif