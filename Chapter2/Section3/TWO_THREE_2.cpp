#include "TWO_THREE_2.h"
	
void two_three_2(LinkList &L, ElemType X) {
	LinkList pre = L;
	LinkList q = L->next;
	LinkList tempVar;
	while(q != NULL) {
		if(q->data == X) {
			tempVar = q;
			q = tempVar->next;
			delete tempVar;
			pre->next = q;
		}else {
			q = q->next;
			pre = pre->next;
		}
	}
}

void exec_two_three_2() {
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
	two_three_2(L, 3);
	
	LinkedListTraverse(L->next, PrintElem);
}