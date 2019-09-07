#include "TWO_THREE_4.h"
	
void two_three_4(LinkList &L) {
	LinkList p = L->next;
	LinkList pre, minpre;
	LinkList minp = p;
	
	while(p != NULL) {
		if(minp->data > p->data) {
			minp = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}
	
	minpre->next = minp->next;
	delete minp;
}

void exec_two_three_4() {
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
	two_three_4(L);
	
	LinkedListTraverse(L->next, PrintElem);
}