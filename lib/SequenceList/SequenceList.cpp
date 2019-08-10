#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "sequenceList.h"
#include "../Status.h"

void PrintElem(ElemType e)
{
	printf("%d ", e);
}

Status InitList_Sq(SqList *L){
	L->data = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->data){
		exit(OVERFLOW);
	}
	L->length = 0;
	L->listSize = LIST_INIT_SIZE;
	
	return OK;
}

Status ListInsert(SqList *L, int i, ElemType e) {
	ElemType *newBase;
	ElemType *p, *q;
	if(i < 1 || i > L->length + 1){
		return ERROR;
	}
	if(L->length >= L->listSize){
		newBase = (ElemType*)realloc(L->data, (L->listSize + LISTINCREMENT)*sizeof(ElemType));
		if(!newBase){
			exit(OVERFLOW);
		}
		L->data = newBase;
		L->listSize += LISTINCREMENT;
	}
	q = &L->data[i-1];
	for(p=&L->data[L->length-1]; p>=q; --p){
		*(p+1) = *p;
	}
	*q = e;
	L->length++;
	return OK;
}

Status ListTraverse_Sq(SqList L, void(Visit)(ElemType)){
	int i;
	
	for(i = 0; i < L.length; i++){
		Visit(L.data[i]);
	}
	return OK;
}

Status ListEmpty(SqList L){
	return L.length == 0 ? TRUE : FALSE;
}

Status ListDelete(SqList *L, int i, ElemType *e){
	ElemType *p, *q;
	
	if(i < 1 || i > L->length){
		return ERROR;
	}
	p = &L->data[i-1];
	*e = *p;
	q = L->data + L->length - 1;
	
	for(++p; p <= q; ++p){
		*(p-1) = *p;
	}
	
	L->length--;
	
	return OK;
}

#endif