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
	
	sum = sum_leaf(node7);
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

TREE mk_tree(int x, TREE left_tree, TREE right_tree){
	TREE temp;
	
	temp = (TREE)malloc(sizeof(TREENODE));
	temp->data = x;
	temp->left = left_tree;
	temp->right = right_tree;
	
	return temp;
}
