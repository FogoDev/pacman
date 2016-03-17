# CC especifica qual compilador estaremos usando
CC = gcc

# SDL Paths
SDL_CFLAGS := $(shell sdl2-config --cflags)
_SDL_LDFLAGS := $(shell sdl2-config --libs)
SDL_LDFLAGS= $(_SDL_LDFLAGS) -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# CFLAGS são as tags do gcc a serem usadas
CFLAGS= -g -c -Wall -Wfatal-errors -std=c11

# Pegando todos os arquivos .c e .o do projeto
VPATH= ./src

# Onde será gerado o executável
TARGET=bin/pacman

# Compilando
all: $(TARGET)

$(TARGET): main.o init.o loadMedia.o loadTexture.o closeProgram.o globals.o textureObject.o timeObject.o dotObject.o checkCollision.o tileObject.o touchesWall.o
	$(CC) $^ $(SDL_CFLAGS) -g -o $@ $(SDL_LDFLAGS)

main.o: main.c constantsNdefines.h init.h loadMedia.h closeProgram.h textureObject.h dotObject.h  timeObject.h tileObject.h globals.h checkCollision.h
	$(CC) $(CFLAGS) $^ 

globals.o: globals.c globals.h textureObject.h constantsNdefines.h timeObject.h dotObject.h tileObject.h
	$(CC) $(CFLAGS) $^

init.o: init.c init.h constantsNdefines.h globals.h 
	$(CC) $(CFLAGS) $^

checkCollision.o: checkCollision.c checkCollision.h constantsNdefines.h
	$(CC) $(CFLAGS) $^

loadMedia.o: loadMedia.c loadMedia.h constantsNdefines.h loadTexture.h globals.h textureObject.h tileObject.h
	$(CC) $(CFLAGS) $^

loadTexture.o: loadTexture.c loadTexture.h constantsNdefines.h globals.h 
	$(CC) $(CFLAGS) $^

closeProgram.o: closeProgram.c closeProgram.h constantsNdefines.h globals.h textureObject.h tileObject.h
	$(CC) $(CFLAGS) $^

textureObject.o: textureObject.c textureObject.h constantsNdefines.h 
	$(CC) $(CFLAGS) $^

timeObject.o: timeObject.c timeObject.h constantsNdefines.h
	$(CC) $(CFLAGS) $^

dotObject.o: dotObject.c dotObject.h constantsNdefines.h textureObject.h checkCollision.h tileObject.h touchesWall.h
	$(CC) $(CFLAGS) $^

tileObject.o: tileObject.c tileObject.h constantsNdefines.h textureObject.h
	$(CC) $(CFLAGS) $^

touchesWall.o: touchesWall.c touchesWall.h constantsNdefines.h checkCollision.h globals.h tileObject.h
	$(CC) $(CFLAGS) $^


# Comando de limpeza
clean:
	rm -rf *.o
	rm -rf bin/pacman
	rm -rf src/*.gch
