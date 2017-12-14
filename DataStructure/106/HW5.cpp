/*
This code can be compiled and run ok.
Usage:let user enter a_min=lower bound a_max=upper bound n=how many numbers,and rs=randomseed.Sort this n number
by all 7 sorts,and print out the time of 7 sorts.

Input file:none
Output files:none

Psuedocode:
t1=mytimer
IS(A,n)
t2=mytimer
t_is=t2-t1

t1=mytimer
MS(A,1,n)
t2=mytimer
t_ms=t2-t1

t1=mytimer
CS(A,n,k)
t2=mytimer
t_cs=t2-t1

t1=mytimer
BS(A,n,k)
t2=mytimer
t_bs=t2-t1

t1=mytimer
RS(A,n,k)
t2=mytimer
t_rs=t2-t1

t1=mytimer
QS(A,1,n)
t2=mytimer
t_qs=t2-t1

t1=mytimer
HS(A,n)
t2=mytimer
t_hs=t2-t1

Compile:g++ H34026246_HW5.cpp
Code by 陳柏彤 ID:H34026246
Date 2015.01.10

*/
#include <iostream>
#include <cmath>
#include <sys/types.h>
#include <sys/times.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
void QS(int A[],int l,int n);
void CS(int A[],int n,int k);                        
void RS(int A[],int n,int k);                     
void BS(int A[],int n,int k);  
void IS(int A[],int n);
void MS(int A[],int l,int n);
void HS(int A[],int n);
void build_max_heap(int A[],int n);
void Maxheapify(int A[],int i,int n);
void merge(int A[],int l,int mid,int n);
int partition(int A[],int p,int r);
void duplicate(int A[],int B[],int n);
float mytimer();
void printout_array(int A[],int n);
int is_A_desc(int A[],int n); 
int main(int argc, char* argv[])
{
                    
	int a_min,a_max,n,k,max,rs,is_p;            //a_max=數字範圍上限 a_min＝數字範圍下限 n＝多少個數字 k＝max＝隨機出來的數字中的最大值 
                                                    //rs＝種子碼 is_p如果=1則印出隨機出來的數字 如果不等於1則輸出sorting時間
                
    if(argv[1]==0||argv[2]==0||argv[3]==0||argv[4]==0||argv[5]==0)      //如果command line沒有輸入參數    
	{
    cout<<"Please input[is_p,n,a_min,a_max,rs]:"<<endl;
    cin>>is_p>>n>>a_min>>a_max>>rs;                                    //讓使用者自己輸入參數
    }
	else                                                   //如果command line有參數 則使用command line的參數
    {
    is_p=atoi(argv[1]);
    n=atoi(argv[2]);
    a_min=atoi(argv[3]);
    a_max=atoi(argv[4]);
    rs=atoi(argv[5]);
    }
    int *A = new int [n+1];                                       // A,B: dynamic arrays
    int *B = new int [n+1];                              
    float t1=0.,t2=0.,t_is,t_ms,t_hs,t_qs,t_cs,t_rs,t_bs; //記錄時間的變數
    srand(rs);                                            
    for(int x=1;x<=n;x++)                           //將n個範圍由a_min~a_max的參數填入A陣列
    A[x]=a_min+(rand()%(a_max - a_min+1));   

    duplicate(A,B,n);                           //將A陣列複製給B陣列
    
    k=A[1];                                     //找出陣列中數字最大值
    for(int x=1;x<=n;x++)
        if(A[x]>k)                         
            k=A[x]; 
    max=k;                                      //讓max值=k        

    if(is_p==1)                                 //如果is_p=1 則輸出A陣列
    printout_array(A,n);

    else                                   //如果is_p不等於1 則開始sorting並記錄時間
    {    
    t1=mytimer();                         //記錄開始時間
    IS(A,n);                              //insertion sort
    t2=mytimer();                         //記錄結束時間
    if(is_A_desc(A,n)==0)                  //檢查是否有排序
    cout<<"IS Wrong!!"<<endl; 
    t_is=(t2-t1);                         //經過時間＝結束時間-開始時間
    
    t2=t1=0;                               //重置t2,t1
    duplicate(B,A,n);                       //將B陣列複製給A陣列
    t1=mytimer();                           //記錄開始時間
    MS(A,1,n);                              //merge sort
    t2=mytimer();                            //記錄結束時間
    if(is_A_desc(A,n)==0)                      //檢查是否有排序
    cout<<"MS Wrong!!"<<endl;
    t_ms=t2-t1;                                  //經過時間＝結束時間-開始時間

    t2=t1=0;                                    //重置t2,t1
    duplicate(B,A,n);                           //將B陣列複製給A陣列
    t1=mytimer();                               //記錄開始時間
    CS(A,n,k);                                  //counting sort
    t2=mytimer();                                //記錄結束時間
    if(is_A_desc(A,n)==0)                          //檢查是否有排序
    cout<<"CS Wrong!!"<<endl;    
    t_cs=t2-t1;                                     //經過時間＝結束時間-開始時間

    t2=t1=0;                                          //重置t2,t1
    duplicate(B,A,n);                                //將B陣列複製給A陣列
    t1=mytimer();                                   //記錄開始時間
    BS(A,n,k);                                      //bucket sort
    t2=mytimer();                                    //記錄結束時間
    if(is_A_desc(A,n)==0)                           //檢查是否有排序
    cout<<"BS Wrong!!"<<endl;
    k=max;                                           //因為k值有變動過 重新將max值指定給k
    t_bs=t2-t1;                                     //經過時間＝結束時間-開始時間

    t2=t1=0;                                               //重置t2,t1
    duplicate(B,A,n);                                    //將B陣列複製給A陣列
    t1=mytimer();                                      //記錄開始時間
    RS(A,n,k);                                          //radix sort
    t2=mytimer();                                        //記錄結束時間
    if(is_A_desc(A,n)==0)                               //檢查是否有排序
    cout<<"RS Wrong!!"<<endl; 
    t_rs=t2-t1;                                          //經過時間＝結束時間-開始時間

    t2=t1=0;                                                //重置t2,t1
    duplicate(B,A,n);                                        //將B陣列複製給A陣列
    t1=mytimer();                                          //記錄開始時間
    QS(A,1,n);                                              //quick sort
    t2=mytimer();                                            //記錄結束時間
    if(is_A_desc(A,n)==0)                                     //檢查是否有排序
    cout<<"QS Wrong!!"<<endl;
    t_qs=t2-t1;                                             //經過時間＝結束時間-開始時間

    t2=t1=0;                                                   //重置t2,t1
    duplicate(B,A,n);                                         //將B陣列複製給A陣列
    t1=mytimer();                                           //記錄開始時間
    HS(A,n);                                                    //heap sort
    t2=mytimer();                                              //記錄結束時間
    if(is_A_desc(A,n)==0)                                      //檢查是否有排序
    cout<<"HS Wrong!!"<<endl;    
    t_hs=t2-t1;                                             //經過時間＝結束時間-開始時間

    cout<<"n="<<n<<" a_min="<<a_min<<" a_max="<<a_max<<" rs="<<rs<<endl;
    cout<<"Time of insertion sort: "<<t_is<<endl;      //輸出各個sort的時間
    cout<<"Time of merge sort: "<<t_ms<<endl;
    cout<<"Time of counting sort: "<<t_cs<<endl;
    cout<<"Time of bucket sort: "<<t_bs<<endl;
    cout<<"Time of radix sort: "<<t_rs<<endl;
    cout<<"Time of quick sort: "<<t_qs<<endl;
    cout<<"Time of heap sort: "<<t_hs<<endl;
    delete [] A ;                                               // free all the memories and end the program
    delete [] B ;
    }
    return 0;
                 
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
        if(k>0)
        digit++;                             //位數＋1
    }
    for ( int x=1;x<=digit;x++)           //最大數字有幾位數就跑幾次for x=1比較第一位數 x=2比較第二位數....
    {
        int num=pow(10,x);                 //宣告num的值為10^x次方
        int key[n+1];                      //宣告key陣列用來儲存該數字某位數的值
        for (int y=1;y<=n;y++)             //將數字某位數的值存入key陣列
        {
            key[y]=(A[y]%num)*10/num;
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
void BS ( int A[] , int n , int k ) 
{        
    int temp;        
    for(int x=0;x<n;x++)
    A[x]=A[x+1];
                    
    int B[10][n] ;
    for ( int x= 0 ;x< 10 ;x++ )
        for ( int y= 0 ; y< n ;y++ )
            B[x][y] = 0 ;
        
    for ( int s = 0 ; s < n ; s++ ) 
    {
        int key = 10*A[s]/(k+1) ;
        for ( int t = 0 ; ; t++ )
            if ( B[key][t] == 0 ) {
                B[key][t] = A[s] ;
                break ;
            }
    }
    for ( int x= 0 ; x< 10 ; x++ ) 
    {
        int depth = 0 , y= 0 ;
        while ( B[x][y] != 0 ) 
        {
            depth ++ ;
            y++ ;
        }
        for ( int t = 0 ; t < depth ; t++ ) 
        {
            for ( int s = t ; s > 0 ; s-- ) 
            {
                if ( B[x][s] > B[x][s-1] ) 
                {
                    temp = B[x][s-1] ;
                    B[x][s-1] = B[x][s] ;
                    B[x][s] = temp ;
                }
            }
        }
    }
    int s =1;
    for ( int i = 9 ; i >= 0 ; i-- )
        for ( int j = 0 ; j < n ; j++ ) 
        {
            if ( B[i][j] == 0 )     
                break ;
            else 
            {
                A[s] = B[i][j] ;
                s ++ ;
            }
        }
  
}

void IS(int A[],int n) 
{                                       
    for ( int x=1 ; x<=n ;x++ )
        for ( int y=x;y>1;y--) 
        {
            int key ;
            if ( A[y] > A[y-1] )   //當A[y-1]<A[y]
            {
                key = A[y-1] ;      //將A[y]左移到A[y-1] 
                A[y-1] = A[y] ;
                A[y] = key ;
            }
        }
}

void MS(int A[],int l,int n)
{   
    if (n>l)                              //如果數列還可以再拆開
    {
     int mid=(n+l)/2;                      //mid=(最左+最右)/2
     MS(A,l,mid);                          //將數據分成左右兩邊 中間點為mid 
     MS(A,mid+1,n);
     merge(A,l,mid,n);
    }

}


void merge( int A[], int l, int mid, int n )
{
    int x[n], i=l,j=mid+1;

    for(int k=0;k<=n-l;k++) 
    {
     if(i==mid+1)                     //如果左半邊數據已填完 就在X[k]填入右半邊數據
     x[k]=A[j++];
     else if(j==n+1)                 //如果右半邊數據已填完 就在X[k]填入左半邊數據
     x[k]=A[i++];
     else if(A[i]<A[j])                //如果左半邊數據<右半邊數據 就在X[k]填入右半邊數據 
     x[k]=A[j++];
     else                              //如果右半邊數據<左半邊數據 就在X[k]填入左半邊數據
     x[k]=A[i++];  
}

    for(i=0,j=l;j<=n;i++,j++)           //將矩陣x資料指定給A陣列
    A[j]=x[i];
}




void QS(int A[],int l,int n)
{
 	int q;
 	if(l<n)
 	{ 
  		q=partition(A,l,n);
  		QS(A,l,q-1);
  		QS(A,q+1,n);
	}

}

int partition(int A[],int l,int n)
{
	int x,i;
	int temp;
	x=A[n];
	i=l-1;
	for(int j=l;j<n;j++)
	{
		if (A[j]>=x)
		{	i=i+1;
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}

	temp=A[i+1];
	A[i+1]=A[n];
	A[n]=temp;

	return i+1;	
}
void duplicate(int A[],int B[],int n)           //將A陣列的值複製給B陣列
{
    for(int x=1;x<=n;x++)
    B[x]=A[x];  
}

float mytimer()                               //計時函數 計算的是cpu time
{ 
    struct tms hold;
    times(&hold);
    return  (float)(hold.tms_utime);
}

void printout_array(int A[],int n)          //將陣列印出來的函數
{
    for(int x=1;x<=n;x++)
    cout<<A[x]<<" ";
    cout<<endl;
}

int is_A_desc(int A[],int n)                 //檢查是否有由大排到小的函數
{
    for(int x=n;x>1;x--)                      //將A陣列中每個值 兩兩比較大小
    {
        if(A[x]>A[x-1])                         //如果後者大於前者  
            return 0;                           //回傳0
    }
    return 1;                                   //如果都有由大排到小回傳1
}

void HS(int A[],int n)
{
    int temp;
    build_max_heap(A,n);
    for(int i=n;i>=2;i--)
    {
        temp=A[1];
        A[1]=A[i];
        A[i]=temp;
        Maxheapify(A,1,i-1);
    }

}
void build_max_heap(int A[],int n)
{
  for(int i=n/2;i>=1;i--)
    Maxheapify(A,i,n);
}

void Maxheapify(int A[],int i,int n)
{
    int l,r,largest,temp;
    l=2*i;
    r=2*i+1;
    if(l<=n && A[l]<A[i])
    largest=l;
    else
    largest=i;
    if(r<=n && A[r]<A[largest])
    largest=r;
    if (largest!=i)
    {
        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;    
        Maxheapify(A,largest,n);
    }

}

