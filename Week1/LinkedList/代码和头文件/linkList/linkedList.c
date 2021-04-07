#include "C:\USERS\86135\DESKTOP\QG\�����ͷ�ļ�\LINKLIST\linkedList.h"
#include<stdio.h>
#include<stdlib.h>
/**
 *  @name        : Status InitList(LinkList *L, ElemType x);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L, ElemType x) 
{
	ElemType i = 0;
	for(i;i<x;i++)
	{
		++(*L);
		(*L) = (LNode*)malloc(sizeof(LNode));
	}
	if (*L == NULL) 
	{
		return ERROR;
	}
	(*L)->next = NULL;

	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) 
{
	for(*L;(*L)!=NULL;(*L)++)
	{
		free(*L);
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) 
{
	q = p->next;
	p->next = q;
	if(p->next->next == q->next)
	{
		return SUCCESS;
	}
	return ERROR;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) 
{
	struct LNode *q;
	q = p->next;
	e = &(q->data);
	p->next = q->next;
	free(q);
	if(p->next != q)
		return SUCCESS;
	return ERROR;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) 
{
	while(L != NULL)
	{
		visit(L->data);
		L++;
	}
}

/**
 *  @name        : void visit(ElemType e)
 *	@description : print the list element
 *	@param		 : ElemType e
 *	@return		 : None
 *  @notice      : None
 */
void visit(ElemType e)
{
	printf("%d\t",e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) 
{
	while(L != NULL)
	{
		if(L->data != e)
		{
			return SUCCESS;
		}
		L++;
	}
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) 
{
	struct LNode *p;
	struct LNode *q;
	if((*L)->next == NULL)
	{
		return ERROR;
	}
	p = (*L)->next;
	q = (*L)->next->next;
	(*L)->next = NULL;
	while(q != NULL)
	{
		p->next = (*L);
		(*L) = p;
		p = q;
		q = q->next;
	}
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) 
{
	struct LNode *fast;
	struct LNode *slow;
	while(L != NULL)
	{
		fast = L->next->next;
		slow = L->next;
		if(fast == slow)
		{
			return SUCCESS;
		}
		L++;
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) 
{
	struct LNode *p;
	struct LNode *q;
	struct LNode *newHead;
	newHead = (*L)->next;
	while( ((*L)->next != NULL) && ((*L)->next->next != NULL) )
	{
		p = *L;
		q = (*L)->next;
		q->next = p;
		p->next = (*L)->next->next;
		*L = (*L)->next->next;
	}
	return newHead;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L)
{
	struct LNode *fast;
	struct LNode *slow;
	fast = slow = (*L);
	while((*L) != NULL)
	{
		fast = (*L)->next->next;
		slow = (*L)->next;
		if( (fast == NULL) || (fast->next == NULL) )
		{
			return slow;
		}
	} 
	return NULL;
}

