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
void Delete(bst **,int);

int main(){

	int ch , data;
	bst *root = NULL;

	while(1){

		printf("1: Insert\n2: Delete\n3: Display in inorder\n4: Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch){

			case 1:
				printf("\nEnter data to be inserted : ");
				scanf("%d",&data);
				Insert(&root,data);
				break;

			case 2: 
				printf("\nEnter node's value to be deleted : ");
				scanf("%d",&data);
				Delete(&root,data);
				break;

			case 3:
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

	if(!root) {

//		printf("\nTree is empty\n");
		return;

	}

	Inorder(root->left);
	printf(" %d ",root->data);
	Inorder(root->right);		

	return;

}

void Delete(bst **root, int data) {

	bst *temp , *current , *leaf , *parent = {0};
	int temp1;

	if(!*root) {

		printf("\nTree is empty!!\n");
		return;

	}
	current = *root;
	temp = current;
	while( current && current->data != data ){
		
		temp = current;
		if( current->data < data )
			current = current->right;
		else if( current->data > data )
			current = current->left;

	}

	if(!current){

		printf("\nNode with given value is not there in tree!!!\n");
		return;

	}
/*

If node to be deleted is a leaf node

*/

	if( !( current->left || current->right ) ){
		
		if( *root == current )
			*root = NULL;
		else if( temp->left == current )
			temp->left = 0x0;
		else if( temp->right == current )
			temp->right = 0x0;

		return;

	}


/*

	Find the node with minimum value 
	in right subtree of node to be deleted.

*/
	leaf = current->right;
	while(leaf->left){

		parent = leaf;
		leaf = leaf->left;

	}

	temp1 = (*current).data;
	current->data = leaf->data;
	(*leaf).data = temp1;
	if(parent)
		parent = parent->left;
	free(parent);

	return;
}


/*
Check whether node to be deleted is
  left child or right child of the parent

			temp2 = temp->right;
	if( temp->left == current ){

			temp->right = temp->left;

	}
	else if( temp->right == current )

If the node to be deleted is having only right child

	if( !( current->left ) )
		temp->right = current->right;

If the node to be deleted is having only left child

	else if( !( current->right ) )
		temp->right = current->left;

If right child of the node to be deleted is a leaf node

	else if( !( current->right->left || current->right->right ) ){

		temp->right = current->right;
		current->right->left = current->left;

	}	

If left child node of the node to be deleted is a leaf node

	else if( !( current->left->left || current->left->right ) ){

		temp->right = current->left;
		current->left->right = current->right;

	}
	
	Else if the node to be deleted is having left subtree 
	as well as right subtree, then traverse till the smallest leaf node 
	in right subtree i.e

		 135
	       /     \
	     127      140
	    /   \    /    \
	  126  128  139  141
	
	If 135 is to be deleted, then replace 135 with 139.
	
	Traversing till the leaf node

	else{
		leaf = current->right;
		while( leaf->left ){

			parent = leaf;
			leaf = leaf->left;

		}		
	
		temp->right = leaf;
		leaf->left = current->left;
		leaf->right = current->right;
 		parent->left = 0x0;
//	free(parent);
//	free(current);

	}

	if( current == *root )
		*root = temp->right;

	temp->right = temp2;
*/
