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
	int count = 0;
	node2 = mk_tree(2, NULL, NULL);
	node9 = mk_tree(9, NULL, NULL);
	node4 = mk_tree(4, node2, NULL);
	node7 = mk_tree(7, node4, node9);
	
	count_leaf(node7, &count);
	printf("%d", count);
	
}


//4.4
void count_leaf(TREE t,int *count){
	int lsum;
	int rsum;
	
	if(t == NULL) {
		return;
	}
	

	if(t->left == NULL && t->right == NULL ){
		*count += 1;
	}
	
	count_leaf(t->left, count);
	count_leaf(t->right, count);
				
}



TREE mk_tree(int x, TREE left_tree, TREE right_tree){
	TREE temp;
	
	temp = (TREE)malloc(sizeof(TREENODE));
	temp->data = x;
	temp->left = left_tree;
	temp->right = right_tree;
	
	return temp;
}
