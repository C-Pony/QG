#include"C:\USERS\86135\DESKTOP\QG\STACK\HEAD\SqStack.h"
#include<stdio.h>
#include<stdlib.h>

void menu()
{
	printf("\n\n\t˳��ջADT\n\n");
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
	SqStack *s;
	int *length;
	s = (SqStack*)malloc(sizeof(SqStack));
	s->elem = NULL;
	s->size = s->top = 0;
	do
	{
		system("cls");
		menu();
		printf("\t������ѡ��(����1-9):");
		switch(checkinput())
		{
		case 1://��ʼ��ջ
			{
				printf("\t������Ҫ������ջ�ĳ���:");
				s = (SqStack*)malloc(sizeof(SqStack));
				statu = initStack(s, checkinput());
				break;
			}
		case 2://�ж�ջ�Ƿ�Ϊ��
			{
				statu = isEmptyStack(s);
				break;
			}
		case 3://�õ�ջ��Ԫ��
			{
				e = (ElemType*)malloc(sizeof(ElemType));
				statu = getTopStack(s, e);
				break;
			}
		case 4://���ջ
			{
				statu = clearStack(s);
				break;
			}
		case 5://����ջ
			{
				statu = destroyStack(s);
				break;
			}
		case 6://���ջ����
			{
				length = (int*)malloc(sizeof(int));
				statu = stackLength(s, length);
				break;
			}
		case 7://��ջ
			{
				printf("\t������Ҫ��ջ������:");
				statu = pushStack(s, checkinput());
				break;
			}
		case 8://��ջ
			{
				pdata = (ElemType*)malloc(sizeof(ElemType));
				statu = popStack(s, pdata);
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