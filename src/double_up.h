#ifndef DOUBLE_UP_H
#define DOUBLE_UP_H

#include <inttypes.h>
#include <stddef.h>

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

void game_state_init(GameState *state);
void game_state_set(GameState *state, size_t row, size_t col, uint8_t val);
uint64_t game_state_empty_count(GameState *state);

void shift(GameState *state, Direction direction);
void shift_up(GameState *state);
void shift_right(GameState *state);
void shift_down(GameState *state);
void shift_left(GameState *state);

#endif
