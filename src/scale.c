#include "include/mainlib.h"

void gen_scale(Game* game) {
    game->scale = MIN((float)GetScreenWidth()/SCREENWIDTH, (float)GetScreenHeight()/SCREENLENGTH);
}

void update_scale(Game* game) {
    gen_scale(game);
}
