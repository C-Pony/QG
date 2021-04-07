#include"C:\USERS\86135\DESKTOP\QG\CALCULATOR\CALCULATOR\CALCULATOR\calcul.h"
#include<stdio.h>
#include<stdlib.h>

//初始化栈
Status initLStack(LinkStack *s)
{
	s->top = (StackNode*)malloc(sizeof(StackNode)); 
	s->top->next = NULL;
	s->count = 0;
	s->top->data = 0;
	//printf("\t成功初始化链栈!\n");
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s)
{
	if(s->top == NULL)
	{
		printf("\t链栈不存在!请先初始化链栈!\n");
		return ERROR;
	}
	else
	{
		if(s->count == 0)
		{
			printf("\t链栈为空!\n");
			return SUCCESS;
		}
		else
		{
			printf("\t链栈不为空!\n");
			return ERROR;
		}
	}
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(s->top == NULL)
	{
		printf("\t链栈不存在!请先初始化链栈!\n");
		return ERROR;
	}
	if(s->count == 0)
	{
		printf("\t链栈为空!无栈顶元素!\n");
		return ERROR;
	}
	*e = s->top->data ;
	printf("\t栈顶元素为%c!\n", *e);
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack *s)
{
	LinkStackPtr base = NULL;
	if(s->count == 0)
	{
		printf("\t链栈已为空!无法清空栈!\n");
		return ERROR;
	}
	base = s->top;
	s->count = 0;
	while(s->top->next)
	{
		s->top = s->top->next;
		free(base);
		base = s->top;
	}
	s->top->data = 0;
	printf("\t已成功清空链栈!\n");
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack *s)
{
	LinkStackPtr base = NULL;
	if(s->top == NULL)
	{
		printf("\t链栈不存在!无法销毁栈!\n");
		return ERROR;
	}
	base = s->top;
	s->count = 0;
	while(s->top)
	{
		s->top = s->top->next;
		free(base);
		base = s->top;
	}
	printf("\t已成功销毁链栈!\n");
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length)
{
	if(s->count == 0 && s->top != NULL)
	{
		printf("\t链栈为空!栈长度为0!\n");
		return ERROR;
	}
	if(s->top == NULL)
	{
		printf("\t链栈不存在!请先初始化栈!\n");
		return ERROR;
	}
	*length = s->count ;
	printf("\t链栈长度为%d!\n", *length);
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if(s->top == NULL)
	{
		printf("\t链栈不存在!请先初始化栈!\n");
		return ERROR;
	}
	p->data = data;
	p->next = s->top;
	s->count++;
	s->top = p;
	//printf("\t%c已压入栈!\n", data);
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *pdata)
{
	LinkStackPtr p;
	if(s->top == NULL)
	{
		printf("\t链栈不存在!请先初始化栈!\n");
		return ERROR;
	}
	*pdata = s->top->data;
	//printf("栈顶元素:%c", s->top->data);
	p = s->top;
	if(s->top->next == NULL)
	{
		s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	}
	else
	{
		s->top = s->top->next ;
	}
	free(p);
	s->count--;
	//printf("\t%c已弹出链栈!\n", *pdata);
	return SUCCESS;
}

//检查非法输入
int checkinput()
{
	int i=0, j=0, input=0, status;
	char str[100];
	do
	{
		scanf("%s", str);
		fflush(stdin);
		status = SUCCESS;
		for(i=0;str[i]!='\0';)
		{
			i++;
		}
		if(i==1)
		{
			if(str[i-1] <= '0' || str[i-1] > '9')
			{
				status = ERROR;
			}
			else status = SUCCESS;
		}
		else status = ERROR;
		if(status == ERROR)
		{
			printf("\t输入错误!请重新输入:");
			for(j=0;j<i;j++)
			{
				str[j] = '\0';
			}
		}
	}while(status == ERROR);
	input = str[i-1] - 48;
	return input;
}
