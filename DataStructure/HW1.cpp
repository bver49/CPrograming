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
	int a=0,sum=0,product=1;          //a=��Ƽƶq  

 	cout<<"Please input a positive integer n larger than 4:";
	cin>>a;                      
	   while(a<4)                         //�p�Ga<4 �h�����s��J 
	   {
	    cout<<"!!Warning!! "<<a<<" is NOT larger than 4!"<<endl<<"Please input the amount of integers(big than 4):";
	    cin>>a;	
	   }
	   
	   int *array;                                  //�ʺA�ŧi�}�C 
       array=new int[a];
       
	   cout<<"Please enter "<<a<<" integers: ";            
	   for(int x=0;x<a;x++)                        //��Ja�Ӿ�� �æs�i�}�C 
	   cin>>array[x];	 
	   cout<<"The number you enter are: ";         //�L�X��J���Ʀr 
	   for(int x=0;x<a;x++)
	   cout<<array[x]<<" ";
	  
	   for(int x=0;x<a;x++)                    //�p��Ʀr�`�M 
	   sum+=array[x];
	     
	   for(int x=0;x<a;x++)                    //�p��Ҧ��Ʀr���n 
	   product*=array[x];
	   
	   sort(array,a);                         //�N�Ʀr�Ѥp�ƨ�j 
	   
	   cout<<endl<<"The integer after sort:";      //�L�X�Ƨǫ�ƦC 
	   for(int x=0;x<a;x++)
	   cout<<array[x]<<" ";
	   
	   cout<<endl<<"Min="<<array[0]<<endl<<"2nd Min="<<array[1]<<endl<<"Max="<<array[a-1]<<endl<<"2nd Max="<<array[a-2]<<endl<<"Sum="<<sum<<endl<<"Product="<<product;
	 delete [] array;   //����O���� 
}


int sort(int *array,int a)
{
	
	for(int z=0;z<a;z++)          
	for(int y=0;y<a;y++)             //��a�Ӽ� �N�]a�M 
	{ 
	if(array[y]!=array[a-1])       //���O�̫�@�Ӽƪ��ɭ� 
	if (array[y]>array[y+1])      //�e�@�ӼƤ�U�@�ӼƤj �h��ӼƦr��m���� 
	{
		int buffer=array[y+1];
		array[y+1]=array[y];
		array[y]=buffer;
	}
	}
}


//coded by ���f�� ID:H34026246 
//  date: 2014.09.27

