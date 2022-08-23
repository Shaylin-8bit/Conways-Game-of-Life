#include "raylib.h"
#include "raymath.h"

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

#define SCREENWIDTH  800
#define SCREENLENGTH 600
#define GRIDWIDTH    1000
#define GRIDLENGTH   1000
#define CELLSIZE     16
#define CELLSIZE_MAX 255
#define CELLSIZE_MIN 4
#define FPS          60   // Frames per second
#define CPS          16    // Cycles per second   *for cells
#define PPS          16   // Pixels per second   *for player movement speed

typedef struct {
    char alive;
    char next;
} Cell;

typedef struct {
    unsigned int fps;
    unsigned int living_cells;
    char debug;
    unsigned int frame;
    unsigned int cycle;
    char paused;
    float cellsize;
    unsigned char grid;
    unsigned int cps;
} Stats;

typedef struct {
    Cell** grid;
    Vector2 player;
    Camera2D camera;
    Vector2 mouse;
    RenderTexture2D texture;
    float scale;
    Stats stats;
} Game;

void gen_grid(Game* game);
void gen_player(Game* game);
void gen_scale(Game* game);
void gen_camera(Game* game);
void gen_texture(Game* game);
void gen_mouse(Game* game);
void gen_stats(Game* game);

void update_grid(Game* game);
void update_player(Game* game);
void update_scale(Game* game);
void update_camera(Game* game);
void update_texture(Game* game);
void update_mouse(Game* game);
void update_stats(Game* game);

Game init_game(void);

void update_game(Game* game);
void draw_screen(Game* game);
