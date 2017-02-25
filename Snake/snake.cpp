#include "snake.h"
#include <curses.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>


using namespace std;

int targetX;
int targetY;
int maxX;
int maxY;

Snake::Snake(int x, int y, Direction direction) 
{
	head = new Node;
	head->x = x;
	head->y = y;
	head->prevNode = NULL;
	tail = head;
	dir = direction;
}

void Snake::DeleteSnake() 
{
	while(tail != NULL) {
		Node* temp = tail;
		tail = tail->prevNode;
		delete temp;
	}
}

void Snake::SetDir(Direction ndir) 
{
	dir = ndir;
}

void Snake::DrawSnake() {
	Node* temp =tail;
	
	while(temp != NULL) {
		mvaddch(temp->y, temp->x, '*');
		temp = temp->prevNode;
	}
}

void Snake::RemoveAtTail() {
	// Please implement this function	
	Node* temp=tail;					//先Node一個 temp 然後暫存snake->tail
	tail=tail->prevNode;		//讓snake->tail 往前指一個
	mvaddch(temp->y, temp->x, ' ');			//然後把原本位置的*清空
	delete temp;							//刪除temp
}

void Snake::InsertAtHead(Node* newHead) {
	// Please implement this function
	head->prevNode=newHead;			//丟進一個newHead把他只到snake->head->prevNode
	head=newHead;					//然後再把snake->head指向nreHead
	head->prevNode=NULL;				//再把snake->head->prevNode清空掉
	
}


bool Snake::MoveSnake() {
	// Please implement this function
	DrawSnake();						//先把蛇蛇畫出來
	Node* node= new Node;					//給一個node點去判斷方向

	switch(dir)
	{
		case UP:
			node->x=head->x;
			node->y=head->y-1;
			dir=UP;
			break;
		case DOWN:
			node->x=head->x;
			node->y=head->y+1;
			dir=DOWN;
			break;
		case LEFT:
			node->x=head->x-1;
			node->y=head->y;
			dir=LEFT;
			break;
		case RIGHT:
			node->x=head->x+1;
			node->y=head->y;
			dir=RIGHT;			
			break;
		default:
			break;
	}
		
	InsertAtHead(node);			//判斷方向完，就要往那個方向前進一格，所以在頭部先加一個點
	DrawSnake();					//在畫蛇一遍
	
	Node* tempH = head;
	
	if(tempH->x==targetX&&tempH->y==targetY)		//判斷如果吃到目標，則RemoveAtTail不啟動，才可以多一個身體
		GenerateNewTarget();					//如果沒吃到目標，則RemoveAtTail啟動，這樣身體就不會增加
	else
		RemoveAtTail();
	
	if((head->x >maxX)||(head->y > maxY)||(head->x < 0)||(head->y < 0))
		return false;								//如果頭撞到邊界，則回傳false，遊戲則停止
	
	return true;
}

void Snake::GenerateNewTarget() {	
	targetX = rand() % maxX;
	targetY = rand() % maxY;
	mvaddch(targetY, targetX, '$');
}

Direction Snake::getdir()
{
 	return dir;
}

