CC := clang++
LIBS := -lSDL2 -lSDL2main -lSDL2_image -lSDL2_mixer -lSDL2_ttf
INCLUDE := -I include
FLAGSO := -Wall -g -c -m64 -std=c++20 $(INCLUDE)
FLAGSB := -O3 -s $(LIBS)
EXEC_FILE := ./build/main

$(EXEC_FILE): ./obj/main.o
	$(CC) ./obj/*.o -o ./build/main $(FLAGSB)

./obj/main.o: ./src/main.cpp
	$(CC) $(FLAGSO) ./src/main.cpp -o ./obj/main.o
