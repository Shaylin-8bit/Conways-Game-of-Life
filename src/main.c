#include "include/mainlib.h"

void init_raylib(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(SCREENWIDTH, SCREENLENGTH, "Life");
    SetWindowMinSize(320, 240);
    SetTargetFPS(FPS);
}

int main(void) {
    init_raylib();
    Game game = init_game();

    while (!WindowShouldClose()) {
        update_game(&game);
        draw_screen(&game);
    }

    CloseWindow();

    return 0;
}