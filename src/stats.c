#include "include/mainlib.h"
#include <stdio.h>

void gen_stats(Game* game) {
    game->stats = (Stats) {
        0, 
        0,
        0,
        0,
        0,
        1,
        CELLSIZE,
        0,
        CPS
    };
}

void update_stats(Game* game) {
    if (IsKeyPressed(KEY_I)) game->stats.debug = !game->stats.debug;
    
    if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) {
        if (IsKeyPressed(KEY_EQUAL)) game->stats.cps = game->stats.cps < FPS ? game->stats.cps + 1 : FPS;
        if (IsKeyPressed(KEY_MINUS)) game->stats.cps = game->stats.cps > 1 ? game->stats.cps - 1 : 1;
    } else {
        if (IsKeyDown(KEY_EQUAL)) game->stats.cellsize *= 1.05;
        if (IsKeyDown(KEY_MINUS)) game->stats.cellsize *= .95;
    }
    

    game->stats.cellsize = game->stats.cellsize >= CELLSIZE_MIN ? game->stats.cellsize : CELLSIZE_MIN;
    game->stats.cellsize = game->stats.cellsize <= CELLSIZE_MAX ? game->stats.cellsize : CELLSIZE_MAX;

    game->stats.fps = GetFPS();
    game->stats.living_cells = 0;

    for (unsigned int i = 0; i < GRIDWIDTH; i++) {
        for (unsigned int j = 0; j < GRIDLENGTH; j++) {
            game->stats.living_cells += game->grid[i][j].alive;
        }
    }

    game->stats.frame += game->stats.frame < (FPS-1) ? 1 : -(FPS-1);
    if (IsKeyPressed(KEY_P)) game->stats.paused = !game->stats.paused;
    if (IsKeyPressed(KEY_G)) game->stats.grid = !game->stats.grid;
    if (!(game->stats.frame % (FPS / game->stats.cps != 0 ? FPS / game->stats.cps : 1)) && !game->stats.paused) ++game->stats.cycle;
}
