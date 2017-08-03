#include <stdio.h>
#include <stdlib.h>


typedef struct tree {

	int data;
	struct tree *left;
	struct tree *right;

}bst;

void Insert(bst **,int);
bst* CreateNode();
void Inorder(bst *);
void length(bst *,int,int);
void swap(int *,int*);

int main(){

	int ch , data , n1 , n2;
	bst *root = NULL;

	while(1){

		printf("1: Insert\n2: Display in inorder\n3: Length between two nodes\n4: Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch){

			case 1:
				printf("\nEnter data to be inserted : ");
				scanf("%d",&data);
				Insert(&root,data);
				break;

			case 3:
				printf("Enter value of two nodes :\n");
				scanf("%d%d",&n1,&n2);
				length(root,n1,n2); 
				break;

			case 2:
				printf("\nElements of tree are :\n");
				Inorder(root);
				printf("\n");
				break;

			case 4:
				exit(0);

			default: 
				printf("\nInvalid choice!!!\n");

		}

	}

}

void Insert(bst **root,int data){

	bst *temp = CreateNode();
	bst *current , *track_current;

	temp->data = data;

	if(!*root){

		//temp->data = data;
		*root = temp;

		return;

	}

	current = *root;	
	while( current ){

		track_current = current;
		if( data < current->data)
			current = current->left;

		else if( data >= current->data )
			current = current->right;

	}

	if( data < track_current->data )
		track_current->left = temp;
	else if( data >= track_current->data )
		track_current->right = temp;

	return;
}

bst* CreateNode(){

	bst *temp = (bst*)malloc(sizeof(bst));

	if(!temp){

		printf("\n Error in memory allocation!!!\n");
		return NULL;

	}

	return temp;

}

void Inorder(bst *root) {

	if(!root) 
		return;

	Inorder(root->left);
	printf(" %d ",root->data);
	Inorder(root->right);		

	return;

}

void length(bst *root, int n1, int n2){

	bst *current = root , *temp;
	int len = 0 , i = 2;

	if( n1 > n2 )
		swap(&n1,&n2);

	while( current->data > n2 || current->data < n1 ) {

		if( current->data > n2 )
			current = current->left;
		else if( current->data < n1 )
			current = current->right;

	}

	if( n1 < current->data && n2 > current->data ){
		
		temp = current;
		while(i){

			while( n1 != current->data ){

				if( n1 < current->data )
					current = current->left;
				else if( n1 > current->data )
					current = current->right;
				++len;
			
			}
			swap(&n1,&n2);
			--i;
			current = temp;

		}
	}
	else if( n1 == current->data || n2 == current->data ) {
		
		if( n2 == current->data )
			swap(&n1,&n2);

		while( n2 != current->data ){

			if( n2 < current->data )
				current = current->left;
			else if( n2 > current->data )
				current = current->right;
			
			++len;
	
		}

	}
	else if( n1 != current->data || n2 != current->data ){
		
		printf("\nNode not found\nPlease a enter a valid value\n");
		return;

	}

	printf("\nLength between two nodes is : %d\n",len);	
	return;

}

void swap(int *p,int *q){

	int temp;
	temp = *p;
	*p = *q;
	*q = temp;

}
