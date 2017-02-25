#ifndef SNAKE_H
#define SNAKE_H


class Node {
public:
	int x;
	int y;
	Node* prevNode;
};

enum Direction{
		UP,DOWN,LEFT,RIGHT
};

				
class Snake
{
	public:
	Snake(int x, int y, Direction direction);
	void DeleteSnake();
    	void RemoveAtTail();
    	void DrawSnake();			// Draw the entire snake
	bool MoveSnake();
	void InsertAtHead(Node* node);
 	void GenerateNewTarget();		// Generate and draw a new target on the screen
	void SetDir(Direction dir);	// Set direction
	Direction getdir();
    private:
	Node* head;
	Node* tail;
	Direction dir;				// Direction of the snake
};

#endif

