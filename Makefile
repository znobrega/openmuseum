CC = g++

all:
	$(CC) main.cpp -lglut -lGLU -lGL -lSOIL -lassimp -I. -I/usr/include -o museum

clean:
	rm museum

