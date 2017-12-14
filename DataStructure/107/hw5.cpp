#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;


struct Node{         
	string word;     
	int f; 
	struct Node* next;    	
	struct Node* rnode; 
	struct Node* lnode;         
};

void postorder(Node* p){
    if(p){
        postorder(p->lnode);
        postorder(p->rnode);
        if(p->word!=" ")
			cout << p->word << " ";

    }
}

void input(Node* p){
	Node* ptr = p;
	ifstream file("data.txt"); 
	char _word;
	int _f;   
	while(!file.eof()){
		file >>_word>>_f;  
		ptr->word=_word;
		ptr->f=_f;
		ptr->next =new Node;                            
		ptr->next->next = NULL;      
		ptr=ptr->next;                    	                   
    }
}

void insert_to_vector(Node* p,vector<Node*>& list){
	Node* ptr = p;
    ptr = p;
    while(ptr!=NULL){
    	list.push_back(ptr);
    	ptr=ptr->next;
    }
    list.pop_back();
}


int main(){
	vector<Node*> list;
	Node* p;
	p = new Node;
	p->next=NULL;
	input(p);
	insert_to_vector(p,list);
	Node* ptr = p;
    while(true){
    	Node* n;
    	n=new Node;
    	n->f=0;
    	n->word=" ";
    	n->rnode=NULL;
    	n->lnode=NULL;
    	for(int i=0;i<2;i++){
    		int min=99;
    		int ind=0;
		 	for(int j=0;j<list.size();j++){
		 		if(list[j]->f < min){
		 			min=list[j]->f;
		 			ind=j;
		 		}
		 	}
		 	if(n->lnode==NULL){
		 		n->lnode=list[ind];
		 		n->f+=list[ind]->f;
		 	}
		 	else{
		 		n->rnode=list[ind];
		 		n->f+=list[ind]->f;
		 	}
		 	list.erase(list.begin()+ind);

		}
		if(list.empty()==1){
			ptr=n;
			break;
		}

		list.push_back(n);
	}

	postorder(ptr);

}