#include "wolf3d.h"

void init_player(t_player *p)
{
  p->x        = 12.0f;
  p->y        = 12.0f;
  p->dir_x    = -1.0f;
  p->dir_y    = 0.0f;
  p->plane_x  = 0.0f;
  p->plane_y  = 0.66f;
}
