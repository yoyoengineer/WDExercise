#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdlib.h>	
#include "../Utils.h"

typedef struct LNode {
	ElemType  data;
	struct LNode *next;
} *LinkList;

/* Given a node prev_node, insert a new node after the given 
prev_node */
void insertAfter(struct LNode* prev_node, int new_data);

Status LinkedListTraverse(LinkList L, void(Visit)(ElemType));

#endif