#include<stdio.h>

struct treenode{
	struct treenode *left;
	int data;
	struct treenode *right;
};
typedef struct treenode TREENODE;
typedef TREENODE *TREE;

TREE mk_tree(int x, TREE left_tree, TREE right_tree);
int sum_leaf(TREE t);
int sum_allNode(TREE t);


int main() {
	TREE node2, node4, node9, node7;
	int sum = 0;
	node2 = mk_tree(2, NULL, NULL);
	node9 = mk_tree(9, NULL, NULL);
	node4 = mk_tree(4, node2, NULL);
	node7 = mk_tree(7, node4, node9);
	
	sum = validate_bst(node7);
	printf("%d", sum);
	
}

int sum_allNode(TREE t) {
	if(t == NULL) {
		return 0;
	}
	
	return t->data + sum_allNode(t->left) + sum_allNode(t->right) ;
}

//4.4
int sum_leaf(TREE t){
	int lsum;
	int rsum;
	
	if(t == NULL) {
		return 0;
	}
	

	if(t->left == NULL && t->right == NULL ){
		//printf("%d \n", t->data);
		return t->data;
	}
	else {
		return sum_leaf(t->left) + sum_leaf(t->right);
	}
				
}

int validate_bst(TREE t){
	if(t == NULL) {
		return 1;
	}
	if(t->left != NULL && maxValue(t->left) >= t->data){
		return 0;
	}
	
	if(t->right != NULL && minValue(t->right) <= t->data) {
		return 0;
	}
	
	if(!validate_bst(t->left) || !validate_bst(t->right)) {
		return 0;
	}
	
	return 1;
}

int maxValue(TREE t) {
	if(t->left == NULL && t->right == NULL){
		return t->data;
	} else if(t->left == NULL) {
		return t->right->data;
	} else if(t->right == NULL) {
		return t->left->data;
	}
	
	if(t->left->data <= t->right->data) {
		return t->right->data;
	} else {
		return t->left->data;
	}
}

int minValue(TREE t) {
	if(t->left == NULL && t->right == NULL){
		return t->data;
	} else if(t->left == NULL) {
		return t->right->data;
	} else if(t->right == NULL) {
		return t->left->data;
	}
	
	if(t->left->data <= t->right->data) {
		return t->left->data;
	} else {
		return t->right->data;
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
