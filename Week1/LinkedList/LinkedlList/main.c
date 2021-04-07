#include "C:\USERS\86135\DESKTOP\QG\LINKEDLLIST\Linkedlist.h"
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
	printf("\t9.�жϵ�ǰ�����Ƿ�ɻ�\n");
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
	q = (LNode*)malloc(sizeof(LNode));
	do
	{
		L = head;
		menu();
		scanf("%d",&choice);
		fflush(stdin); // ��ֹ�Ƿ�����
		switch(choice)
		{
		case 1: // ����������
			{
				printf("\t������������:");
				scanf("%d", &x);
				fflush(stdin); // ��ֹ�Ƿ�����
				num = InitList(&L, x);
				if(num == 0)
				{
					printf("\t�����ڴ�ʧ�ܣ�����������...");
					InitList(&L, x);
				}
				printf("\t����������ɹ�!");
				break;
			}
		case 2: // �����������
			{
				printf("\t������������(��ע�⣺�����봴����������ͬ�ĳ���):");
				scanf("%d", &x);
				fflush(stdin); // ��ֹ�Ƿ�����
				L = head;
				for(i=0;i<x;i++)
				{
					printf("\t��%d���ڵ�:", i+1);
					scanf("%d", &(L->data));
					fflush(stdin); // ��ֹ�Ƿ�����
					L = L->next ;
				}
				break;
			}
		case 3: // ��������
			{
				DestroyList(&L);
				break;
			}
		case 4: // ����ڵ�
			{
				printf("\t������Ҫ�����ڵڼ����ڵ��(��������)��");
				scanf("%d", &i);
				fflush(stdin); // ��ֹ�Ƿ�����
				printf("\t������Ҫ����Ľڵ�����(��������)��");
				scanf("%d", &(q->data));
				fflush(stdin); // ��ֹ�Ƿ�����
				for(i;i>1;i--)
				{
					L = L->next ;
				}
				p = L;
				num = InsertList(p, q);
				if(num == 0)
				{
					printf("\t����ʧ��!������...");
					InsertList(p, q);
				}
				printf("\t�ɹ�����ڵ�!");
				break;
			}
		case 5: // ɾ���ڵ�
			{
				printf("\t������Ҫɾ���Ľڵ��ǰһ���ڵ������:");
				scanf("%d", &x);
				fflush(stdin); // ��ֹ�Ƿ�����
				while(L->data != x)
				{
					L = L->next ;
				}
				p = L;
				num = DeleteList(p, q);
				if(num == 0)
				{
					printf("\tɾ��ʧ��!������...");
					DeleteList(p, q);
				}
				printf("\t�ɹ�ɾ���ڵ�!");
				break;
			}
		case 6: // ��������
			{
				printf("\t��ǰ��������Ϊ:");
				TraverseList(L, visit);
				break;
			}
		case 7: // ���ҽڵ�
			{
				printf("\t������Ҫ���ҵĽڵ�����(��������)��");
				scanf("%d", &x);
				fflush(stdin); // ��ֹ�Ƿ�����
				L = head;
				num = SearchList(L, x);
				if(num == 0)
				{
					printf("\t�Ҳ����ýڵ�!");
					break;
				}
				printf("\t�ҵ�����Ҫ�ҵĽڵ�!");
				break;
			}
		case 8: // ��ת����
			{
				num = ReverseList(&L);
				if(num == 0)
				{
					printf("\t����Ϊ��!�޷���ת!");
					break;
				}
				printf("\t�����ѷ�ת!");
				printf("\t��ת�������Ϊ:");
				TraverseList(L, visit);
				break;
			}
		case 9: // �ж������Ƿ�ɻ�
			{
				num = IsLoopList(L);
				if(num == 0)
				{
					printf("\t�����ɻ�״!");
					break;
				}
				printf("\t����ɻ�!");
				break;
			}
		case 10: // ��������ż�ڵ��û�
			{
				p = ReverseEvenList(&L);
				printf("\t������ż�ڵ����û�!\n");
				printf("\t�û��������Ϊ:");
				TraverseList(p, visit);
				break;
			}
		case 11: // Ѱ��������м�ڵ�
			{
				L = head;
				p = FindMidNode(&L);
				printf("\t�м�ڵ�Ϊ%d", p->data );
				break;
			}
		default:
            break;
		}
	}
	while(choice != 12);
}