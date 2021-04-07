#include "C:\USERS\86135\DESKTOP\QG\代码和头文件\DULINKLIST\duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L, ElemType x) 
{
	ElemType i = 0;
	struct DuLNode *p;
	for(i;i<x;i++)
	{
		p = (DuLinkedList)malloc(sizeof(DuLNode));
		(*L)->next = p->prior;
		(*L) = p;
	}
	if (*L == NULL) 
	{
		return ERROR;
	}
	(*L)->next = NULL;

	return SUCCESS;
	
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList L) 
{
	if(!L)
	{
		printf("错误!空链表无法销毁!");
	}
	else
	{
		DuLinkedList p;
		p = L;
		while(p)
		{
			p = p->next ;
			free(L);
			L = p;
		}
		printf("\t节点已销毁!");
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) 
{
	if(p->next == NULL)
	{
		q->next = p;
	}
	else
	{
		q->next = p;
		p->prior = q->prior ;
	}
	if(q->next->next == p->next)
	{
		return SUCCESS;
	}
	return ERROR;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) 
{
	if(p->next == NULL)
	{
		p->next = q;
		q->next = NULL;
	}
	else
	{
		p->next->prior = q ;
		p->next = q ;
		q->prior = p ;
	}
	if(p->next->next == q->next)
	{
		return SUCCESS;
	}
	return ERROR;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) 
{
	struct DuLNode *q;
	q = p->next;
	e = &(q->data);
	p->next = q->next;
	free(q);
	if(p->next != q)
		return SUCCESS;
	return ERROR;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) 
{
	while(L != NULL)
	{
		visit(L->data);
		L = L->next ;
	}
	printf("\n");
}
void visit(ElemType e)
{
	printf("%d->",e);
}
