#include <iostream>
#include <fstream>


using namespace std;
struct node
{
	int num;
	int ind;
	struct node *pre;
	struct node *lnode;
	struct node *rnode;
	
};


void insert(node *root)
{
	int obj;
	int ind=1;
	node *ptr;
	ifstream file("data.txt");    
	while(!file.eof()){

		file >> obj;

		if(ind==1){
			root->num=obj;
			root->ind=ind;
			root->pre=NULL;
		}

		else{
			
			ptr=root;

			while(true){
				if(ptr->num>obj && ptr->lnode!=NULL){
					ptr=ptr->lnode;
				}

				else if(ptr->num>obj && ptr->lnode==NULL){
					node *add= new node;
					add->num=obj;
					add->ind=ind;
					add->pre=ptr->lnode;
					add->lnode=NULL;
					add->rnode=NULL;
					ptr->lnode=add;
					break;
				}	

				else if(ptr->num <obj && ptr->rnode!=NULL){
					ptr=ptr->rnode;
				}

				else if(ptr->num <obj && ptr->rnode==NULL){
					node *add= new node;
					add->num=obj;
					add->ind=ind;
					add->pre=ptr->rnode;
					add->lnode=NULL;
					add->rnode=NULL;
					ptr->rnode=add;
					break;					
				}
			}
		}
		ind++;
	}
}




void inorder(node* p) {
    if ( p ) {
       inorder(p->lnode);
       cout << p->num << " ";
       inorder(p->rnode);
    }
}


 	




int main()
{
	node *root= new node;
	root->num=0;
	root->lnode=NULL;
	root->rnode=NULL;
	insert(root);
	inorder(root);
	return 0;
}