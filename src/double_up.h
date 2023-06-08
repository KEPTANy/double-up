#ifndef DOUBLE_UP_H
#define DOUBLE_UP_H

#include <inttypes.h>

#ifndef BOARD_SIZE
#define BOARD_SIZE 4
#endif

typedef struct GameState {
    uint8_t board[BOARD_SIZE * BOARD_SIZE];
} GameState;

typedef enum Direction {
    DIR_UP,
    DIR_RIGHT,
    DIR_DOWN,
    DIR_LEFT
} Direction;

#endif
