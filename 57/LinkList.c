#include<stdio.h>

//1
struct node {
	int data;
	struct node *next;
};

typedef struct node LISTNODE;
typedef LISTNODE *LNP;

void insert(LNP *lst, int data) {
	LNP newNode;
	newNode = (LNP)malloc(sizeof(LISTNODE));
	if(newNode != NULL) {
		newNode->data = data;
		newNode->next = *lst;
		*lst = newNode;
	}
}

void printList(LNP lst) {
	while ( lst != NULL) {
		printf("%d ", lst->data);
		lst = lst->next;
	}
	printf("\n");
}

void findUpdate(LNP lst, int data, int new_value) {
	LNP current = lst;

	
	while(current != NULL) {
		
		if(current->data == data) {
			modify_data(current, new_value);
		}
		
		current = current->next;
	}
	
}

//1.2
void modify_data(LNP node, int new_value) {
	if(node != NULL) {
		node->data = new_value;
	}
}

void insert_in_order(LNP head, int data) {
	LNP current = head;
	LNP previous = NULL;
	LNP newNode;
	
	newNode = (LNP)malloc(sizeof(LISTNODE));
	newNode->data = data;
	newNode->next = NULL;
	
	while(current != NULL) {
		printf("%d ", current->data);
		
		current = current->next;
	}
	
}

int main() {
	LNP lst = NULL;
	int i;
	
	for(i=0;i<10;i++) {
		insert(&lst,i);
	}
	
	//printList(lst);
	insert_in_order(lst, 8);
	//printList(lst);
	return 0;
}
