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
void mirror(bst *,bst **);

int main(){

	int ch , data;
	bst *root = NULL, *new_root = NULL;

	while(1){

		printf("1: Insert\n2: Mirror\n3: Display in inorder\n4: Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch){

			case 1:
				printf("\nEnter data to be inserted : ");
				scanf("%d",&data);
				Insert(&root,data);
				break;

			case 2: mirror(root,&new_root);
				break;

			case 3:
				printf("Which tree :\n1:Default\n2:Mirror\n");
				scanf("%d",&ch);
				printf("\nElements of tree are :\n");
				switch(ch){
			
					case 1:
						Inorder(root);
						break;

					case 2:
						Inorder(new_root);
						break;

				}	
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

	if(!root) {

//		printf("\nTree is empty\n");
		return;

	}

	Inorder(root->left);
	printf(" %d ",root->data);
	Inorder(root->right);		

	return;

}

void mirror(bst *node1,bst **node2){

	if(!node1)
		return;

	*node2 = CreateNode();
	(*node2)->data = node1->data;

	mirror(node1->left,&(*node2)->right);
	mirror(node1->right,&(*node2)->left);

}
