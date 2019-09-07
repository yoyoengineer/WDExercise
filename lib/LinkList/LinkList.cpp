#include "LinkList.h"

void insertAfter(struct LNode* prev_node, ElemType new_data) 
{ 
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL) { 
		printf("the given previous node cannot be NULL");	 
		return; 
	} 
		
	/* 2. allocate new node */
	struct LNode* new_node =(struct LNode*) malloc(sizeof(struct LNode)); 

	/* 3. put in the data */
	new_node->data = new_data; 

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next; 

	/* 5. move the next of prev_node as new_node */
	prev_node->next = new_node; 
} 

Status LinkedListTraverse(LinkList L, void(Visit)(ElemType)) {
	int i;
	
	while(L != NULL) {
		Visit(L->data);
		L = L->next;
	}
	return OK;
} 