#include "TWO_THREE_1.h"

void two_three_1(LinkList &L, ElemType X) {
	LinkList tempVar;
	if(L == NULL) {
		return; 
	} 
	
	two_three_1(L->next, X);
	
	if(L->data == X) {
		tempVar = L;
		L = L->next;
		delete tempVar;
	}
}

void exec_two_three_1() {
	LinkList L = NULL;
	L = (LinkList)malloc(sizeof(struct LNode));
	L->next = NULL;
	L->data = 3;

	insertAfter(L, 3);
	insertAfter(L, 2);
	insertAfter(L, 3);
	insertAfter(L, 5);
	insertAfter(L, 6);
	insertAfter(L, 3);
	insertAfter(L, 3);
	insertAfter(L, 8);
	insertAfter(L, 3);
		
	LinkedListTraverse(L, PrintElem);
	
	printf("\n");
	two_three_1(L, 3);
	
	LinkedListTraverse(L, PrintElem);
}