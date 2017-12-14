#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

void ins_sort(string *choose,int n);

int main(int argc, char *argv[]){
	int amount=0;									//記錄要抽出的人數
	string filename;
    string line;                      				//用來儲存讀取的檔案中每一行字串的變數
    string name[80];								//用來儲存所有學生的學號和名字
    string *choose;									//用來儲存抽出的學生的學號和名字
    int n=0;
    int randn;										//記錄隨機抽取的數字
    srand(time(NULL));

    cout<<"請輸入學生名單完整檔名:";
    cin>>filename;

    ifstream fin(filename);              			//讀取指定名稱的檔案

    cout<<"請問要抽出多少人數:";
	cin>>amount;

    choose = new string[amount];
	
	while(getline(fin, line)){							//一行一行讀取檔案中的內容 並存到name array中 直到讀不到內容就結束			
		name[n]=line;								
		n++;
	}
	fin.close();                                      //關閉檔案


	for(int x=1;x<=amount;x++){						//隨機抽出指定的人數 並將抽到的人的資料存到choose array中
		randn=(rand()%amount)+1;
		while(name[randn]==" "){
			randn=(rand()%amount)+1;
		}
		choose[x]=name[randn];
		name[randn]=" ";
	}

	ins_sort(choose,amount);                         //執行insertion sort

	for(int x=1;x<=amount;x++)                       //依照排序列出抽到的人
		cout<<choose[x]<<endl;

	return 0;
}


void ins_sort ( string *choose,int n){										
	for (int x=1 ; x<=n ;x++){
		for (int y=x;y>1;y--){
			string key;
			if ( choose[y] < choose[y-1] ){
				key = choose[y-1] ;     
				choose[y-1] = choose[y] ;
				choose[y] = key ;
			}
		}
	}
}