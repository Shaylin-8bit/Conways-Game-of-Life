#include "include/mainlib.h"

void gen_player(Game* game) {
    game->player = (Vector2){0, 0};
}

void update_player(Game* game) {
    if (IsKeyDown(KEY_W)) game->player.y = MAX(game->player.y - PPS, 0); 
    if (IsKeyDown(KEY_A)) game->player.x = MAX(game->player.x - PPS, 0);
    if (IsKeyDown(KEY_S)) game->player.y = MIN(game->player.y + PPS, game->stats.cellsize * GRIDLENGTH - SCREENLENGTH);
    if (IsKeyDown(KEY_D)) game->player.x = MIN(game->player.x + PPS, game->stats.cellsize * GRIDWIDTH - SCREENWIDTH - game->stats.cellsize);
}
