#include "C:\USERS\86135\DESKTOP\QG\代码和头文件\DULINKLIST\duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
void menu()
{
	printf("\n\n\n\t双链表ADT\n\n");
	printf("\t1.创建链表\n");
	printf("\t2.添加链表数据\n");
	printf("\t3.销毁链表\n");
	printf("\t4.插入前节点\n");
	printf("\t5.插入后节点\n");
	printf("\t6.删除节点\n");
	printf("\t7.遍历链表\n");
	printf("\t8.退出\n");
	printf("\n\t请输入相应的数字(1-8):\t");
}
void main()
{
	struct DuLNode *head, *L, *p, *q;
	ElemType choice,num,i,x;
	head = (DuLNode*)malloc(sizeof(DuLNode));
	q = (DuLNode*)malloc(sizeof(DuLNode));
	do
	{
		L = head;
		menu();
		scanf("%d",&choice);
		fflush(stdin); // 防止非法输入
		switch(choice)
		{
		case 1: // 创建空链表
			{
				printf("\t请输入链表长度:");
				scanf("%d", &x);
				fflush(stdin); // 防止非法输入
				num = InitList_DuL(&L, x);
				if(num == 0)
				{
					printf("\t分配内存失败，正在重试中...");
					InitList_DuL(&L, x);
				}
				printf("\t创建空链表成功!");
				break;
			}
		case 2: // 添加链表数据
			{
				printf("\t请输入链表长度(请注意：输入与创建的链表相同的长度):");
				scanf("%d", &x);
				fflush(stdin); // 防止非法输入
				L = head;
				for(i=0;i<x;i++)
				{
					printf("\t第%d个节点:", i+1);
					scanf("%d", &(L->data));
					L = L->next ;
				}
				break;
			}
		case 3: // 销毁链表
			{
				DestroyList_DuL(L);
				break;
			}
		case 4: // 插入前节点
			{
				printf("\t请输入要插入在第几个节点前(输入数字)：");
				scanf("%d", &i);
				fflush(stdin); // 防止非法输入
				printf("\t请输入要插入的节点数据(输入数字)：");
				scanf("%d", &(q->data));
				fflush(stdin); // 防止非法输入
				for(i;i>0;i--)
				{
					L = L->next ;
				}
				p = L;
				num = InsertAfterList_DuL(p, q);
				if(num == 0)
				{
					printf("\t插入失败!重试中...");
					InsertAfterList_DuL(p, q);
				}
				printf("\t成功插入节点!");
				break;
			}
		case 5: // 插入后节点
			{
				printf("\t请输入要插入在第几个节点后(输入数字)：");
				scanf("%d", &i);
				fflush(stdin); // 防止非法输入
				printf("\t请输入要插入的节点数据(输入数字)：");
				scanf("%d", &(q->data));
				fflush(stdin); // 防止非法输入
				for(i;i>0;i--)
				{
					L = L->next ;
				}
				p = L;
				num = InsertAfterList_DuL(p, q);
				if(num == 0)
				{
					printf("\t插入失败!重试中...");
					InsertAfterList_DuL(p, q);
				}
				printf("\t成功插入节点!");
				break;
			}
		case 6: // 删除节点
			{
				printf("\t请输入要删除的节点的前一个节点的数据:");
				scanf("%d", &x);
				fflush(stdin); // 防止非法输入
				while(L->data != x)
				{
					L = L->next ;
				}
				p = L;
				num = DeleteList_DuL(p, q);
				if(num == 0)
				{
					printf("\t删除失败!重试中...");
					DeleteList_DuL(p, q);
				}
				printf("\t成功删除节点!");
				break;
			}
		case 7: // 遍历链表
			{
				printf("\t链表数据:");
				TraverseList_DuL(L, visit);
				break;
			}
		default:
            break;
		}
	}
	while(choice != 8);
}