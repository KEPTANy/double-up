#include "double_up.h"

#include <assert.h>
#include <stdlib.h>

void game_state_init(GameState *state) {
    srand(time(NULL));
    for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
        state->board[i] = 0;
}

void game_state_set(GameState *state, size_t row, size_t col, uint8_t val) {
    assert(row < BOARD_SIZE);
    assert(col < BOARD_SIZE);
    state->board[row * BOARD_SIZE + col] = val;
}

void game_state_set_random(GameState *state) {
    uint64_t empty_cnt = game_state_empty_count(state);
    if (!empty_cnt)
        return;
    uint64_t pos = rand() % empty_cnt;
    for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        if (!state->board[i])
            pos--;
        if (!pos)
            state->board[i] = (rand() & 1) ? 1 : 2;
    }
}

uint64_t game_state_empty_count(GameState *state) {
    uint64_t cnt;
    for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
        if (!state->board[i])
            cnt++;
    return cnt;
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
