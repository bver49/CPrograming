//This code can be compiled and run ok.
//usage:read a natual number n, an integral lower bound a_min, an integral upper bound a_max, and a random seed rseed
//pirntout a sequence of n random integer numbers with random seed rseed,sort the numbers by insertion sort and merge sort in
//descending order than print out hte numbers after sorted.
//input file:none
//output files:none
//compile:g++ H34026246_HW2.cpp
//pseudocode:	 
// ins_sort(A,n)
// for x<-1 to length(A)
//for y=x  y>1 y--
//if A[y]>A[y-1] 
// do key<-A[y-1]
//do A[y-1]=A[y]
// A[y]<-key
//mg_sort(B,m,n,l)
//if l<r
//then mid=(n+l)/2
//mg_sort(B,1,mid,l)
//mg_sort(B,1,n,mid+1)
//merge(B,l,mid,n)
// i<-l j<-mid+1
//creat array x[1...n]
//for k=1 to n-l
//if(i==mid+1)
//x[k]<-B[j++]
//if(j==n+1) 
//x[k]<-B[i++]
//if(B[i]<B[j])
//x[k]<-B[j++]
//else x[k]<-B[i++]
//for i=0  j=l to n
//B[j]=x[i]
//coded by ≥Ø¨fßÕ ID:H34026246 
//date: 2014.10.27

#include <iostream>
#include <cstdlib>
using namespace std;
void duplicate_array(int *A,int *B,int m,int n);
void printout_arrary(int *A,int m,int n);
void ins_sort(int *A,int n);
void mg_sort(int *B,int m,int n,int l);
void merge(int *B,int l,int mid,int n);
int main()
{
  	int rseed,n,a_min,a_max;                              //rseed=∫ÿ§lΩX n=º∆¶r≠”º∆ a_min=∂√º∆≥Ã§p≠» a_max=∂√º∆≥Ã§j≠» 
 
 	cout<<"Please input [n, a_min, a_max, rseed]:";
 	cin>>n>>a_min>>a_max>>rseed;                   
 	int *A;                                             //´ÿ•ﬂ∞ ∫A§@∫˚∞}¶CA[n] 
 	A=new int[n];         
 	int *B;                                             //´ÿ•ﬂ∞ ∫A§@∫˚∞}¶CB[n]
 	B=new int[n];

 	srand(rseed);                                       //®œ•Œ®œ•Œ™ÃøÈ§J™∫∫ÿ§lΩX 
	  
 	for(int x=1;x<=n;x++)                              //±NA∂Ò§J≥Ã§pa_min≥Ã§j®Ïa_max™∫∂√º∆ 
 	A[x]=rand()%(a_max-a_min+1);

 	duplicate_array(A,B,1,n);                        //±NØx∞}A™∫∏ÍÆ∆Ω∆ªs®ÏØx∞}B 
 	cout<<"Numbers are:"<<endl;
	 printout_arrary(A,1,n);
 	cout<<endl;
 	
 	ins_sort(A,n);                                  //∏gπLinsertion sort 
     mg_sort(B,1,n,1);                                //∏gπLmerge sort 
 	
 	cout<<"By insertion sort:"<<endl;  
 	printout_arrary(A,1,n);                        //¶L•X±∆ß«´·™∫º∆¶C 
 	cout<<endl;
 	cout<<"By merge sort:"<<endl;
 	printout_arrary(B,1,n);
 	
}
 
void duplicate_array(int *A,int *B,int m,int n)
{
	for(int x=1;x<=n;x++)
	B[x]=A[x];	
}

void printout_arrary(int *A,int m,int n)
{
	for(int x=1;x<=n;x++)
	cout<<A[x]<<" ";
}


void ins_sort ( int *A,int n) 
{										
	for ( int x=1 ; x<=n ;x++ )
		for ( int y=x;y>1;y--) 
		{
			int key ;
			if ( A[y] > A[y-1] )   //∑ÌA[y-1]<A[y] 
			{
				key = A[y-1] ;     //±NA[y]•™≤æ®ÏA[y-1] 
				A[y-1] = A[y] ;
				A[y] = key ;
			}
		}
}

void mg_sort(int *B,int m,int n,int l)
{   
	if (n>l)                                //¶p™Gº∆¶C¡Ÿ•i•H¶A©Ó∂} 
	{
	 int mid=(n+l)/2;                      //mid=(≥Ã•™+≥Ã•k)/2 
	 mg_sort(B,1,mid,l);                  //±Nº∆æ⁄§¿¶®•™•k®‚√‰ §§∂°¬I¨∞mid 
	 mg_sort(B,1,n,mid+1);
	 merge(B,l,mid,n);
	}

}


void merge( int *B, int l, int mid, int n )
{
	int x[n], i=l,j=mid+1;

	for(int k=0;k<=n-l;k++) 
	{
	 if(i==mid+1)                     //¶p™G•™•b√‰º∆æ⁄§w∂Òßπ ¥N¶bX[k]∂Ò§J•k•b√‰º∆æ⁄ 
     x[k]=B[j++];
     else if(j==n+1)                 //¶p™G•k•b√‰º∆æ⁄§w∂Òßπ ¥N¶bX[k]∂Ò§J•™•b√‰º∆æ⁄ 
     x[k]=B[i++];
     else if(B[i]<B[j])             //¶p™G•™•b√‰º∆æ⁄<•k•b√‰º∆æ⁄ ¥N¶bX[k]∂Ò§J•k•b√‰º∆æ⁄ 
     x[k]=B[j++];
     else                           //¶p™G•k•b√‰º∆æ⁄<•™•b√‰º∆æ⁄ ¥N¶bX[k]∂Ò§J•™•b√‰º∆æ⁄  
     x[k]=B[i++];  
}

    for(i=0,j=l;j<=n;i++,j++)
    B[j]=x[i];                     //±NØx∞}x∏ÍÆ∆´¸©wµπBØx∞} 
}


