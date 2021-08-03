CC := clang++
LIBS := -lSDL2 -lSDL2main -lSDL2_image -lSDL2_mixer -lSDL2_ttf
INCLUDE := -I include
FLAGSO := -Wall -g -c -m64 -std=c++20 $(INCLUDE)
FLAGSB := -O3 -s $(LIBS)
EXEC_FILE := ./build/main

$(EXEC_FILE): ./obj/main.o ./obj/renderwindow.o
	$(CC) ./obj/*.o -o ./build/main $(FLAGSB)

./obj/main.o: ./src/main.cpp
	$(CC) ./src/main.cpp -o ./obj/main.o $(FLAGSO)

./obj/renderwindow.o: ./src/renderwindow.cpp
	$(CC) ./src/renderwindow.cpp -o ./obj/renderwindow.o $(FLAGSO)

./obj/math.o: ./src/math.cpp
	$(CC) ./src/math.cpp -o ./obj/math.o $(FLAGSO)

clean:
	rm ./obj/*.o
	rm ./build/main
	rm ./bin/main
