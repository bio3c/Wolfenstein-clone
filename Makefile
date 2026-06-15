NAME    = wolf3d
CC      = cc
RM      = rm -f

SDLDIR  = vendor/sdl2
PKG_CFG = PKG_CONFIG_PATH=$(SDLDIR)/lib/pkgconfig pkg-config
CFLAGS  = -Wall -Wextra -Iinc $(shell $(PKG_CFG) --cflags sdl2)
LDFLAGS = $(shell $(PKG_CFG) --libs sdl2)

SRCDIR  = src
SRCS    = $(SRCDIR)/main.c $(SRCDIR)/events.c $(SRCDIR)/draw.c $(SRCDIR)/map.c \
					$(SRCDIR)/render.c $(SRCDIR)/player.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:  
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
