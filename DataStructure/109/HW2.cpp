#include <cstring>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct node{
	string name;
	struct node* next;
	struct node* pre;
};

void showAll(node*,int);
node* pass(node*,int);

int main(){
	srand(time(NULL));
	string students[8] = {"A","B","C","D","E","F","G","H"};
	string out[7];
	node *student= new node;
	node *start = student;

  int nextStep = 0;
  int explosionRate = 0; //爆炸機率
	int rounds =1;    //回合數
	int studentAmt = 8; //學生人數

  //將每個node串成linlist
	for(int i = 0; i<8 ; i++){
		if(i==7){
			student -> next = start;
		}else{
			student -> next = new node;
		}
		student -> next -> pre = student;
		student -> name = students[i];
		student = student -> next;
	}

	cout<<"炸死倒霉鬼遊戲開始..."<<endl;
	while(studentAmt!=1){
		cout<<"目前玩家順序:";
		showAll(student,studentAmt); //印出現在的linklist
		cout<<"第"<<rounds<<"回合,由"<<student->name<<"開始"<<endl;
		nextStep = rand()%5;   //傳遞的人數，範圍0-5
		student = pass(student,nextStep);   //傳遞炸彈
		explosionRate = (rand()%100)+1;   //取1-100之間的亂數
		if(explosionRate<=30){
			cout<<"炸彈爆炸"<<start->name<<"出局,還剩"<<studentAmt<<"位玩家"<<endl;
			studentAmt-- ;       //學生數目減去1
			out[studentAmt-1] = student->name;    //記錄淘汰順序
			student -> next -> pre = student -> pre;     //從linklist移除現有的node
			student -> pre -> next = student -> next;
			student = student -> next;      //由下一位學生開始回合
		}else{
			cout<<"炸彈沒有爆炸,還剩"<<studentAmt<<"位玩家"<<endl;
		}
		rounds++;
	}
	cout<<endl<<"淘汰順序：";
	//印出淘汰順序
	for(int i=6;i>=0;i--){
		cout<<out[i];
		if(i!=0) cout<<"->";
	}
	//印出僅剩的學生名字
	cout<<endl<<student->name<<"獲勝"<<endl;
}

//印出現在在linklist中的所有學生名字
void showAll(node *student,int studentAmt){
	for(int i = 0;i<=studentAmt;i++){
		cout<<student->name;
		if(i!=studentAmt) cout<<"->";
		student = student->next;
	}
	cout<<endl<<endl;
}

//傳遞炸彈
node* pass(node *student,int step){
	int rate = (rand()%100)+1;  //取1-100之間的亂數
	if(rate<=50){          //小於50逆時針傳
		for(int i = 0;i<step;i++){
			student = student->pre;
		}
		cout<<"炸彈往上傳給第"<<step<<"位同學"<<student->name<<endl;
	}else{               //大於50順時針傳
		for(int i = 0;i<step;i++){
			student = student->next;
		}
		cout<<"炸彈往下傳給第"<<step<<"位同學"<<student->name<<endl;
	}
	return student;
}
