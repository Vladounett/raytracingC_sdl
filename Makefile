CC = gcc
CFLAGS = -Wall -Wextra -g
LIBFLAGS = `sdl2-config --cflags --libs` -lm

all: raytracing

raytracing: raytracing.c geometry.c const.h
	$(CC) $(CFLAGS) raytracing.c geometry.c $(LIBFLAGS)

clean:
	rm -f a.out
