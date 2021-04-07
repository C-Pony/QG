#include"C:\USERS\86135\DESKTOP\QG\STACK\HEAD\SqStack.h"
#include<stdio.h>
#include<stdlib.h>

void menu()
{
	printf("\n\n\t顺序栈ADT\n\n");
	printf("\t1.初始化栈\n");
	printf("\t2.判断栈是否为空\n");
	printf("\t3.打印栈顶元素\n");
	printf("\t4.清空栈\n");
	printf("\t5.销毁栈\n");
	printf("\t6.检测栈的长度\n");
	printf("\t7.入栈\n");
	printf("\t8.出栈\n");
	printf("\t9.退出\n\n");
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
		printf("\t请输入选择(数字1-9):");
		switch(checkinput())
		{
		case 1://初始化栈
			{
				printf("\t请输入要创建的栈的长度:");
				s = (SqStack*)malloc(sizeof(SqStack));
				statu = initStack(s, checkinput());
				break;
			}
		case 2://判断栈是否为空
			{
				statu = isEmptyStack(s);
				break;
			}
		case 3://得到栈顶元素
			{
				e = (ElemType*)malloc(sizeof(ElemType));
				statu = getTopStack(s, e);
				break;
			}
		case 4://清空栈
			{
				statu = clearStack(s);
				break;
			}
		case 5://销毁栈
			{
				statu = destroyStack(s);
				break;
			}
		case 6://检测栈长度
			{
				length = (int*)malloc(sizeof(int));
				statu = stackLength(s, length);
				break;
			}
		case 7://入栈
			{
				printf("\t请输入要入栈的数据:");
				statu = pushStack(s, checkinput());
				break;
			}
		case 8://出栈
			{
				pdata = (ElemType*)malloc(sizeof(ElemType));
				statu = popStack(s, pdata);
				break;
			}
		case 9://退出
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