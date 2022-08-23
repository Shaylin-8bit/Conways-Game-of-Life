#include "include/mainlib.h"
#include <stdio.h>

void gen_texture(Game* game) {
    game->texture = LoadRenderTexture(SCREENWIDTH, SCREENLENGTH);
}

void update_texture(Game* game) {
    BeginTextureMode(game->texture);
        BeginMode2D(game->camera);

            ClearBackground(BLACK);
            const unsigned char cellsize = game->stats.cellsize;

            int x = (int)game->player.x / cellsize;
            int y = (int)game->player.y / cellsize;
            x = x >= 0 ? x : 0;
            y = y >= 0 ? y : 0;

            int lx = x + SCREENWIDTH / cellsize + 1;
            int ly = y + SCREENLENGTH / cellsize + 1;
            lx = lx < GRIDWIDTH ? lx : GRIDWIDTH;
            ly = ly < GRIDLENGTH ? ly : GRIDLENGTH;

            for (int i = x; i < lx; i++) {
                for (int j = y; j < ly; j++) {
                    if (game->grid[i][j].alive) {
                        DrawRectangle(i*cellsize, j*cellsize, cellsize, cellsize, WHITE);
                        DrawRectangleLines(i*cellsize, j*cellsize, cellsize, cellsize, BLACK);
                    } else {
                        if (game->stats.grid) DrawRectangleLines(i*cellsize, j*cellsize, cellsize, cellsize, WHITE);
                    } 
                }
            }
        
        EndMode2D();

        if (game->stats.debug) {
            DrawText(TextFormat("FPS: %i  Cycle: %i  Frame: %i", game->stats.fps, game->stats.cycle, game->stats.frame), 5, 5, 18, DARKGREEN);
            DrawText(TextFormat("Living Cells: %i  X: %i  Y: %i", game->stats.living_cells, (int)game->player.x / cellsize, (int)game->player.y / cellsize), 5, 23, 18, DARKGREEN);
            DrawText(TextFormat("Game %s  CPS: %i", game->stats.paused ? "paused" : "running", game->stats.cps), 5, 41, 18, DARKGREEN);
        }
        
    EndTextureMode();
}
