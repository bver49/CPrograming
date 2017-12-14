#include <fstream> 
#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

struct node{
	string name;                     
	int birth;
	struct node* right;      
  struct node* left;
};

void printTree(node* temp, int indent);
void search(node* temp);

int main(){
	node *root;                                         
	root = new node;                                        
	root->right = NULL; 
	root->left = NULL;
	node *temp = root;    
	
  ifstream file("hw3_BirthDate.txt");      //讀檔案
	int start = 0; 
	int input;        
	int birth;
	string name;
	while (file >> name >> birth){         //讀入資料
		temp = root;
		if(start==0){ 	 										//新增root節點
			temp->name = name;
			temp->birth = birth;
			start = 1;
		}else{														//插入子節點
			while(true){
				if(birth>temp->birth){         //如果讀入的資料的出生日期比目前節點大，則向右找插入新結點的位置
					if(temp->right==NULL){       //如果右邊沒有子節點
						temp->right = new node;    //插入新節點
						temp = temp->right;
						break;
					}
					temp = temp->right;         //如果右邊已經有節點了則繼續往下一層走，繼續找可以插入新節點的位置
				}else{                        //如果讀入的資料的出生日期比目前節點小，則向左找插入新結點的位置
					if(temp->left==NULL){       //如果左邊沒有子節點
						temp->left = new node;    //插入新節點
						temp = temp->left;
						break;
					}
					temp = temp->left;          //如果左邊已經有節點了則繼續往下一層走，繼續找可以插入新節點的位置
				}
			}
			temp->name = name;              //在新節點內填入資料
			temp->birth = birth;
			temp->right = NULL;
			temp->left = NULL;
		}
	}
	cout<<"(1)Search by birth date"<<endl;
	cout<<"(2)Print tree"<<endl;
	cout<<"Please choose:";
	cin>>input;
	switch (input) {                //讓使用者選擇功能
		case 1:
			search(root);
			break;
		case 2:
			printTree(root,0);
			break;
		default:
			printTree(root,0);
			break;
	}
}

void printTree(node* temp, int indent){
	if(indent){
		cout <<setw(indent)<<" ";          //依照節點所在的層數縮排
	}
	cout<<temp->name<<" "<<temp->birth<<endl;     
	if(temp != NULL) {
		if(temp->right) printTree(temp->right, indent+5);      //印出右邊的子節點
	  if(temp->left) printTree(temp->left, indent+5);        //印出左邊的子節點
	}
}

void search(node* temp){
	int date;
	int found=0;
	string path="";
	cout<<"Please input birth date:";
	cin>>date;
	while(true){
		path+="("+temp->name+")"+to_string(temp->birth);      //記錄找尋的路徑
		if(date>temp->birth){  																//如果目前節點的出生日期比目標的日期大
			path+=" -> ";
			if(temp->right==NULL) break;												//如果右邊沒有節點
			temp=temp->right;																		//向右找目標
		}else if(date<temp->birth){														//如果目前節點的出生日期比目標的日期小
			path+=" -> ";
			if(temp->left==NULL) break;													//如果左邊沒有節點
			temp=temp->left;																		//向左找目標
		}else{																								//如果目前節點的出生日期等於目標的日期
			found=1;																						
			break;
		}
	}
	if(found){																								//如果找到了印出找尋的路徑
		cout<<"Found it!"<<endl;
		cout<<"Path: "<<path<<endl;
	}else{
		cout<<"Not found!"<<endl;																//顯示找不到目標值
	}
}