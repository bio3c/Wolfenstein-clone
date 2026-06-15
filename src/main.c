#include "wolf3d.h"

int main(void)
{
  SDL_Window    *win;
  SDL_Renderer  * rend;
  SDL_Texture   *tex;
  uint32_t      *buf;
  int           running;
  t_player      player;

  init_player(&player);

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    return 1;
  win = SDL_CreateWindow("wolf3d", 0, 0, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
  if (!win)
    return 2;

  rend = SDL_CreateRenderer(win, -1, 0);
  if (!rend)
    return 3;

  buf = create_buffer(SCREEN_W, SCREEN_H);

  tex = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGBA8888,
      SDL_TEXTUREACCESS_STREAMING, SCREEN_W, SCREEN_H);

  running = 1;
  while (running)
  {
    running = handle_events();

    clear_buffer(buf, SCREEN_W, SCREEN_H, 0x222222FF);
    draw_minimap(buf);
    draw_player_mini(buf, &player);
    put_pixel(buf, SCREEN_W, SCREEN_W / 2, SCREEN_H / 2, 0XFF0000FF);

    SDL_UpdateTexture(tex, NULL, buf, SCREEN_W * sizeof(uint32_t));
    SDL_RenderCopy(rend, tex, NULL, NULL);
    SDL_RenderPresent(rend);
  }
  SDL_DestroyTexture(tex);
  free(buf);
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}
