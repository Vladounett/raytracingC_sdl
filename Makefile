CC = gcc
CFLAGS = -Wall -Wextra -g
LIBFLAGS = `sdl2-config --cflags --libs` -lm

all: raytracing

raytracing: raytracing.c circles.c
	$(CC) $(CFLAGS) raytracing.c circles.c $(LIBFLAGS)

clean:
	rm -f a.out
