#include "C:\USERS\86135\DESKTOP\QG\�����ͷ�ļ�\LINKLIST\linkedList.h"
#include<stdio.h>
#include<stdlib.h>
void menu()
{
	printf("\n\n\n\t������ADT\n\n");
	printf("\t1.��������\n");
	printf("\t2.�����������\n");
	printf("\t3.��������\n");
	printf("\t4.����ڵ�\n");
	printf("\t5.ɾ���ڵ�\n");
	printf("\t6.��������\n");
	printf("\t7.���ҽڵ�\n");
	printf("\t8.��ת����\n");
	printf("\t9.�ж������Ƿ�ɻ�\n");
	printf("\t10.��������ż�ڵ��û�\n");
	printf("\t11.Ѱ��������м�ڵ�\n");
	printf("\t12.�˳�\n");
	printf("\n\t��������Ӧ������(1-12):\t");
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
		case 1: // ����������
			{
				printf("������������:");
				scanf("%d", &x);
				num = InitList(&head, x);
				if(num == 0)
				{
					printf("�����ڴ�ʧ�ܣ�����������...");
					InitList(&head, x);
				}
				printf("����������ɹ�!");
				break;
			}
		case 2: // �����������
			{
				printf("������������:");
				scanf("%d", &x);
				for(i=0;i<x;i++)
				{
					printf("��%d���ڵ�:", i+1);
					scanf("%d", L);
					getchar();
					L++;
				}
			}
		case 3: // ��������
			{
				DestroyList(&head);
				break;
			}
		case 4: // ����ڵ�
			{
				printf("������Ҫ�������ĸ��ڵ��(��������)��\t");
				scanf("%d", &i);
				printf("������Ҫ����Ľڵ�����(��������)��\t");
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
					printf("����ʧ��!������...");
					InsertList(p, q);
				}
				printf("�ɹ�����ڵ�!");
				break;
			}
		case 5: // ɾ���ڵ�
			{
				printf("������Ҫɾ���Ľڵ������:\t");
				scanf("%d", &x);
				while(L->data != x)
				{
					L++;
				}
				p = L;
				num = DeleteList(p, q);
				if(num == 0)
				{
					printf("ɾ��ʧ��!������...");
					DeleteList(p, q);
				}
				printf("�ɹ�ɾ���ڵ�!");
				break;
			}
		case 6: // ��������
			{
				TraverseList(L, visit);
			}
		case 7: // ���ҽڵ�
			{
				printf("������Ҫ���ҵĽڵ�����(��������)��\t");
				scanf("%d", &x);
				while(L->data != x)
				{
					L++;
				}
				num = SearchList(L, x);
				if(num == 0)
				{
					printf("�Ҳ����øýڵ�!");
					break;
				}
				printf("�ҵ�����Ҫ�ҵĽڵ�!");
				break;
			}
		case 8: // ��ת����
			{
				num = ReverseList(&head);
				if(num == 0)
				{
					printf("����Ϊ��!�޷���ת!");
					break;
				}
				printf("�����ѷ�ת!");
				break;
			}
		case 9: // �ж������Ƿ�ɻ�
			{
				num = IsLoopList(head);
				if(num == 0)
				{
					printf("�����ɻ��ɻ�״!");
					break;
				}
				printf("����ɻ�!");
				break;
			}
		case 10: // ��������ż�ڵ��û�
			{
				p = ReverseEvenList(&head);
				printf("������ż�ڵ����û�!\n");
				printf("�û��������Ϊ:\t");
				TraverseList(L, visit);
				break;
			}
		case 11: // Ѱ��������м�ڵ�
			{
				p = FindMidNode(&head);
				printf("�м�ڵ�Ϊ%d", p->data );
				break;
			}
		}
	}
	while(choice != 12);
}