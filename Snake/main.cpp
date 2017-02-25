#include <curses.h>
#include "snake.h"
#include <iostream>

using namespace std;
extern int maxX;
extern int maxY;

int main() {
	
	int x,y,cd;
	Direction d;
	int c;
	bool gameEnded = false;
	srand(time(NULL)); 
	initscr();
	cbreak();		// Disable buffering, making input available to the program immediately
	timeout(1000);		// Wait user's input for at most 1s
	keypad(stdscr, TRUE);	// Enable input from arrow keys
	curs_set(0); 			// Hide cursor
	getmaxyx(stdscr, maxY, maxX);	// Get max X and Y of the terminal
	printw("%d %d", maxX, maxY);

	x=rand()%maxX;
	y=rand()%maxY;
	cd=rand()%4;
	switch(cd)
	{
		case 0:
		d=UP;
		break;
		case 1:
		d=DOWN;
		break;
		case 2:
		d=RIGHT;
		break;
		case 3:
		d=LEFT;
		break;
	}

	Snake snake(x,y,d);

	
	snake.GenerateNewTarget();
	
	while (!gameEnded) {
		c = getch();
		switch (c) {
		case KEY_UP:
			if (snake.getdir()!=DOWN)
			snake.SetDir(UP);
			break;
		case KEY_DOWN:
			if (snake.getdir()!=UP)
			snake.SetDir(DOWN);
			break;
		case KEY_LEFT:
			if (snake.getdir()!=RIGHT)
			snake.SetDir(LEFT);
			break;
		case KEY_RIGHT:
			if (snake.getdir()!=LEFT)
			snake.SetDir(RIGHT);
			break;
		default:
			break;
		}

		if (c == 'q' || c == 'Q'){
			break;
		}
		gameEnded = !snake.MoveSnake();
	}
	
	snake.DeleteSnake();
	endwin();	// Restores the terminal after Curses activity
}
