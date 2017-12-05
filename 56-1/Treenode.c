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
	TREE node2, node4, node9, node7, node5, node8;
	int sum = 0;
	node8 = mk_tree(8, NULL, NULL);
	node2 = mk_tree(2, NULL, NULL);
	node5 = mk_tree(5, NULL, NULL);
	node9 = mk_tree(9, NULL, NULL);
	node4 = mk_tree(4, node2, node5);
	node7 = mk_tree(7, node4, node9);
	
	sum = validate_bst2(node7);
	printf("%d", sum);
	
}


//2.3
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

int validate_bst2(TREE t){
	if(t == NULL) {
		return 1;
	}
	
	if(t->left != NULL && maxValue(t->left) >= t->data || t->right != NULL && minValue(t->right) <= t->data){
		return 0 && validate_bst2(t->left) && validate_bst2(t->right);
	} else {
		return 1 && validate_bst2(t->left) && validate_bst2(t->right);
	}	
	
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
