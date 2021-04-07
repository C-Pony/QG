#include"C:\USERS\86135\DESKTOP\QG\CALCULATOR\CALCULATOR\CALCULATOR\calcul.h"
#include<stdio.h>
#include<stdlib.h>

void main()
{
	ElemType init[100], statu, *p=pr, res;
	int suf, j;
	LinkStack *s;
	s = (LinkStack*)malloc(sizeof(StackNode));
	//s->count = 0;
	//s->top = NULL;
	statu = initLStack(s); //初始化链栈
	do
	{
		//system("cls");
		printf("\t四则整数运算计算器\n");
		printf("***请注意：请使用英文输入法输入全角字符！***\n");
		printf("***请注意：目前仅支持个位数以内的计算！***\n");
		printf("请输入要计算的表达式：");
		gets(init);
		printf("后缀表达式为：");
		suf = converInfixExpression(s, init);//转为后缀表达式
		/*for(j=0;pr[j]!='\0';j++)
		{
			printf("%s", p[j]);//判断是否将打印出来的符号按顺序放到了pr数组中
		}*/
		for(j=0;init[j]!='\0';j++)
			{
				init[j] = '\0';//清空数组
			}
		res = CalculSuffixExpression(s);//计算后缀表达式
		printf("答案为：%d\n", res-'0');
		printf("\n请问还要计算下一个表达式嘛？(yes=1,no=0)\n");
		scanf("%d", &statu);
		if(!statu)
		{
			exit(0);
		}
		system("pause");
	}while(1);
}