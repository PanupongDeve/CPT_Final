#include<stdio.h>

struct listnode {
	char c;
	struct listnode *next;
};

typedef struct listnode LN;

void printList(LN *head);
LN *string_to_list(char *s);
void str_end(LN **hptr, char c);

int main() {
	LN *head;
	char c[128];
	gets(c);
	head = string_to_list(c);
	str_end(&head, 'l');
	printList(head);
	
	return 0;
}

void printList(LN *head){
	LN *current = head;
	
	while( current != NULL) {
		printf("%c", current->c);
		current = current->next;
	}
}

//2.2
void str_end(LN **hptr, char c) {
	LN *current = *hptr;
	LN *previous = NULL;
	LN *tmp;
	

	
	while ( current != NULL) {
		if (current->c == c) {
			tmp = current;
			previous->next = NULL;
			free(tmp);
			break;
		}
		previous = current;
		current = current->next;
	}
}

//2.1
LN *string_to_list(char *s){
	LN *head = NULL;
	LN *tail = NULL;
	LN *current = NULL;
	
	while ( *s != '\0'){
		current = (LN*)malloc(sizeof(LN));
		current->c = *s;
		current->next = NULL;
		if(head == NULL){
			head=current;
		} else {
			tail->next = current;
		}
		tail = current;
		s++;
	}
	return head;
}
