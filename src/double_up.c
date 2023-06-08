#include "double_up.h"

#include <stddef.h>

void game_state_init(GameState *state) {
    for (size_t i = 0; i < BOARD_SIZE; i++)
        for (size_t j = 0; j < BOARD_SIZE; j++)
            state->board[i * BOARD_SIZE + j] = 0;
}

void shift(GameState *state, Direction direction) {
    switch (direction) {
        case DIR_UP:    shift_up(state);    break;
        case DIR_RIGHT: shift_right(state); break;
        case DIR_DOWN:  shift_down(state);  break;
        case DIR_LEFT:  shift_left(state);  break;
    }
}

void shift_up(GameState *state) {
    for (size_t col = 0; col < BOARD_SIZE; col++) {
        size_t curr = col;
        for (size_t row = 0; row < BOARD_SIZE; row++) {
            if (!state->board[row * BOARD_SIZE + col])
                continue;

            uint8_t val = state->board[row * BOARD_SIZE + col];
            state->board[row * BOARD_SIZE + col] = 0;

            if (state->board[curr] == val) {
                state->board[curr]++;
                curr += BOARD_SIZE;
            } else if (state->board[curr]) {
                curr += BOARD_SIZE;
                state->board[curr] = val;
            } else {
                state->board[curr] = val;
            }
        }
    }
}

void shift_right(GameState *state) {
    for (size_t row = 0; row < BOARD_SIZE; row++) {
        size_t curr = row * (BOARD_SIZE + 1) - 1;
        for (size_t col = 0; col < BOARD_SIZE; col++) {
            if (!state->board[row * BOARD_SIZE + col])
                continue;

            uint8_t val = state->board[row * BOARD_SIZE + col];
            state->board[row * BOARD_SIZE + col] = 0;

            if (state->board[curr] == val) {
                state->board[curr]++;
                curr--;
            } else if (state->board[curr]) {
                curr--;
                state->board[curr] = val;
            } else {
                state->board[curr] = val;
            }
        }
    }
}

void shift_down(GameState *state) {
    for (size_t col = 0; col < BOARD_SIZE; col++) {
        size_t curr = col + BOARD_SIZE * (BOARD_SIZE - 1);
        for (size_t row = BOARD_SIZE - 1; row < BOARD_SIZE; row--) {
            if (!state->board[row * BOARD_SIZE + col])
                continue;

            uint8_t val = state->board[row * BOARD_SIZE + col];
            state->board[row * BOARD_SIZE + col] = 0;

            if (state->board[curr] == val) {
                state->board[curr]++;
                curr -= BOARD_SIZE;
            } else if (state->board[curr]) {
                curr -= BOARD_SIZE;
                state->board[curr] = val;
            } else {
                state->board[curr] = val;
            }
        }
    }
}

void shift_left(GameState *state) {
    for (size_t row = 0; row < BOARD_SIZE; row++) {
        size_t curr = row * BOARD_SIZE;
        for (size_t col = 0; col < BOARD_SIZE; col++) {
            if (!state->board[row * BOARD_SIZE + col])
                continue;

            uint8_t val = state->board[row * BOARD_SIZE + col];
            state->board[row * BOARD_SIZE + col] = 0;

            if (state->board[curr] == val) {
                state->board[curr]++;
                curr++;
            } else if (state->board[curr]) {
                curr++;
                state->board[curr] = val;
            } else {
                state->board[curr] = val;
            }
        }
    }
}
