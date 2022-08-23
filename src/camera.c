#include "include/mainlib.h"

void gen_camera(Game* game) {
    game->camera.target = (Vector2){game->player.x, game->player.y};
    game->camera.rotation = 0.0f;
    game->camera.zoom = 1.0f;
}

void update_camera(Game* game) {
    game->camera.target = (Vector2){game->player.x, game->player.y};
}
