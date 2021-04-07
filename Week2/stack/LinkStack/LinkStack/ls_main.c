#include"C:\USERS\86135\DESKTOP\QG\STACK\HEAD\LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

void menu()
{
	printf("\n\n\t链栈ADT\n\n");
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
	LinkStack *s;
	int *length;
	s = (LinkStack*)malloc(sizeof(StackNode));
	s->count = 0;
	s->top = NULL;
	do
	{
		menu();
		printf("\t请输入选择(数字1-9):");
		switch(checkinput())
		{
		case 1://初始化栈
			{
				s = (LinkStack*)malloc(sizeof(StackNode));
				statu = initLStack(s);
				break;
			}
		case 2://判断栈是否为空
			{
				statu = isEmptyLStack(s);
				break;
			}
		case 3://得到栈顶元素
			{
				e = (ElemType*)malloc(sizeof(ElemType));
				statu = getTopLStack(s, e);
				break;
			}
		case 4://清空栈
			{
				statu = clearLStack(s);
				break;
			}
		case 5://销毁栈
			{
				statu = destroyLStack(s);
				break;
			}
		case 6://检测栈长度
			{
				length = (int*)malloc(sizeof(int));
				statu = LStackLength(s, length);
				break;
			}
		case 7://入栈
			{
				printf("\t请输入要入栈的数据:");
				statu = pushLStack(s, checkinput());
				break;
			}
		case 8://出栈
			{
				pdata = (ElemType*)malloc(sizeof(ElemType));
				statu = popLStack(s, pdata);
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