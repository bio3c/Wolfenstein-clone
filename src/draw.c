#include <stdlib.h>
#include <wolf3d.h>

uint32_t *create_buffer(int w, int h)
{
  return (malloc(w * h * sizeof(uint32_t)));
}

void put_pixel(uint32_t *buf, int w, int x, int y, uint32_t color)
{
  buf[y * w + x] = color;
}

void clear_buffer(uint32_t *buf, int w, int h, uint32_t color)
{
  for (int i = 0; i < w * h; i++)
      buf[i] = color;
}
