#include <stdio.h>
#include <stdlib.h>

struct listNode {
	char data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert( ListNodePtr *sPtr, char value);
char delete( ListNodePtr *sPtr, char value);
int isEmpty ( ListNodePtr sPtr);
void printList (ListNodePtr currentPtr);
void instructions(void);

int main(){
	ListNodePtr startPtr = NULL;
	int choice;
	char item;
	
	instructions();
//	printf("? ");
//	scanf("%d", &choice);
	
//	printf("Enter a character: ");
//	scanf("\n%c", &item);
//	insert(&startPtr, item);
//	
//	printf("Enter a character: ");
//	scanf("\n%c", &item);
//	insert(&startPtr, item);
	
	while ( choice != 3){
		printf("? ");
		scanf("%d", &choice);
		if(choice == 1){
			printf("Enter a character: ");
			scanf("\n%c", &item);
			insert(&startPtr, item);
			printList(startPtr);
		}		
	}

	
	return 0;
}

void instructions(){
	printf("Enter your choice:\n"
	"	1 to insert an element into the list.\n"
	"	2 to delete an element from the list.\n"
	"	3 to end.\n");
}

void insert(ListNodePtr *sPtr, char value){
	ListNodePtr newPtr;
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	
	newPtr = malloc(sizeof(ListNode));
	
	if( newPtr != NULL){
		newPtr->data = value;
		newPtr->nextPtr = NULL;
		
		previousPtr = NULL;
		currentPtr = *sPtr;
		
		while (currentPtr != NULL && value > currentPtr->data){
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if( previousPtr == NULL){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else {
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else {
		printf(" %c not inserted. No memory avaliable", value);
	}
}

void printList(ListNodePtr currentPtr){
	if(currentPtr == NULL) {
		printf(" List is empty.\n\n");
	} else {
		printf("The list is: \n");
		
		while(currentPtr != NULL) {
			printf("%c --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		
		printf("NULL\n\n");
	}
}
