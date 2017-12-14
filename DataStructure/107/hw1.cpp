#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using namespace std;

int main(){

	string name[60]={
		"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30",
		"31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59","60"
	};

	string choice[30];
	
	srand(time(NULL));
	
	for(int x=0 ; x<30 ; x++){
		int i=rand()%60;
		while(name[i]==" "){
			i=rand()%60;
	 	}

	 	choice[x]=name[i];
	 	name[i]=" ";
	}

	for(int x=0 ; x<30 ; x++)
	cout<<"第"<<setw(2)<<x<<"位 :"<<setw(3)<<choice[x]<<endl;

}