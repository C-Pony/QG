#include "C:\USERS\86135\DESKTOP\QG\LINKEDLLIST\Linkedlist.h"
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
	struct LNode *p;
	for(i;i<x-1;i++)
	{
		p = (LNode*)malloc(sizeof(LNode));
		(*L)->next = p;
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
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) 
{
	struct LNode *p;
	(*L) = (*L)->next ;
	p = (*L) ;
	for(*L;(*L)!=NULL;)
	{
		(*L) = (*L)->next ;
		free(p);
		p = (*L);
	}
	printf("\t链表已销毁!");
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
	q->next = p->next;
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
		L = L->next ;
	}
	printf("\n");
}
void visit(ElemType e)
{
	printf("%d->",e);
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
		if(L->data == e)
		{
			return SUCCESS;
		}
		L = L->next ;
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
	while(p != NULL)
	{
		(*L) = p->next;
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
	fast = L;
	slow = L;
	while((fast != NULL) && (fast->next != NULL))
	{
		slow = slow->next;		
		fast = fast->next->next;
		if(fast == slow)
		{
			return SUCCESS;
		}
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
	struct LNode *p, *q, *r, *newHead;
	int i=0;
	if((*L)->next == NULL)
	{
		return ERROR;
	}
	newHead = (*L)->next;
	while( ((*L) != NULL) && ((*L)->next->next != NULL) )
	{
		i++;
		if(i < 2) // 链表头两个交换
		{
			q = (*L)->next ;
			p = q->next ;
			(*L)->next = p ;
			q->next = (*L) ;
			(*L) = p ;
		}
		r = *L ;
		q = (*L)->next ;
		p = q->next ;
		(*L)->next = p ;
		q->next = (*L) ;
		r->next = q ;
		(*L) = p ;
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
