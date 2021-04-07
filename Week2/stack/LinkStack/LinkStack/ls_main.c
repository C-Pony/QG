#include"C:\USERS\86135\DESKTOP\QG\STACK\HEAD\LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

void menu()
{
	printf("\n\n\t��ջADT\n\n");
	printf("\t1.��ʼ��ջ\n");
	printf("\t2.�ж�ջ�Ƿ�Ϊ��\n");
	printf("\t3.��ӡջ��Ԫ��\n");
	printf("\t4.���ջ\n");
	printf("\t5.����ջ\n");
	printf("\t6.���ջ�ĳ���\n");
	printf("\t7.��ջ\n");
	printf("\t8.��ջ\n");
	printf("\t9.�˳�\n\n");
}

void main()
{
	ElemType statu, *e, *pdata;
	LinkStack *s;
	int *length;
	s = (LinkStack*)malloc(sizeof(StackNode));
	s->count = 0;
	s->top = NULL;
	do
	{
		menu();
		printf("\t������ѡ��(����1-9):");
		switch(checkinput())
		{
		case 1://��ʼ��ջ
			{
				s = (LinkStack*)malloc(sizeof(StackNode));
				statu = initLStack(s);
				break;
			}
		case 2://�ж�ջ�Ƿ�Ϊ��
			{
				statu = isEmptyLStack(s);
				break;
			}
		case 3://�õ�ջ��Ԫ��
			{
				e = (ElemType*)malloc(sizeof(ElemType));
				statu = getTopLStack(s, e);
				break;
			}
		case 4://���ջ
			{
				statu = clearLStack(s);
				break;
			}
		case 5://����ջ
			{
				statu = destroyLStack(s);
				break;
			}
		case 6://���ջ����
			{
				length = (int*)malloc(sizeof(int));
				statu = LStackLength(s, length);
				break;
			}
		case 7://��ջ
			{
				printf("\t������Ҫ��ջ������:");
				statu = pushLStack(s, checkinput());
				break;
			}
		case 8://��ջ
			{
				pdata = (ElemType*)malloc(sizeof(ElemType));
				statu = popLStack(s, pdata);
				break;
			}
		case 9://�˳�
			{
				exit(0);
				break;
			}
		default:
                printf("\tNo such option.\n");
		}
		system("pause");
	}while(1);
}