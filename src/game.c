#include "include/mainlib.h"
#include <stdio.h>

Game init_game(void) {
    Game game = (Game){};

    gen_grid(&game);
    gen_player(&game);
    gen_camera(&game);
    gen_mouse(&game);
    gen_texture(&game);
    gen_scale(&game);
    gen_stats(&game);

    return game;
}

void update_game(Game* game) {
    update_camera(game);
    update_player(game);
    update_mouse(game);
    update_grid(game);
    update_scale(game);
    update_texture(game);
    update_stats(game);
}
