#include"C:\USERS\86135\DESKTOP\QG\CALCULATOR\CALCULATOR\CALCULATOR\calcul.h"
#include<stdio.h>
#include<stdlib.h>

//定义全局变量
ElemType pr[100];/*要在整个文件开头定义，不能在函数内*/

//判断符号优先级
int precedence(char a)
{
	int ret=0;
	if(a == '+')
	{
		ret = 2;
	}
	if(a == '-')
	{
		ret = 2;
	}
	if(a == '*')
	{
		ret = 3;
	}
	if(a == '/')
	{
		ret = 3;
	}
	
	return ret;
}

//将中缀表达式转化为后缀表达式
ElemType converInfixExpression(LinkStack *s, ElemType a[])
{
	ElemType *pdata;
	int i=0, j=0, statu, b=0;
	pdata = (ElemType*)malloc(sizeof(ElemType));
	while(a[i] !='\0')
	{
		if(a[i] >= '0')
		{
			if(a[i-1] >= '0')
			{
				b = (pr[j-1] - '0')*10 + (a[i] - '0');//多位数的存储
				printf("%c", a[i]);
				pr[j-1] = b + '0';
			}
			else
			{
				printf("%c", a[i]);
				pr[j++] = a[i];
			}
		}
		if(a[i] == '(')
		{
			statu = pushLStack(s, a[i]);//左括号直接入栈
		}
		if((a[i] == '+') || (a[i] == '-') || (a[i] == '*') || (a[i] == '/'))
		{
			//if(a[i] == '-')printf("\n当前与'-'比较的栈内符号为%c\n", s->top->data);
			while(precedence(a[i]) <= precedence(s->top->data))
			{
				printf("%c", s->top->data);
				pr[j++] = s->top->data;
				statu = popLStack(s, pdata);//a[i]与当前栈顶符号比较，若后者优先级高则出栈
			}
			statu = pushLStack(s, a[i]);//不管结果如何，a[i]最终都将进栈
		}
		if(a[i] == ')')
		{
			while(s->top->data != '(')
			{
				printf("%c", s->top->data);
				pr[j++] = s->top->data;
				statu = popLStack(s, pdata);
			}
			while(s->top->data == '(')
			{
				statu = popLStack(s, pdata);
			}
		}
		if(a[i] == ' ')
		{
			break;
		}
		/*else
		{
			printf(" 输入有误!\n");
		}*/
		i++;
	}
	while(((s->count) > 0) && (a[i] == '\0'))
	{
		printf("%c", s->top->data);
		pr[j++] = s->top->data;
		statu = popLStack(s, pdata);
	}
	pr[j] = '\0';
	return 0;
}

//计算后缀表达式
ElemType CalculSuffixExpression(LinkStack *s)
{
	int i=0, j=0, statu, ret, m, n;
	ElemType *pdata, tur;
	extern ElemType pr[];
	pdata = (ElemType*)malloc(sizeof(ElemType));
	while(pr[i] != '\0')
	{
		if(pr[i] >= '0')//数字直接进栈
		{
			statu = pushLStack(s, pr[i]);
			if(pr[i] > '9')
			{
				printf("\n多位数为%d\n", pr[i]-'0');
			}
		}
		if((pr[i] == '+') || (pr[i] == '-') || (pr[i] == '*') || (pr[i] == '/'))
		{
			statu = popLStack(s, pdata);
			m = *pdata - '0';
			statu = popLStack(s, pdata);
			n = *pdata - '0';
			switch(pr[i])
			{
			case '+':
				{
					ret = m + n;
					break;
				}
			case '-':
				{
					ret = n - m;
					break;
				}
			case '*':
				{
					ret = m * n;
					break;
				}
			case '/':
				{
					ret = n / m;
					break;
				}
			}
			tur = ret+'0';
			statu = pushLStack(s, tur);//运算结果压入栈
		}
		i++;
	}
	if(s->count == 1 && pr[i] == '\0')
	{
		statu = popLStack(s, pdata);//最终结果
		//if(*pdata > '9')
	}
	return *pdata ;
}