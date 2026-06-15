#include "wolf3d.h"
#include <math.h>

void init_player(t_player *p)
{
  p->x        = 12.0f;
  p->y        = 12.0f;
  p->dir_x    = -1.0f;
  p->dir_y    = 0.0f;
  p->plane_x  = 0.0f;
  p->plane_y  = 0.66f;
}

void rotate_player(t_player *p, float angle)
{
	float old_dir_x;
	float old_plane_x;
	
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);

	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_x = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}
