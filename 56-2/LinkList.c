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

LNP find(LNP *lst, int data) {
	LNP current = *lst;
	LNP previous = NULL;
	LNP Head = *lst;
	
	while(current != NULL) {
		
		if(current->data == data) {
			previous->next = current->next;
			current->next = Head;
			Head = current;
			return Head;
		}
		
		previous = current;
		current = current->next;
	}
	
	return NULL;
}


int main() {
	LNP lst = NULL;
	int i;
	
	for(i=0;i<10;i++) {
		insert(&lst,i);
	}
	
	printList(lst);
	lst = find(&lst, 5);
	printList(lst);
	return 0;
}
