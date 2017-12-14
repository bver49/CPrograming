/*
This code can be compiled and run ok.
Usage:let user enter a=lower bound b=upper bound n=how many numbers,and random n numbers.Sort this number
bycounting sort, radix sort and bucket sort,then print out the numbers that is sorted.
Input file:none
Output files:none
 
Pseudocode:
CS(A[],n,k)
int C[n+1],D[k+1]
for x<-1 to k
do D[x]<-0
for x<-1 to n
do D[A[x]]=D[A[x]]+1
for x<-k to 1
do D[x-1]=D[x-1]+D[x]
for x<-1 to n
do C[D[A[x]]]=A[x]
D[A[x]]=D[A[x]]-1
for x<-1 to n
do A[x]=C[x]

 
RS(A[],n,k)
int digit=1
while (k>0)
do k = k/10 ;                          
if (k>0)
digit=digit+1

for x<-1 to digit
 int num=pow(10,x)
 int key[n+1]
 
 for y<-1 to n
 key[y] = A[y]% num
 key[y] = key[y]*10/num
 
 for z<-1 to n
    for j<-z to 0
    int buff
 if (key[j]>key[j-1])
 do buff=A[j-1];
    A[j-1]=A[j];
    A[j]=buff;
    buff=key[j-1];
    key[j-1]=key[j];
    key[j]=buff;
 
 
BS(A[],n,k)
int bucket[10][n+1];
int digit=1
while (k>0)
do k = k/10 ;
if (k>0)
digit=digit+1
 
for x<-0 to 9
 for y<-0 to n
do bucket[x][y]=0

for x<-1 to digit
 int num=pow(10,x)
 for y<-1 to n
    for z<-1 to n
 int r=(A[y]%num)*10/num
 if(bucket[r][z]==0)
 do bucket[r][z]=A[y];
 break;
 
 for p<-9 to 0
    for j<-1 to n
        for q<-j to 2
 int buff;
 if (bucket[p][q]>bucket[p][q-1])
 do buff<-bucket[p][q]
    bucket[p][q]<-bucket[p][q-1]
    bucket[p][q-1]<-buff
 int t<-1
 for r<-9 to 0
    for s<-1 to n
 if(bucket[r][s]!=0)
 do A[t]<-bucket[r][s];
    bucket[r][s]<-0;
    t<-t+1;

Compile:g++ H34026246_HW4.cpp
Code by 陳柏彤 ID:H34026246
Date 2014.12.14
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
void duplicate_array(int A[],int B[],int n);         //複製矩陣的函數
void CS(int A[],int n,int k);                        //counting sort函數
void RS(int A[],int n,int k);                        //radix sort函數
void BS(int A[],int n,int k);                       //bucket sort函數
int is_A_desc(int A[],int n);                       //檢查是否有由大排到小的函數 有排序回傳1 沒排好序回傳0

int main()
{
srand(time(NULL));                            //以時間作為種子碼

int a,b,n,k;                                 //宣告三個整數 a=數字下限 b＝數字上限 n＝個數 k＝陣列中最大的數

cout<<"Please input [a, b, n]:";
cin>>a>>b>>n;                                //輸入a,b,n

int A[n+1],B[n+1];                           //宣告兩個陣列Ａ,B 編號都是0~n

    for(int x=1;x<=n;x++)                  //在Ａ陣列中編號1~n格填入隨機的亂數
    A[x]=a+(rand()%(b-a+1));

    k=A[1];                                //讓k=A[1]
    for(int x=1;x<=n;x++)
    {
        if(A[x]>k)                         //假如陣列中有某格的值大於k
            k=A[x];                       //讓k的值變成它
    }

   
    cout<<"Source:";                    //印出未排序的數列
    for(int x=1;x<=n;x++)
        cout<<A[x]<<" ";
    cout<<endl;
    
    duplicate_array(A,B,n);                 //將A陣列的值複製給B陣列
    CS(A,n,k);                                //counting sort
    if(is_A_desc(A,n)==0)                       //檢查是否有由大到小排序
    {
        cout << "Warning!!Failed!";           //若沒有由大到小排序 則顯示錯誤
        return 0;
    }
    cout<<"By counting sort:";               //印出排序後數列
    for(int x=1;x<=n;x++)
        cout<<A[x]<<" ";
    cout<<endl;
    
    
    duplicate_array(B,A,n);                      //將B陣列的值複製到A陣列
    RS(A,n,k);                                    //radix sort
    if(is_A_desc(A,n)==0)                           //檢查是否有由大到小排序
    {
        cout << "Warning!!Failed!";                 //若沒有由大到小排序 則顯示錯誤
        return 0;
    }
    cout<<"By radix sort:";                        //印出排序後數列
    for(int x=1;x<=n;x++)
        cout<<A[x]<<" ";
    cout<<endl;
    
    
    k=A[1];                                         //找出陣列中數字最大的值 讓k等於它
    for(int x=1;x<=n;x++)
    {
        if(A[x]>k)
            k=A[x];
    }
    
    
    duplicate_array(B,A,n);                         //將B陣列的值複製到A陣列
    BS(A,n,k);                                       //bucket sort
    if(is_A_desc(A,n)==0)                           //檢查是否有由大到小排序
    {
        cout << "Warning!!Failed!";                 //若沒有由大到小排序 則顯示錯誤
        return 0;
    }
    cout<<"By bucket sort:";                        //印出排序後數列
    for(int x=1;x<=n;x++)
        cout<<A[x]<<" ";
    cout<<endl;
    
    return 0;
}


void duplicate_array(int A[],int B[],int n)        //將A矩陣的值複製到B矩陣
{
 for(int x=1;x<=n;x++)
 B[x]=A[x];	
}


void CS(int A[],int n,int k)                        //counting sort
{
    int C[n+1],D[k+1];                             //宣告兩個陣列C編號由0~n D編號由0~`最大數字
    
    for (int x=1;x<=k;x++)                          //將陣列D每個值初始為0
        D[x]=0;
    for(int x=1;x<=n;x++)                         //用陣列D記錄A陣列中各個數字出現次數
        D[A[x]]= D[A[x]]+1;
    for(int x=k;x>1;x--)                         //讓次數累計
        D[x-1]=D[x-1]+D[x];
    for(int x=1;x<=n;x++)                        //依照該數字累計的次數 決定他在C陣列的位置
    {
        C[D[A[x]]]=A[x];
        D[A[x]]=D[A[x]]-1;
    }
    for(int x=1;x<=n;x++)                        //將C陣列中的值複製回A陣列
        A[x]=C[x];
    
}


void RS (int A[],int n,int k)                  //radix sort
{
    int digit = 1 ;                            //宣告整數digit用來計算數字位數
    while (k>0)
    {
        k = k/10 ;                           //如果k除以10之後大於0
        if (k>0)
            digit++;                             //位數＋1
    }
    for ( int x=1;x<=digit;x++)           //最大數字有幾位數就跑幾次for x=1比較第一位數 x=2比較第二位數....
    {
        int num=pow(10,x);                 //宣告num他的值為10^x次方
        int key[n+1];                      //宣告key陣列用來儲存該數字某位數的值
        for (int y=1;y<=n;y++)             //將數字某位數的值存入key陣列
        {
            key[y] = A[y]% num ;
            key[y] = key[y]*10 /num ;
        }
        for ( int z=1;z<=n;z++)            //key陣列由大排到小
            for ( int j=z;j>0;j--)
            {
                int buff;
                if (key[j]>key[j-1])      //如果後者大於前者
                {
                    buff=A[j-1];          //將key陣列的值以及相對應的A陣列的值互換
                    A[j-1]=A[j];
                    A[j]=buff;
                    buff=key[j-1];
                    key[j-1]=key[j];
                    key[j]=buff;
                }
            }
    }
}


void BS(int A[],int n,int k)             //bucket sort
{
    int bucket[10][n+1];                //宣告bucket陣列 bucket[該位數的數值(0~9)][這個行的第幾個數(0~n)]
    int digit=1;                        //宣告整數digit用來計算數字位數
    while (k>0)
    {
        k=k/10 ;                        //如果k除以10之後大於0
        if (k>0)
        digit++;                        //位數+1
    }
    
    for(int x=0;x<10;x++)              //將bucket陣列中每個值初始為0
        for(int y=0;y<n+1;y++)
            bucket[x][y]=0;
    
    
    for (int x=1;x<=digit;x++)         //最大數字有幾位數就跑幾次for x=1比較第一位數 x=2比較第二位數....
    {
        int num=pow(10,x);             //宣告num他的值為10^x次方
        for(int y=1;y<n+1;y++)         //從A[1]~A[n]  把值丟入相對應的bucket  ex:比較個位數A[1]=51就丟入bucket[1][1]
        {                               //A[2]=23 就丟入bucket[3][1]
            for(int z=1;z<n+1;z++)
            {
                int r=(A[y]%num)*10/num;  //宣告整數r 其值等於該數字某位數的值
                if(bucket[r][z]==0)      //如果bucket陣列中該格數值=0
                {
                    bucket[r][z]=A[y];    //讓該格的值等於A[y]
                    break;
                }
            }
        }
        
        for(int p=9;p>=0;p--)            //將每個行的數字由大排到小
        {
            for (int j=1;j<=n;j++)
            {
                for (int q=j;q>1;q--)
                {
                    int buff;
                    if (bucket[p][q]>bucket[p][q-1])
                    {
                        buff=bucket[p][q];
                        bucket[p][q]=bucket[p][q-1];
                        bucket[p][q-1]=buff;
                    }
                }
            }
        }
        
        
        int t=1;
        for(int r=9;r>=0;r--)              //從第9行將數字一個一個填回A陣列
        {
            for(int s=1;s<n+1;s++)
            {
                if(bucket[r][s]!=0)
                {
                    A[t]=bucket[r][s];
                    bucket[r][s]=0;
                    t+=1;
                }
            }
        }
        
    }
}



int is_A_desc(int A[],int n)            //檢查是否有由大排到小的函數
{
    for(int x=n;x>1;x--)                //將A陣列中每個值 兩兩比較大小
    {
        if(A[x]>A[x-1])                 //如果後者大於前者
            return 0;                   //回傳0
    }
    return 1;                          //都有由大排到小則回傳1
}
