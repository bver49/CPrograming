#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;


struct node{
	string name;
	float msrate[5];
	struct node* next;
	struct node* pre;
};


int main(){
	srand(time(NULL));
	string in;
	string customer[5] = {"A","B","C","D","E"};
	string correct[5] = {"工","資","披","薩","讚"};
	string data[6][6];
	float rate[5][5];

	node *A;
	A = new node;
	A -> next = NULL;
	A -> name = "";
	node *start = A;

	ifstream file("mistakeRate.txt");
	int x =0, y = 0;
	while(!file.eof()){
		file >> in;
		data[x][y]=in;
		x++;
		if(x>5){
			x=0;
			y++;
		}
	}
	for(int i=1;i<6;i++){
		for(int j=1;j<6;j++){
			rate[j-1][i-1]=stof(data[j][i]);
		}
	}
	for(int i=0;i<5;i++){
		if(i!=4){
			A->name = customer[i];
			node *temp;
			temp = new node;
			temp -> next = NULL;
			temp -> name ="";
			A -> next = temp;
			A ->next -> pre = A;
			A = A->next ;
		}
		else{
			A->name = customer[i];
			A -> next = start;
			A ->next -> pre = A;
		}
	}

	int c = 0;
	node *tmp = start;
	while(tmp!=NULL){
		for(int i=0;i<5;i++){
			tmp -> msrate[i] = rate[i][c];
		}
		tmp = tmp->next;
		c++;
		if(c>4){
			break;
		}
	}

	int index = 0;
	int number = 5;
	int rounds=1;
	int re=0;
	int turns=0;
	string out[4];
	tmp = start;
	cout<<"第1輪"<<endl;
	cout<<"--------------"<<endl;
	while(tmp!=NULL){
		cout<<tmp->name<<" ";
		int r = (rand()%100)+1;
		if(r < ( tmp -> msrate[index] * 100 )){
			cout<<"  "<<correct[index]<<"  F  "<<endl;
			cout<<"--------------"<<endl;
			cout<<tmp->name<<" 出局"<<endl<<endl;
			out[5-number]=tmp->name;
			tmp -> pre -> next = tmp ->next;
			tmp -> next -> pre = tmp -> pre;
			tmp = tmp -> next;
			number--;
			rounds++;
			re=0;
			turns=0;
			if(number==1){
				break;
			}
			cout<<"第"<<rounds<<"輪"<<endl;
			cout<<"--------------"<<endl;
			index=0;
		}
		else{
			cout<<"  "<<correct[index]<<"  T  "<<endl;
			index++;
			tmp = tmp ->next;
			if(index == 5 && re==0){
				cout<<"--------------"<<endl;
				index=0;
				turns++;
				re=turns;
			}
			else if(index == 5 && re > 0 ){
				index=4;
				re--;
			}
		}
	}
	cout<<"贏家: "<<tmp->name<<endl<<"出局順序: ";
	for(int k=0;k<4;k++){
		cout<<out[k]<<" ";
	}
	cout<<endl;
}
