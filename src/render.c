#include <wolf3d.h>

#define MAP_SCALE 12

void draw_minimap(uint32_t *buf)
{
  int cell;
  int sx, sy;

  for (int y = 0; y < MAP_H; y++)
  {
    for (int x = 0; x < MAP_W; x++)
    {
      cell = get_cell(x, y);
      if (cell == 0)
          cell = 0x333333FF;
      else if (cell == 1)
        cell = 0x777777FF;
      else
        cell = 0xBB4444FF;
      sy = y * MAP_SCALE;
      while (sy < (y + 1) * MAP_SCALE)
      {
        sx = x * MAP_SCALE;
        while (sx < (x + 1) * MAP_SCALE)
        {
          put_pixel(buf, SCREEN_W, sx, sy, cell);
          sx++;
        }
        sy++;
      }
    } 
  }
}

void draw_player_mini(uint32_t *buf, t_player *p)
{
  int px, py, lx, ly;

  px = (int)(p->x * MAP_SCALE);
  py = (int)(p->y * MAP_SCALE);
  for (int dy = -1; dy <= 1; dy++)
    for (int dx = -1; dx <= 1; dx++)
      put_pixel(buf, SCREEN_W, px + dx, py + dy, 0x00FF00FF);

  lx = (int)((p->x + p->dir_x * 4) * MAP_SCALE);
  ly = (int)((p->y + p->dir_y * 4) * MAP_SCALE);

  put_pixel(buf, SCREEN_W, lx, ly, 0x00FF00FF);
}
