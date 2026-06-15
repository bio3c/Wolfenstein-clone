#ifndef WOLF3D_H
#define WOLF3D_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include "types.h"

#define SCREEN_W 960
#define SCREEN_H 540
#define MAP_W 24
#define MAP_H 24
#define ROT_SPEED 3.0f
#define MOVE_SPEED 3.0f

int handle_events(void);
void handle_input(t_player *p, float dt);
int get_cell(int x, int y);

uint32_t  *create_buffer(int w, int h);
void      put_pixel(uint32_t *buf, int w, int x, int y, uint32_t color);
void      clear_buffer(uint32_t *buf, int w, int h, uint32_t color);
void      draw_minimap(uint32_t *buf);
void      draw_player_mini(uint32_t *buf, t_player *p);
void      init_player(t_player *p);
void      rotate_player(t_player *p, float angle);

#endif
