#include "include/mainlib.h"

void gen_mouse(Game* game) {
    game->mouse = (Vector2){0, 0};
}

void update_mouse(Game* game) {
    Vector2 mouse = GetMousePosition();
    game->mouse.x = (mouse.x - (GetScreenWidth() - (SCREENWIDTH*game->scale))*0.5f)/game->scale;
    game->mouse.y = (mouse.y - (GetScreenHeight() - (SCREENLENGTH*game->scale))*0.5f)/game->scale;
    game->mouse = Vector2Clamp(game->mouse, (Vector2){ 0, 0 }, (Vector2){ (float)SCREENWIDTH, (float)SCREENLENGTH });
}
