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


//2.2
void insert_in_order(LNP *head, int data) {
	LNP current = *head;
	LNP previous = *head;
	LNP newNode;
	
	newNode = (LNP)malloc(sizeof(LISTNODE));
	newNode->data = data;
	newNode->next = NULL;
	
	if(current == NULL){
		current = newNode; //list = NULL  insert 8 result 8->NULL
	}else if(current->next == NULL) {
		if(current->data <= data){ // list = 5->NULL insert 6 result = 5->6->NULL 
			current->next = newNode;
		} else {
			newNode->next = current; // list = 8->NULL insert 6 result = 6->8->NULL
			*head = newNode;
		}
	}
	
	if(data <= current->data) { //insert first Node
		newNode->next = current; // list = 1->2->3->NULL insert 0 result = 0->1->2->3->NULL
		*head = newNode;
		current = current->next;
	}

	while(current != NULL) {
		if(data <= current->data){
			previous->next = newNode; //list = 2->6->NULL insert 4 result 2->4->6->NULL
			newNode->next = current;
			break;
		}else if(current->next == NULL){// insert last node
			current->next = newNode; // list = 2->6->NULL insert 8 result 2->6->8->NULL 
			break;
		}
		
		previous = current;
		current = current->next;
	}
	
}

int main() {
	LNP lst = NULL;
	int i;
	
	for(i=9;i>=0;i--) {
		if(i==6){
			continue;
		}
		insert(&lst,i);
	}
	
	//insert(&lst,7);
	
	//printList(lst);
	insert_in_order(&lst, 0);
	insert_in_order(&lst, 60);
	printList(lst);
	return 0;
}
