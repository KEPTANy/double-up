#include <stdio.h>

#include "double_up.h"

int main() {
    GameState state;
    game_state_init(&state);

    game_state_set_random(&state);
    game_state_set_random(&state);

    game_state_print(&state);

    while (game_state_empty_count(&state)) {
        char c;
        puts("Input one of the following symbols: 'u', 'l', 'd', 'r'");
        scanf(" %c", &c);
        switch (c) {
            case 'u': shift(&state, DIR_UP);    break;
            case 'r': shift(&state, DIR_RIGHT); break;
            case 'd': shift(&state, DIR_DOWN);  break;
            case 'l': shift(&state, DIR_LEFT);  break;
            default: puts("Unable to process the symbol"); continue; break;
        }
        game_state_set_random(&state);

        game_state_print(&state);
    }

    return 0;
}
