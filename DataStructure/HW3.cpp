
#include <fstream> 
#include <iostream>
using namespace std;


struct term          //建立一個struct term 
{
	int coe;       //係數               
	int exp;      //次方 
	struct term* next;     //下一個節點的位置 
};


void AddData(term *A, int _coe, int _exp);
void Output(term *A);
void InputData(term *A); 

int main()
{
	int m,n,exp,coe;
	ifstream file("input.txt");             //讀取input.txt 
	while(!file.eof())
	{         
		file >>m;                             //讀取有幾個多項式 
		cout<<"多項式個數:"<<m<<endl;  
		for(int x=0;x<m;x++)
		{  
			file >>n;                        //讀取多項式有幾項 
			cout<<"第"<<x+1<<"個多項式有"<<n<<"項 :";
			for(int y=0;y<n;y++)
			{
				file >> coe;                              
				file >> exp;
				cout<<coe<<"X^"<<exp;
				if(y!=n-1)
				cout<<"+";                //輸出係數及次方 
			}
		 	cout<<endl;
		}                     
	} 
	cout<<endl;
         
	term *A;                                          //新增一個term型態的pointer A 
	A=new term;                                        //新增一個節點 
	A->next = NULL;                                    //將資料輸入節點 
	InputData(A);      
	cout<<"所有多項式相加總合:"<<endl;                              
	Output(A);                                        //輸出linked list的資料 
	return 0;
}

void AddData(term *A, int _coe, int _exp)
{
	term *tmp = A;                   //新增一個結點tmp=A

	while(tmp->next!=NULL)             //當後面沒有節點時跳出    
	{
                
		if(tmp->next->exp == _exp)            //當讀入的次方與節點的次方相同 
		{
        	tmp->next->coe += _coe;            //將係數相加 
        	return ;                           //跳出函式 
        }
        
		else if(tmp->next->exp < _exp)              //當讀入的次方比節點的大  往前新增一個節點 
		{
			term *tmp2 = tmp->next;                 //新增一個節點tmp2 並將tmp資料存入 
			tmp->next =new term;                     
 			tmp->next->exp = _exp;                   //存入係數 
			tmp->next->coe=_coe;                     //存入次方 
			tmp->next->next = tmp2;                  //將tmp指向tmp2 
			return ;                                 //跳出函式 
		}
		else
		{                 
			tmp=tmp->next;                         //當讀入的次方比節點的小 繼續往下一個節點找 
		}
	}
	
	tmp->next =new term;                            //新增一個節點 
	tmp->next->next = NULL;
	tmp->next->coe = _coe;                          //存入係數 
	tmp->next->exp = _exp;                          //存入次方 
}

void Output(term *A)
{
	term *tmp = A->next;                           
	while(tmp!=NULL)            //後面沒有節點時跳出 
	{
		cout<<tmp->coe;         //輸出係數 
                
		if(tmp->exp!=0)           //當次方不等於0 
		cout<<"X^"<<tmp->exp;	//輸出次方		
				
		tmp = tmp->next;           //到下一個節點 
				
		if(tmp!=NULL)           //當後面還有節點 
		cout<<"+";              //印出"+" 
	}
}

void InputData(term *A)
{
	int m=0,n=0;                         //m表示有幾個多項式 n表示這多項式有幾項 
	int _coe=0, _exp=0;                  //暫時儲存exp跟coe的變數 
	ifstream file("input.txt");           //讀取input.txt 
	while(!file.eof())                  
	{
		file >>m;                              
		for(int x=0;x<m;x++)
		{  
			file >>n;
			for(int y=0;y<n;y++)
			{
				file >> _coe;                         //讀取係數 
				file >> _exp;                         //讀取次方 
				AddData(A, _coe, _exp);              //將係數次方新增到linked list 
		    }
		}                     
    }
}

