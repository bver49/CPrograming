//This code can be compiled and run ok.
//usage:To input more than four integers then ouput the min number, second min number, max number, second max number, sum and product.
//input file:none
//output files:none
//compile:g++ H34026246_HW1.cpp

// pseudocode: 
// cin>>a
//cin>>integers 
//sort(*array,a)
//---------------
//if(array[y]>array[y+1])
//then array[y]=buffer
//     array[y+1]=array[y]
//     buffer=arrat[y+1]
//--------------------
//  for x=o to a-1
//  sum+=array[x]
//  product*=array[x] 
//cout<<min<<2ndmin<<max<<2ndmax<<sum<<product
 
#include <iostream>
using namespace std;
int sort(int *array,int a );
int main()
{
	int a=0,sum=0,product=1;          //a=俱计计秖  

 	cout<<"Please input a positive integer n larger than 4:";
	cin>>a;                      
	   while(a<4)                         //狦a<4 玥斗穝块 
	   {
	    cout<<"!!Warning!! "<<a<<" is NOT larger than 4!"<<endl<<"Please input the amount of integers(big than 4):";
	    cin>>a;	
	   }
	   
	   int *array;                                  //笆篈皚 
       array=new int[a];
       
	   cout<<"Please enter "<<a<<" integers: ";            
	   for(int x=0;x<a;x++)                        //块a俱计 秈皚 
	   cin>>array[x];	 
	   cout<<"The number you enter are: ";         //块计 
	   for(int x=0;x<a;x++)
	   cout<<array[x]<<" ";
	  
	   for(int x=0;x<a;x++)                    //璸衡计羆㎝ 
	   sum+=array[x];
	     
	   for(int x=0;x<a;x++)                    //璸衡┮Τ计縩 
	   product*=array[x];
	   
	   sort(array,a);                         //盢计パ逼 
	   
	   cout<<endl<<"The integer after sort:";      //逼计 
	   for(int x=0;x<a;x++)
	   cout<<array[x]<<" ";
	   
	   cout<<endl<<"Min="<<array[0]<<endl<<"2nd Min="<<array[1]<<endl<<"Max="<<array[a-1]<<endl<<"2nd Max="<<array[a-2]<<endl<<"Sum="<<sum<<endl<<"Product="<<product;
	 delete [] array;   //睦癘拘砰 
}


int sort(int *array,int a)
{
	
	for(int z=0;z<a;z++)          
	for(int y=0;y<a;y++)             //Τa计 碞禲a筂 
	{ 
	if(array[y]!=array[a-1])       //讽ぃ琌程计 
	if (array[y]>array[y+1])      //玡计ゑ计 玥ㄢ计竚が传 
	{
		int buffer=array[y+1];
		array[y+1]=array[y];
		array[y]=buffer;
	}
	}
}


//coded by 朝琭 ID:H34026246 
//  date: 2014.09.27

