#include "C:\USERS\86135\DESKTOP\QG\代码和头文件\LINKLIST\linkedList.h"
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
	printf("\t9.判断链表是否成环\n");
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
	L = head;
	do
	{
		menu();
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: // 创建空链表
			{
				printf("请输入链表长度:");
				scanf("%d", &x);
				num = InitList(&head, x);
				if(num == 0)
				{
					printf("分配内存失败，正在重试中...");
					InitList(&head, x);
				}
				printf("创建空链表成功!");
				break;
			}
		case 2: // 添加链表数据
			{
				printf("请输入链表长度:");
				scanf("%d", &x);
				for(i=0;i<x;i++)
				{
					printf("第%d个节点:", i+1);
					scanf("%d", L);
					getchar();
					L++;
				}
			}
		case 3: // 销毁链表
			{
				DestroyList(&head);
				break;
			}
		case 4: // 插入节点
			{
				printf("请输入要插入在哪个节点后(输入数字)：\t");
				scanf("%d", &i);
				printf("请输入要插入的节点数据(输入数字)：\t");
				scanf("%d", &x);
				q->data = x;
				while(L->data != x)
				{
					L++;
				}
				p = L;
				num = InsertList(p, q);
				if(num == 0)
				{
					printf("插入失败!重试中...");
					InsertList(p, q);
				}
				printf("成功插入节点!");
				break;
			}
		case 5: // 删除节点
			{
				printf("请输入要删除的节点的数据:\t");
				scanf("%d", &x);
				while(L->data != x)
				{
					L++;
				}
				p = L;
				num = DeleteList(p, q);
				if(num == 0)
				{
					printf("删除失败!重试中...");
					DeleteList(p, q);
				}
				printf("成功删除节点!");
				break;
			}
		case 6: // 遍历链表
			{
				TraverseList(L, visit);
			}
		case 7: // 查找节点
			{
				printf("请输入要查找的节点数据(输入数字)：\t");
				scanf("%d", &x);
				while(L->data != x)
				{
					L++;
				}
				num = SearchList(L, x);
				if(num == 0)
				{
					printf("找不到该该节点!");
					break;
				}
				printf("找到了你要找的节点!");
				break;
			}
		case 8: // 反转链表
			{
				num = ReverseList(&head);
				if(num == 0)
				{
					printf("链表为空!无法反转!");
					break;
				}
				printf("链表已反转!");
				break;
			}
		case 9: // 判断链表是否成环
			{
				num = IsLoopList(head);
				if(num == 0)
				{
					printf("链表不成环成环状!");
					break;
				}
				printf("链表成环!");
				break;
			}
		case 10: // 将链表奇偶节点置换
			{
				p = ReverseEvenList(&head);
				printf("链表奇偶节点已置换!\n");
				printf("置换后的链表为:\t");
				TraverseList(L, visit);
				break;
			}
		case 11: // 寻找链表的中间节点
			{
				p = FindMidNode(&head);
				printf("中间节点为%d", p->data );
				break;
			}
		}
	}
	while(choice != 12);
}