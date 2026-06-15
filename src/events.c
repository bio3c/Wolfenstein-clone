#include "wolf3d.h"

int handle_events(void)
{
  SDL_Event ev;

  while (SDL_PollEvent(&ev))
  {
    if (ev.type == SDL_QUIT)
      return 0;
    if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_ESCAPE)
      return 0;
  }
  return (1);
}

void handle_input(t_player *p, float dt)
{
	const Uint8 *key;

	key = SDL_GetKeyboardState(NULL);

	if (key[SDL_SCANCODE_W])
	{
		p->x += p->dir_x * MOVE_SPEED * dt;
		p->y += p->dir_y * MOVE_SPEED * dt;
	}
	if (key[SDL_SCANCODE_S])
	{
		p->x -= p->dir_x * MOVE_SPEED * dt;
		p->y -= p->dir_y * MOVE_SPEED * dt;
	}
	if (key[SDL_SCANCODE_A])
	{
		p->x -= p->plane_x * MOVE_SPEED * dt;
		p->y -= p->plane_y * MOVE_SPEED * dt;
	}
	if (key[SDL_SCANCODE_D])
	{
		p->x += p->plane_x * MOVE_SPEED * dt;
		p->y += p->plane_y * MOVE_SPEED * dt;
	}
	if (key[SDL_SCANCODE_LEFT])
	{
		rotate_player(p, -ROT_SPEED * dt);
	}
	if (key[SDL_SCANCODE_RIGHT])
	{
		rotate_player(p, ROT_SPEED * dt);
	}
}
