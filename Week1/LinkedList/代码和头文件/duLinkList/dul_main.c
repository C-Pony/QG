#include "C:\USERS\86135\DESKTOP\QG\�����ͷ�ļ�\DULINKLIST\duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
void menu()
{
	printf("\n\n\n\t˫����ADT\n\n");
	printf("\t1.��������\n");
	printf("\t2.�����������\n");
	printf("\t3.��������\n");
	printf("\t4.����ǰ�ڵ�\n");
	printf("\t5.�����ڵ�\n");
	printf("\t6.ɾ���ڵ�\n");
	printf("\t7.��������\n");
	printf("\t8.�˳�\n");
	printf("\n\t��������Ӧ������(1-8):\t");
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
		fflush(stdin); // ��ֹ�Ƿ�����
		switch(choice)
		{
		case 1: // ����������
			{
				printf("\t������������:");
				scanf("%d", &x);
				fflush(stdin); // ��ֹ�Ƿ�����
				num = InitList_DuL(&L, x);
				if(num == 0)
				{
					printf("\t�����ڴ�ʧ�ܣ�����������...");
					InitList_DuL(&L, x);
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
					L = L->next ;
				}
				break;
			}
		case 3: // ��������
			{
				DestroyList_DuL(L);
				break;
			}
		case 4: // ����ǰ�ڵ�
			{
				printf("\t������Ҫ�����ڵڼ����ڵ�ǰ(��������)��");
				scanf("%d", &i);
				fflush(stdin); // ��ֹ�Ƿ�����
				printf("\t������Ҫ����Ľڵ�����(��������)��");
				scanf("%d", &(q->data));
				fflush(stdin); // ��ֹ�Ƿ�����
				for(i;i>0;i--)
				{
					L = L->next ;
				}
				p = L;
				num = InsertAfterList_DuL(p, q);
				if(num == 0)
				{
					printf("\t����ʧ��!������...");
					InsertAfterList_DuL(p, q);
				}
				printf("\t�ɹ�����ڵ�!");
				break;
			}
		case 5: // �����ڵ�
			{
				printf("\t������Ҫ�����ڵڼ����ڵ��(��������)��");
				scanf("%d", &i);
				fflush(stdin); // ��ֹ�Ƿ�����
				printf("\t������Ҫ����Ľڵ�����(��������)��");
				scanf("%d", &(q->data));
				fflush(stdin); // ��ֹ�Ƿ�����
				for(i;i>0;i--)
				{
					L = L->next ;
				}
				p = L;
				num = InsertAfterList_DuL(p, q);
				if(num == 0)
				{
					printf("\t����ʧ��!������...");
					InsertAfterList_DuL(p, q);
				}
				printf("\t�ɹ�����ڵ�!");
				break;
			}
		case 6: // ɾ���ڵ�
			{
				printf("\t������Ҫɾ���Ľڵ��ǰһ���ڵ������:");
				scanf("%d", &x);
				fflush(stdin); // ��ֹ�Ƿ�����
				while(L->data != x)
				{
					L = L->next ;
				}
				p = L;
				num = DeleteList_DuL(p, q);
				if(num == 0)
				{
					printf("\tɾ��ʧ��!������...");
					DeleteList_DuL(p, q);
				}
				printf("\t�ɹ�ɾ���ڵ�!");
				break;
			}
		case 7: // ��������
			{
				printf("\t��������:");
				TraverseList_DuL(L, visit);
				break;
			}
		default:
            break;
		}
	}
	while(choice != 8);
}