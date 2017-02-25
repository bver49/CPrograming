#include <iostream>
#include <ctime>
#include <cstdlib>
  
using namespace std;
struct cell 
{
	int marked=0,opened=0,bombed=0,count=0;       //宣告一個資料型態cell    marked用來判定是否標記  opened用來判定是否打開(有炸彈的格子例外,opened值永遠為1) bombed用來判定是否有炸彈 1=是 0=否  count用來存取周圍九宮格內炸彈總數 
	char show;                                    //以一個字元型態的變數show 來顯示雷區的圖案  沒被開啟顯示'.' 標記顯示'M'   
};

void open(cell **,int ,int,int);                 //用來打開使用者所選定的座標 
void opennear(cell **,int,int,int);             //用來打開使用者所選定的座標旁邊的座標 
void printmap(cell **,int);                     //用來顯示最新的地雷區 
void mark (cell **,int,int);                   //用來標記座標 
int win(cell**,int);                           //用來判定是否獲勝 
int bombcount(cell**,int,int,int);           //用來計算每個座標 周圍九宮格內炸彈數總和 


int main()
{
   srand(time(NULL));                       //用時間選取一組亂數組 
   int start,game_choose=0;
   int x=0,y=8,m,h,v;                     //宣告變數 並把y軸長度設定為8 
   cout << "1.easy mode"<<endl<<"2.hard mode"<<endl;  //選擇難易度 1是容易 2是困難 
   cin >> start;
   	while (start!=1&&start!=2 ) 
	{
	 cout << "please enter again(1.easy/2.hard)"<<endl;
	 cin >>start;
	}
   if(start==1)x=8;                            //當選擇難度是容易時 x軸長度是8 
   if(start==2)x=16;                          //當選擇難度是困難時 x軸長度是16 
   
   cell **map;                              //動態配置邊界為8*8或16*8的二維陣列  
   map = new cell*[x];                         
   for(int a=0; a<x; a++)                          
   map[a] = new cell[y];   
   
   for(int a=0;a<x;a++)               
    { 
     for(int b=0;b<y;b++)
	 {
	 map[a][b].bombed=0;	              //放置炸彈 每個座標有炸彈的機率是20% 
	 m=(rand()%10)+1; 
	  if(m<=2)
	  {
	   map[a][b].bombed=1;                   //讓有炸彈的格子 bombed值=1(該格子有炸彈)  
	   map[a][b].opened=1;                  //讓有炸彈的格子 opened值=1 
	  } 
	  
	 map[a][b].show='.';	                //讓每一格座標顯示'.' 
	 } 
	} 
    
	for(int a=0;a<x;a++)
    { 
     for(int b=0;b<y;b++)
     {
     bombcount(map,a,b,x);               //計算每個座標周圍九宮格內炸彈總數 
 	 }
	}
   
    printmap(map,start);                //印出最新雷區情形 
	
while(win(map,x)==1)                          //一直反覆詢問使用者下一步動作 跳出迴圈的條件是函數win回傳的值不等於1 
{
	cout<<endl<<"1.open\n2.mark\n";
	cin>>game_choose;                                       //讓使用者選定下一步要打開雷區還是標記 1是打開雷區 2是標記 
	while (game_choose!=1&&game_choose!=2 )                            
	{
	 cout << "please enter again(1.open/2.mark)"<< endl;
	 cin >>game_choose;
	}
	
	if(game_choose==1)                                             
	{
	 cout<<"[Open](x y):";
	 cin>>h>>v;                                                           //輸入座標 
	 while (h>x||v>8||h<1||v<1)                                           //若是座標超過範圍，印出重新輸入介面 
	 {
	  cout << "please enter again range x=1~"<<x<<" y=1~8 (x y):";
	  
	  cin >>h>>v;                                                       
	 }
     
	 if(map[h-1][v-1].bombed==1)                                        //如果選定的座標有炸彈(bombed值=1) 則顯示You lose! 同時程式結束 
	 {
	  system("CLS");
	  cout<<"You lose!";
	   for (int i= 0; i<x;i ++ )		                                  //程式結束 釋放動態二維陣列所佔的記憶體 
         delete [] map[i];
	      delete [] map;
	  return 0;
     }
     open(map,h-1,v-1,x);                                                //開啟所選定的座標 
	 printmap(map,start);                                                //印出最新雷區情形  
	
	}
	 
	if(game_choose==2)
	{
	 cout<<"[Mark](x y):";
	 cin>>h>>v;                                                          //輸入座標 
	 while (h>x||v>8||h<1||v<1)                                         //若是座標超過範圍，印出重新輸入介面 
	 {
	  cout << "please enter again range x=1~"<<x<<" y=1~8 (x y):";
	  
	  cin >>h>>v;                                                     
	 }
	 mark(map,h-1,v-1);                                                   //標記該座標 
	 printmap(map,start);                                                 //印出最新雷區情形 
	}
	
}	
	system("CLS");                                                      
	cout<<"You win!";                                                 //當獲勝時會跳出while迴圈 並顯示you win! 
	for (int i= 0; i<x;i ++ )		                                  //程式結束 釋放動態二維陣列所佔的記憶體 
    	delete [] map[i];
	    delete [] map;
	return 0;
}

void printmap(cell **map,int start)
{	
	 system("CLS");
	 int y=8,x;                                            
	 
   	 if(start==1) x=8;                                       //當選擇難度是容易時 x軸長度是8  
   	 if(start==2) x=16;                                      //當選擇難度是困難時 x軸長度是16 
   	 cout<<"  X";
     for(int z=1;z<=8;z++)                                   //印出X軸座標1~8  
     cout<<" "<<z;                                          
     cout<<endl<<"Y ";

	 for(int z=1;z<=x+11;z++)                                //印出上方邊界 
	 cout<<"_";
	 cout<<endl;

	for(int b=0;b<y;b++)
	{
	 cout<<b+1<<' '<<"|";                                 //印出y軸座標及左方邊界 
	  for(int a=0;a<x;a++)
	  {
	   cout<<" "<<map[a][b].show;                         //印出每個座標的所存取的顯示結果 
	   
	   if(start==2&&a==15) cout<<" |"<<endl;              //如果是困難模式 x軸每印16個跳一行 
	   if(start==1&&a==7)  cout<<" |"<<endl;              //如果是簡易模式 x軸每印8個跳一行  
	  }  
	}
	 cout<<"  ";                                         //印出下方邊界 
     for(int z=1;z<=x+11;z++)
     cout<<"-";
    
}

void open(cell **map,int h,int v,int x)
{
    if(map[h][v].count==0&&map[h][v].marked==0)
    {
     map[h][v].show=' ';
     opennear(map,h,v,x);
    }
    if(map[h][v].count!=0&&map[h][v].marked==0)
    { 
    map[h][v].opened=1; 
	   switch(map[h][v].count)
	   {
		case 1:  map[h][v].show='1'; break;
		case 2:  map[h][v].show='2'; break;
		case 3:  map[h][v].show='3'; break;
		case 4:  map[h][v].show='4'; break;
		case 5:  map[h][v].show='5'; break;
	   }
    }

}

void opennear(cell **map,int h,int v,int x)
{

 if(map[h][v].bombed==0&& map[h][v].count==0&&map[h][v].opened==0)
  {
   map[h][v].show=' ';
   map[h][v].opened=1;
    for ( int a=h-1;a<=h+1; a++ ) 
	{
		for ( int b= v-1 ;b<=v+1;b++ )
			if ( a>= 0 && b>= 0 && a<x && b<8 && map[a][b].opened == 0 ) 
			{
				if ( map[a][b].count== 0 ) 
				{
					map[a][b].show=' ';
					opennear(map, a, b,x);
				}
				else
				{       
						map[a][b].opened=1; 
						switch(map[a][b].count)
						{
						case 1:  map[a][b].show='1'; break;
						case 2:  map[a][b].show='2'; break;
						case 3:  map[a][b].show='3'; break;
						case 4:  map[a][b].show='4'; break;
						case 5:  map[a][b].show='5'; break;
						}
				}
			}
	}
  }
 } 
void mark (cell **map,int h,int v) 
{                                     //傳入使用者想標記的座標 
 if(map[h][v].marked==0&&map[h][v].opened==0&&map[h][v].bombed==0)       //如果該座標 沒被標記 沒被打開 沒有炸彈 
  {
   map[h][v].show='M';                                                   //該座標顯示結果變成'M' 
   map[h][v].marked=1;                                                   //marked值變成1(被標記) 
  }
   else if(map[h][v].marked==1&&map[h][v].opened==0&&map[h][v].bombed==0) //如果該座標 被標記 沒被打開 沒有炸彈  
  {
   map[h][v].show='.';                                                   //該座標顯示結果變成'.' 
   map[h][v].marked=0;                                                   //marked值變成0(取消標記) 
  }
   else if(map[h][v].marked==0&&map[h][v].opened==1&&map[h][v].bombed==0) //如果該座標 沒被標記 但已被打開 沒有炸彈   
  {
   map[h][v].marked=1;                                                   //marked值變成1 且不改變顯示結果 
  }
   else if(map[h][v].marked==0&&map[h][v].opened==1&&map[h][v].bombed==1)  //如果該座標 沒被標記 沒被打開 且有炸彈 (bombed和opened值為1) 
  {
   map[h][v].show='M';                                                     //該座標顯示結果變成'M'                              
   map[h][v].marked=1;                                                     //marked值變成1(被標記)  
  }
   else if(map[h][v].marked==1&&map[h][v].opened==1&&map[h][v].bombed==1)  //如果該座標 被標記 沒被打開 且有炸彈 (bombed和opened值為1)  
  {
   map[h][v].show='.';                                                      //該座標顯示結果變成'.'  
   map[h][v].marked=0;                                                      //marked值變成0(取消標記) 
  }  
}

int bombcount(cell **map,int h,int v,int x)   //會傳入一個座標 並計算該座標周圍8個格子內炸彈數總和 
{
	int d=0;                           //初始定義d=0 
if((h-1)>=0&&(v-1)>=0)                 //如果該座標左上方的格子沒超過邊界 
d+=map[h-1][v-1].bombed;               //把d加上該格子的bombed值
if((h-1)>=0)                           //如果該座標左方 的格子沒超過邊界  
d+=map[h-1][v].bombed;                 //把d加上該格子的bombed值 
if((h-1)>=0&&(v+1)<=7)                 //如果該座標左下方的格子沒超過邊界 
d+=map[h-1][v+1].bombed;               //把d加上該格子的bombed值
if((v-1)>=0)                           //如果該座標上方的格子沒超過邊界  
d+=map[h][v-1].bombed;                 //把d加上該格子的bombed值
if((v+1)<=7)                           //如果該座標下方的格子沒超過邊界  
d+=map[h][v+1].bombed;                 //把d加上該格子的bombed值 
if((h+1)<=(x-1)&&(v-1)>=0)             //如果該座標右上方的格子沒超過邊界 
d+=map[h+1][v-1].bombed;               //把d加上該格子的bombed值 
if((h+1)<=(x-1))                       //如果該座標右方的格子沒超過邊界 
d+=map[h+1][v].bombed;                 //把d加上該格子的bombed值 
if((h+1)<=(x-1)&&(v+1)<=7)             //如果該座標右下方的格子沒超過邊界 
d+=map[h+1][v+1].bombed;               //把d加上該格子的bombed值 
map[h][v].count=d;                    //將d最終的數值 丟給該座標的count值 
}

int win(cell **map,int x)        //計算雷區所有格子的opened值 用來判定是否獲勝  若獲勝所以格子的opened值總和會等於格子個數 
{
	int y=8,c=0;                   
	
 for(int a=0;a<x;a++)
     for(int b=0;b<y;b++)
	 {
	  c+=map[a][b].opened;              //把c加上每個座標的opened值 
	 
	 } 
  if(c==x*y)                          //如果c值等於8*8(容易)或8*16(困難) 
  return 0;                           //回傳0 (遊戲結束 玩家獲勝) 
  else 
  return 1;                          //回傳1 (遊戲繼續) 
}


