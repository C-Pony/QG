#include "C:\USERS\86135\DESKTOP\QG\LINKEDLLIST\Linkedlist.h"
#include<stdio.h>
#include<stdlib.h>
void menu()
{
	printf("\n\n\n\t单链表ADT\n\n");
	printf("\t1.创建链表\n");
	printf("\t2.添加链表数据\n");
	printf("\t3.销毁链表\n");
	printf("\t4.插入节点\n");
	printf("\t5.删除节点\n");
	printf("\t6.遍历链表\n");
	printf("\t7.查找节点\n");
	printf("\t8.反转链表\n");
	printf("\t9.判断当前链表是否成环\n");
	printf("\t10.将链表奇偶节点置换\n");
	printf("\t11.寻找链表的中间节点\n");
	printf("\t12.退出\n");
	printf("\n\t请输入相应的数字(1-12):\t");
}
void main()
{
	struct LNode *head, *L, *p, *q;
	ElemType choice,num,i,x;
	head = (LNode*)malloc(sizeof(LNode));
	q = (LNode*)malloc(sizeof(LNode));
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
				num = InitList(&L, x);
				if(num == 0)
				{
					printf("\t分配内存失败，正在重试中...");
					InitList(&L, x);
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
					fflush(stdin); // 防止非法输入
					L = L->next ;
				}
				break;
			}
		case 3: // 销毁链表
			{
				DestroyList(&L);
				break;
			}
		case 4: // 插入节点
			{
				printf("\t请输入要插入在第几个节点后(输入数字)：");
				scanf("%d", &i);
				fflush(stdin); // 防止非法输入
				printf("\t请输入要插入的节点数据(输入数字)：");
				scanf("%d", &(q->data));
				fflush(stdin); // 防止非法输入
				for(i;i>1;i--)
				{
					L = L->next ;
				}
				p = L;
				num = InsertList(p, q);
				if(num == 0)
				{
					printf("\t插入失败!重试中...");
					InsertList(p, q);
				}
				printf("\t成功插入节点!");
				break;
			}
		case 5: // 删除节点
			{
				printf("\t请输入要删除的节点的前一个节点的数据:");
				scanf("%d", &x);
				fflush(stdin); // 防止非法输入
				while(L->data != x)
				{
					L = L->next ;
				}
				p = L;
				num = DeleteList(p, q);
				if(num == 0)
				{
					printf("\t删除失败!重试中...");
					DeleteList(p, q);
				}
				printf("\t成功删除节点!");
				break;
			}
		case 6: // 遍历链表
			{
				printf("\t当前链表数据为:");
				TraverseList(L, visit);
				break;
			}
		case 7: // 查找节点
			{
				printf("\t请输入要查找的节点数据(输入数字)：");
				scanf("%d", &x);
				fflush(stdin); // 防止非法输入
				L = head;
				num = SearchList(L, x);
				if(num == 0)
				{
					printf("\t找不到该节点!");
					break;
				}
				printf("\t找到了你要找的节点!");
				break;
			}
		case 8: // 反转链表
			{
				num = ReverseList(&L);
				if(num == 0)
				{
					printf("\t链表为空!无法反转!");
					break;
				}
				printf("\t链表已反转!");
				printf("\t反转后的链表为:");
				TraverseList(L, visit);
				break;
			}
		case 9: // 判断链表是否成环
			{
				num = IsLoopList(L);
				if(num == 0)
				{
					printf("\t链表不成环状!");
					break;
				}
				printf("\t链表成环!");
				break;
			}
		case 10: // 将链表奇偶节点置换
			{
				p = ReverseEvenList(&L);
				printf("\t链表奇偶节点已置换!\n");
				printf("\t置换后的链表为:");
				TraverseList(p, visit);
				break;
			}
		case 11: // 寻找链表的中间节点
			{
				L = head;
				p = FindMidNode(&L);
				printf("\t中间节点为%d", p->data );
				break;
			}
		default:
            break;
		}
	}
	while(choice != 12);
}