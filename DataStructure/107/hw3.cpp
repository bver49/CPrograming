
#include <fstream> 
#include <iostream>
#include <iomanip>

using namespace std;


struct term          //建立一個struct term 
{         
	int num;      
	int x;
	int y;
	struct term* next;     //下一個節點的位置 
};

void Putinarray(term *A,int array[][4]);
void InputData(term *A); 

int main()
{
	int array[4][4];
	term *A;                                          //新增一個term型態的pointer A 
	A=new term;                                        //新增一個節點 
	A->next = NULL;                                    //將資料輸入節點 
	InputData(A);                                 
	Putinarray(A,array);                                        
	for(int x=0;x<4;x++){
		for(int y=0;y<4;y++){
			cout<<setw(2)<<array[x][y]<<" ";
		}
		cout<<endl;
	}

	return 0;
}

void Putinarray(term *A,int array[][4])
{
	term *tmp = A;                           
	for(int x=0;x<4;x++)
		for(int y=0;y<4;y++){
			array[tmp->x][tmp->y]=tmp->num;
			tmp=tmp->next;
		}    
}

void InputData(term *A)
{ 
	int _x=0,_y=0;                        
	int _num=0;
	term *tmp = A;   
	ifstream file("input.txt");    
	while(!file.eof())                  
	{
		file >>_x>>_y>>_num;  
		A->x=_x;
		A->y=_y;
		A->num=_num;
		A->next =new term;                            
		A->next->next = NULL;      
		A=A->next;                    	                   
    }
}

