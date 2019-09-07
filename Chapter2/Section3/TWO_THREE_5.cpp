#include "TWO_THREE_5.h"
	
void two_three_5(LinkList &L) {
	LinkList p = L->next;
	LinkList tempVar;
	
	L->next = NULL;
	while(p != NULL) {
		tempVar = p;
		p = p->next;
		tempVar->next = L->next;
		L->next = tempVar;
	}
}

void exec_two_three_5() {
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
	insertAfter(L, 1);
	insertAfter(L, 8);
	insertAfter(L, 7);
		
	LinkedListTraverse(L->next, PrintElem);
	
	printf("\n");
	two_three_5(L);
	
	LinkedListTraverse(L->next, PrintElem);
}