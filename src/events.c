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
