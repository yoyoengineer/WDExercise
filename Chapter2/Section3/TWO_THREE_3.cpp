#include "TWO_THREE_3.h"
	
void two_three_3(LinkList L) {
	if(L->next == NULL) {
		return; 
	} 
	
	two_three_3(L->next);
	
	PrintElem(L->next->data);
}

void exec_two_three_3() {
	LinkList L = NULL;
	L = (LinkList)malloc(sizeof(struct LNode));
	L->next = NULL;
	L->data = 0;

	insertAfter(L, 3);
	insertAfter(L, 2);
	insertAfter(L, 3);
	insertAfter(L, 5);
	insertAfter(L, 6);
	insertAfter(L, 3);
	insertAfter(L, 3);
	insertAfter(L, 8);
	insertAfter(L, 3);
		
	LinkedListTraverse(L->next, PrintElem);
	
	printf("\n");
	two_three_3(L);
}