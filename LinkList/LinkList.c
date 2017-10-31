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
	
	
	
	while ( choice != 3){
		instructions();
		printf("? ");
		scanf("%d", &choice);
		
		switch( choice ){
			case 1:
				printf("Enter a character: ");
				scanf("\n%c", &item);
				insert(&startPtr, item);
				printList(startPtr);
				break;
			case 2:
				if( !isEmpty(startPtr)){
					printf("Enter character to be deleted: ");
					scanf("\n%c", &item);
					
					if(delete(&startPtr,item)){ // remove item
						printf("%c deleted. \n", item);
						printList( startPtr);
					}
					else {
						printf("%c not found. \n\n", item);
						printList( startPtr);
					}
				}
			else {
				printf("List is empty. \n\n");
			}
			break;	
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
	
	newPtr =(ListNodePtr) malloc(sizeof(ListNode));
	
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

char delete( ListNodePtr *sPtr, char value){
	ListNodePtr previousPtr; 
	ListNodePtr currentPtr; //for search value
	ListNodePtr tempPtr;//for delete value
	
	// firstNode	
	if( value == (*sPtr)->data) {
		tempPtr = *sPtr;
		*sPtr = (*sPtr)->nextPtr;
		free(tempPtr);
		return value;
	}
	else {
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;
		
		//find value for delete or NULL 
		while( currentPtr != NULL && currentPtr->data != value) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if( currentPtr != NULL){
			// find value for delete
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free(tempPtr);
			return value;
		}
	}
	
	return '\0';
}

int isEmpty( ListNodePtr sPtr){
	return sPtr == NULL;
}

void printList(ListNodePtr currentPtr){
	if(isEmpty(currentPtr)) {
		printf(" List is empty.\n\n");
	} else {
		
		printf("The list is: \n");
		printf("##########################\n");
		while(currentPtr != NULL) {
			printf("%c --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		
		printf("NULL \n");
		
		printf("##########################\n");
	}
}
