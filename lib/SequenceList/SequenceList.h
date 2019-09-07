#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdlib.h>	
#include "../Utils.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct {
	ElemType  *data;
	int length;
	int listSize;
}SqList;

Status InitList_Sq(SqList *L);

Status ListInsert(SqList *L, int i, ElemType e);

Status ListEmpty(SqList L);

Status ListDelete(SqList *L, int i, ElemType *e);

Status ListTraverse_Sq(SqList L, void(Visit)(ElemType));

#endif