
#include <iostream>
#include "sudoku.h"
#include <cstdlib>
#include <ctime>

using namespace std;


void Sudoku::GiveQuestion()
{
	srand(time(NULL));  
	int a,b,c,d,e,f,g,h,i;        
	int num[9];
    for(int i=0;i<9;i++)
        num[i]=0;

    for(int j=0;j<9;j++)
    {
        int k=rand()%9+1;
        if(num[k-1]==0)
        {
            num[k-1]=1;

			switch(j)
            {
                case 0:a=k;
                case 1:b=k;
                case 2:c=k;
                case 3:d=k;
                case 4:e=k;
                case 5:f=k;
                case 6:g=k;
                case 7:h=k;
                case 8:i=k;
            }
        }
        else j--;
    }

	int fboard[12][12]={				           //給予
	{ a, b, c, d, e, f, g, h, i,-1,-1,-1},
	{ d, e, f, g, h, i, a, b, c,-1,-1,-1},
	{ g, h, i, a, b, c, d, e, f,-1,-1,-1},
	{-1,-1,-1, e, f, d, h, i, g, b, c, a},
	{-1,-1,-1, h, i, g, b, c, a, e, f, d},
	{-1,-1,-1, b, c, a, e, f, d, h, i, g},
	{ b, c, a, i, g, h,-1,-1,-1, f, d, e},
	{ e, f, d, c, a, b,-1,-1,-1, i, g, h},
	{ h, i, g, f, d, e,-1,-1,-1, c, a, b},
	{ c, a, b,-1,-1,-1, f, d, e, g, h, i},
	{ f, d, e,-1,-1,-1, i, g, h, a, b, c},
	{ i, g, h,-1,-1,-1, c, a, b, d, e, f}
	};

	for(int i=0;i<12;i++)
		for(int j=0;j<12;j++)
		{
			if(i!=11 && j!=11)
			if(fboard[i][j]!=-1)
			{
				int r=rand()%10;
				if(r<=1)
				fboard[i][j]=0;
			}

		}

	int t=rand()%4,t1=rand()%4,buff;

	if(t!=t1)
	for(int j=3*t,k=3*t1; j<=(3*t)+2 ; j++,k++)
		for(int i=0;i<12;i++)
		{
			buff=fboard[j][i];
			fboard[j][i]=fboard[k][i];
			fboard[k][i]=buff;			
		}

	for(int y=0;y<12;y++)
		for(int x=0;x<12;x++)
		{
			board[x][y]=fboard[x][y];
		}

	Printboard(1);

}


void Sudoku::ReadIn()
{
	for(int j=0;j<12;j++)
		for(int i=0;i<12;i++)
		{
			cin>>board[i][j];
		}
	Printboard(1);
}


void Sudoku::Printboard(int ch)
{
		if(ch==1)
		{
			for(int y=0;y<12;y++)
			{
				for(int x=0;x<12;x++)
				{
					if(board[x][y]!=-1)
						cout<<" ";
						cout<<board[x][y]<<" ";
				}
					cout<<endl;
			}	
			cout<<endl;
		}
		if(ch==2)
		{
			for(int y=0;y<12;y++)
			{
				for(int x=0;x<12;x++)
				{
					if(answer[x][y]!=-1)
						cout<<" ";
						cout<<answer[x][y]<<" ";
				}
					cout<<endl;
			}	
			cout<<endl;	
		}

}

		
void Sudoku::record()
{
	blank[counts][0]=x;
	blank[counts][1]=y;
	counts++;
}


void Sudoku::next()
{
	while(x<12 && y<12 && x>=0 && y>=0 && (board[x][y]>0 ||board[x][y]==-1))
	{
		if(x==10 && y==11)
		{
			x=11;
			y=11;
			break;
		}
		else if(x==11)
		{
			x=0;
			y++;
		}
		else
		x++;
	}
}


void Sudoku::back()
{
	if(counts==0)
	{	
		x=-1;
		y=-1;
		return;
	}
	counts--;
	x=blank[counts][0];
	y=blank[counts][1];
}


void Sudoku::Solve()
{
	for(int j=0;j<144;j++)
		for(int i=0;i<2;i++)
			blank[j][i]=0;
	no=0;
	x=0;
	y=0;
	counts=0;
	next();			
	while(x<12 && y<12 && x>=0 && y>=0 && no<2)
	{	
		fill();
		if(board[x][y]==-2)
			break;
			
		if(board[x][y]>0)
		{
			record();
			next();
			if(x==11 && y==11)
			{
				back();
				no++;
				if(no<2)					
				{
					for(int j=0;j<12;j++)
						for(int i=0;i<12;i++)
							answer[i][j]=board[i][j];
				}
				
			}
		}
		else if(board[x][y]==0)
			back();
	}
			
		cout<<no<<endl;
		if(no==1)
			Printboard(2);
}

void Sudoku::fill()
{
			int _x,_y;
			_x=x-(x%3);
			_y=y-(y%3);

			for(int i=0;i<10;i++)
				pos[i]=0;
			
			for(int i=0;i<12;i++)
			{
				if(board[x][i]>0)
					pos[board[x][i]]++;			
				if(board[i][y]>0)
					pos[board[i][y]]++;
			}
			for(int j=_y;j<_y+2;j++)
				for(int i=_x;i<_x+2;i++)
					if(board[i][j]>0)
						pos[board[i][j]]++;
				
			for(int i=1;i<10;i++)
			{
				if(pos[i]>3)					
				{	
					board[x][y]=-2;
					return;
				}	
				else if(pos[i]==0 && i>board[x][y])
				{	
					board[x][y]=i;
					return;
				}

			}
			board[x][y]=0;

		
}
