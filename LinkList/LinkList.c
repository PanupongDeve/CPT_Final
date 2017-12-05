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
void deleteAllList(ListNodePtr *sPtr);
int isEmpty ( ListNodePtr sPtr);
void printList (ListNodePtr currentPtr);
void instructions(void);
void swap(ListNodePtr *sPtr);
void reverseList(ListNodePtr *sPtr);

int main(){
	ListNodePtr startPtr = NULL;
	int choice;
	char item;
	
	
	
	while ( choice != 6){
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
			case 3: 
				deleteAllList(&startPtr);
				printf("Delete All List!!\n\n");
				printList(startPtr);
				break;
			
			case 4:
				swap(&startPtr);
				printf("Swap!!");
				printList(startPtr);
				break;
			case 5:
				if(!isEmpty(startPtr)){
					reverseList(&startPtr);
					printf("Reverse List Success!!!!\n\n");	
				}
				printList(startPtr);
				break;
		}					
	}

	
	return 0;
}

void instructions(){
	printf("Enter your choice:\n"
	"	1 to insert an element into the list.\n"
	"	2 to delete an element from the list.\n"
	"	3 to All lists.\n"
	"	4 swap List.\n"
	"	5 reverse List.\n"
	"	6 to end.\n");
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

void deleteAllList(ListNodePtr *sPtr){
	ListNodePtr currentPtr = *sPtr;
	ListNodePtr tempPtr;
	
	while(currentPtr != NULL){
		tempPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
		free(tempPtr);
	}
	
	*sPtr = NULL;
}

int isEmpty( ListNodePtr sPtr){
	return sPtr == NULL;
}

void printList(ListNodePtr currentPtr){
	if(isEmpty(currentPtr)) {
		printf(" List is empty.\n\n");
	} else {
		
		printf("\nThe list is: \n\n");
		printf("##########################\n");
		while(currentPtr != NULL) {
			printf("%c --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		
		printf("NULL \n");
		
		printf("##########################\n\n");
	}
}

void swap(ListNodePtr *sPtr){
	ListNodePtr currentPtr = *sPtr;
	ListNodePtr savePtr = currentPtr;
	
	currentPtr = currentPtr->nextPtr;
	currentPtr->nextPtr = savePtr;
	savePtr->nextPtr = NULL;
	
	*sPtr = currentPtr;
}

void reverseList(ListNodePtr *sPtr){
	ListNodePtr HeadPtr = *sPtr;
	ListNodePtr currentPtr = HeadPtr;
	ListNodePtr current2Ptr = HeadPtr;
	
	// 1st Chang HeadNode to TailNode
	HeadPtr = HeadPtr->nextPtr;
	currentPtr->nextPtr = NULL; 
	
	while(HeadPtr != NULL){
		currentPtr = HeadPtr;
		HeadPtr = HeadPtr->nextPtr;
		currentPtr->nextPtr = current2Ptr;
		current2Ptr = currentPtr;
	}
	
	
	*sPtr = currentPtr;
}
