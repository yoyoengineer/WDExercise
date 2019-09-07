#include "TWO_THREE_8.h"
	
LinkList two_three_8(LinkList A, LinkList B) {
	LinkList ta = A;
	LinkList tb = B;
	
	int acount = 0;
	int bcount = 0;
	
	int dif;
	
	while(ta != NULL) {
		ta = ta->next;
		acount++;
	}
	
	while(tb != NULL) {
		tb = tb->next;
		bcount++;
	}
	
	if(ta != tb) {
		return NULL;
	}
	
	dif = acount - bcount;

	ta = A;
	tb = B;
		
	if(dif > 0) {
		while(dif--) {
			ta = ta->next;
		}
	}else {
		while(dif++) {
			tb = tb->next;
		}
	}
	
	while(ta != tb){
		ta = ta->next;
		tb = tb->next;	
	}
	
	return ta;
}

void exec_two_three_8() {
	LinkList A = NULL;
	LinkList B = NULL;
	LinkList C = NULL;
	LinkList D;
	
	LinkList ta;
	LinkList tb;
	
	A = (LinkList)malloc(sizeof(struct LNode));
	A->next = NULL;
	A->data = 0;
	
	
	B = (LinkList)malloc(sizeof(struct LNode));
	B->next = NULL;
	B->data = 0;
	
	C = (LinkList)malloc(sizeof(struct LNode));
	C->next = NULL;
	C->data = 0;
	
	ta = A;
	tb = B;
	
	insertAfter(A, 3);
	insertAfter(A, 2);
	insertAfter(A, 5);
	insertAfter(B, 6);
	insertAfter(B, 1);
	insertAfter(B, 8);
	insertAfter(C, 3);
	insertAfter(C, 7);
	insertAfter(C, 9);
	
	while(ta->next != NULL) {
		ta = ta->next;
	}
	
	while(tb->next != NULL) {
		tb = tb->next;
	}
	
	ta->next = C;
	tb->next = C;
		
	printf("A: ");
	LinkedListTraverse(A->next, PrintElem);
	printf("\n");

	printf("B: ");
	LinkedListTraverse(B->next, PrintElem);
	printf("\n");
	printf("\n");
	
	D = two_three_8(A, B);
	
	if(D != NULL) {
		printf("Common node data: %d\n", D->data);		
	}
}