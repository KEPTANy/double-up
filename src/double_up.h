#ifndef DOUBLE_UP_H
#define DOUBLE_UP_H

#include <inttypes.h>

#ifndef BOARD_SIZE
#define BOARD_SIZE 4
#endif

typedef struct GameState {
    int8_t board[BOARD_SIZE * BOARD_SIZE];
};

#endif
