INCLUDE=/usr/include/ncurses
LIB=ncurses

all: main.o snake.o
	g++ -g3 main.o snake.o -l$(LIB) -o snake
main.o: main.cpp
	g++ -c -g3 main.cpp -I$(INCLUDE)
snake.o: snake.cpp
	g++ -c -g3 snake.cpp -I$(INCLUDE)
clean: 
	rm -f *.o snake
