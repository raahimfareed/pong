CC := clang++
LIBS := -lSDL2 -lSDL2main -lSDL2_image -lSDL2_mixer -lSDL2_ttf
INCLUDE := -I include
FLAGSO := -Wall -g -c -m64 -std=c++20 $(INCLUDE)
FLAGSB := -O3 -s $(LIBS)
EXEC_FILE := ./build/main

$(EXEC_FILE): ./obj/main.o ./obj/renderwindow.o ./obj/math.o ./obj/entity.o ./obj/game.o ./obj/input.o ./obj/player.o
	$(CC) ./obj/*.o -o ./build/main $(FLAGSB)

./obj/main.o: ./src/main.cpp
	$(CC) ./src/main.cpp -o ./obj/main.o $(FLAGSO)

./obj/renderwindow.o: ./src/renderwindow.cpp
	$(CC) ./src/renderwindow.cpp -o ./obj/renderwindow.o $(FLAGSO)

./obj/math.o: ./src/math.cpp
	$(CC) ./src/math.cpp -o ./obj/math.o $(FLAGSO)

./obj/entity.o: ./src/entity.cpp
	$(CC) ./src/entity.cpp -o ./obj/entity.o $(FLAGSO)

./obj/game.o: ./src/game.cpp
	$(CC) ./src/game.cpp -o ./obj/game.o $(FLAGSO)

./obj/input.o: ./src/input.cpp
	$(CC) ./src/input.cpp -o ./obj/input.o $(FLAGSO)

./obj/player.o: ./src/player.cpp
	$(CC) ./src/player.cpp -o ./obj/player.o $(FLAGSO)

clean:
	rm ./obj/*.o
	rm ./build/main
	rm ./bin/main
