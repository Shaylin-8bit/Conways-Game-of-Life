NAME  =  Life
INC   =  src/include/mainlib.h
C     =  gcc
FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o $(NAME)
OBJS  =  main.o game.o screen.o grid.o player.o scale.o camera.o texture.o mouse.o stats.o

Life: $(OBJS)
	$(C) $(OBJS) $(FLAGS)
	rm *.o
	./Life

main.o: src/main.c $(INC)
	$(C) src/main.c -c

game.o: src/game.c $(INC)
	$(C) src/game.c -c

screen.o: src/screen.c $(INC)
	$(C) src/screen.c -c

grid.o: src/grid.c $(INC)
	$(C) src/grid.c -c

player.o: src/player.c $(INC)
	$(C) src/player.c -c

scale.o: src/scale.c $(INC)
	$(C) src/scale.c -c

camera.o: src/camera.c $(INC)
	$(C) src/camera.c -c

texture.o: src/texture.c $(INC)
	$(C) src/texture.c -c

mouse.o: src/mouse.c $(INC)
	$(C) src/mouse.c -c

stats.o: src/stats.o $(INC)
	$(C) src/stats.c -c
