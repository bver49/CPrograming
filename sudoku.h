#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{
public:
	void GiveQuestion();
    void ReadIn();
    void Solve();
    void Printboard(int ch);
    void next();
    void record();
    void back();
    void fill();

private:
    int x,y;
    int counts;
    int no;
	int board[12][12];
    int answer[12][12];
    int blank[144][2];
    int pos[10];
};

#endif

