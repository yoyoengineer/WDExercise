#include "TWO_THREE_6.h"
	
void two_three_6(LinkList &L) {
	LinkList f = L->next;
	LinkList p = f;

	LinkList minp = f;

	L->next = NULL;
	
	LinkList t = L;
	
	LinkList h = NULL;
	h = (LinkList)malloc(sizeof(struct LNode));
	h->next = f;
	h->data = 0;
	
	LinkList pre = h;
	LinkList minpre = h;
	
	while(p != NULL) {
		while(p != NULL) {
			if(p->data < minp->data) {
				minp = p;
				minpre = pre;
			}
			pre = p;
			p = p->next;
		}
		pre = h;
		minpre->next = minp->next;
		minp->next = t->next;
		t->next = minp;
		t = minp;
		p = pre->next;
		minp = p;
		minpre = pre;
	}
}

void exec_two_three_6() {
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
	two_three_6(L);
	
	LinkedListTraverse(L->next, PrintElem);
}