#include "include/mainlib.h"

void draw_screen(Game* game) {
    BeginDrawing();
        ClearBackground((Color){30, 30, 30, 255});
        DrawTexturePro(
            game->texture.texture, 
            (Rectangle) { 
                0.0f,
                0.0f, 
                (float) {game->texture.texture.width}, 
                (float) {-game->texture.texture.height}
            },
            (Rectangle) { 
                (GetScreenWidth() - ((float)SCREENWIDTH*game->scale))*0.5f, 
                (GetScreenHeight() - ((float)SCREENLENGTH*game->scale))*0.5f,
                (float)SCREENWIDTH*game->scale, 
                (float)SCREENLENGTH*game->scale 
            }, 
            (Vector2){ 0, 0 },
            0.0f, 
            WHITE
        );
    EndDrawing();
}
