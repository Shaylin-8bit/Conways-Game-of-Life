#include "include/mainlib.h"
#include <stdio.h>
#include <stdlib.h>

void gen_grid(Game* game) {
    if ((game->grid = malloc(sizeof(Cell*) * GRIDWIDTH)) == NULL) {
        fprintf(stderr, "Failed to allocate %llu bytes for grid at %p!", sizeof(Cell*) * GRIDWIDTH, game->grid);
    }
    for (int i = 0; i < GRIDWIDTH; i++) {
        if ((game->grid[i] = malloc(sizeof(Cell*) * GRIDLENGTH)) == NULL) {
            fprintf(stderr, "Failed to allocate %llu bytes for grid row at %p!", sizeof(Cell*) * GRIDLENGTH, game->grid[i]);
        }
        for (int j = 0; j < GRIDLENGTH; j++) {
            game->grid[i][j] = (Cell){0, 0};
        }
    }
}

void update_grid(Game* game) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        int x = (int)(game->mouse.x + game->player.x) / (game->stats.cellsize);
        int y = (int)(game->mouse.y + game->player.y) / (game->stats.cellsize);
        
        if (x >= 0 && x < GRIDWIDTH && y >= 0 && y < GRIDLENGTH) {
            game->grid[x][y].alive = !game->grid[x][y].alive;
        }
    }

    if (!(game->stats.frame % (FPS / game->stats.cps != 0 ? FPS / game->stats.cps : 1)) && !game->stats.paused) {
        for(int i = 0; i < GRIDWIDTH; i++) {
            for (int j = 0; j < GRIDLENGTH; j++) {
                Cell* cell = &game->grid[i][j];   
                char sibs = 0;
        
                for (int x = i-1 >= 0 ? i-1 : i; x <= (i+1 < GRIDWIDTH ? i+1 : i); x++) {
                    for (int y = j-1 >= 0 ? j-1 : j; y <= (j+1 < GRIDLENGTH ? j+1 : j); y++) {
                        sibs += game->grid[x][y].alive;
                    }
                }

                sibs -= cell->alive;  
                cell->next = cell->alive ? (sibs > 1 && sibs < 4) : sibs == 3;
            }
            
        }

        for(int i = 0; i < GRIDWIDTH; i++) {
            for (int j = 0; j < GRIDLENGTH; j++) {
                game->grid[i][j].alive = game->grid[i][j].next;
            }
        }
    }
}
