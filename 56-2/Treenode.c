#include<stdio.h>

struct treenode{
	struct treenode *left;
	int data;
	struct treenode *right;
};
typedef struct treenode TREENODE;
typedef TREENODE *TREE;

TREE mk_tree(int x, TREE left_tree, TREE right_tree);

void printDescending(TREE t);
void preOrder(TREE t);
void inOrder(TREE t);
void PostOrder(TREE t);

int main() {
	TREE node2, node4, node9, node7;
	int sum = 0;
	node2 = mk_tree(2, NULL, NULL);
	node9 = mk_tree(9, NULL, NULL);
	node4 = mk_tree(4, node2, NULL);
	node7 = mk_tree(7, node4, node9);
	
	//printDescending(node7);
	//preOrder(node7);
	//inOrder(node7);
	//PostOrder(node7);
}

void preOrder(TREE t) {
	//NLR
	if(t != NULL) {
		printf("%d ", t->data);
		preOrder(t->left);
		preOrder(t->right);		
	}
}

void inOrder(TREE t) {
	//LNR
	if(t != NULL) {
		inOrder(t->left);
		printf("%d ", t->data);
		inOrder(t->right);	
	}
}

//5
void printDescending(TREE t){
	//RNL
	if(t != NULL) {
		printDescending(t->right);
		printf("%d ", t->data);
		printDescending(t->left);	
	}
}


void PostOrder(TREE t) {
	//LRN
	if(t != NULL) {
		PostOrder(t->left);
		PostOrder(t->right);	
		printf("%d ", t->data);
	}
}


TREE mk_tree(int x, TREE left_tree, TREE right_tree){
	TREE temp;
	
	temp = (TREE)malloc(sizeof(TREENODE));
	temp->data = x;
	temp->left = left_tree;
	temp->right = right_tree;
	
	return temp;
}
