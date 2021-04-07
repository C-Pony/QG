#include"C:\USERS\86135\DESKTOP\QG\STACK\HEAD\SqStack.h"
#include<stdio.h>
#include<stdlib.h>

//初始化栈
Status initStack(SqStack *s,int sizes)
{
	if(sizes <= 0)
	{
		printf("\t栈的长度必须大于0!\n");
		return ERROR;
	}
	else
	{
		s->top = -1;
		s->size = sizes;
		s->elem = (ElemType*)malloc(sizes*sizeof(ElemType));
		printf("\t成功创建长度为%d的顺序栈!\n", sizes);
		return SUCCESS;
	}
}

//判断栈是否为空
Status isEmptyStack(SqStack *s)
{
	if(s->top == -1 || s->size == 0)
	{
		printf("\t栈为空!\n");
		return SUCCESS;
	}
	else
	{
		printf("\t栈不为空!\n"); 
		return ERROR;
	}
}

//得到栈顶元素
Status getTopStack(SqStack *s,ElemType *e)
{
	if(s->size == 0 || s->top == -1)
	{
		printf("\t栈为空!无栈顶元素!\n");
		return ERROR;
	}
	else
	{
		*e = s->elem[s->top];
		printf("\t栈顶元素为%d!\n", *e);
		return SUCCESS;
	}
}

//清空栈
Status clearStack(SqStack *s)
{
	if(s->size == 0)
	{
		printf("\t栈本就为空!\n");
		return ERROR;
	}
	else
	{
		s->top = -1;
		printf("\t栈已清空!\n");
		return SUCCESS;
	}
}

//销毁栈
Status destroyStack(SqStack *s)
{
	if(s->elem == NULL)
	{
		printf("\t栈还未初始化!无法销毁!\n");
		return ERROR;
	}
	else
	{
		free(s->elem);
		s->size = 0;
		s->elem = NULL;
		printf("\t栈已销毁!\n");
		return SUCCESS;
	}
}

//检测栈长度
Status stackLength(SqStack *s,int *length)
{
	if(s == NULL || s->size == 0)
	{
		printf("\t请先初始化栈!\n");
		return ERROR;
	}
	else
	{
		*length = s->top + 1;
		printf("\t栈长度为%d!\n", *length);
		return SUCCESS;
	}
}

//入栈
Status pushStack(SqStack *s,ElemType data)
{
	if(s->top == s->size -1)
	{
		printf("\t栈已满!无法再进栈!\n");
		return ERROR;
	}
	if(s == NULL || s->size == 0)
	{
		printf("\t请先初始化栈!\n");
		return ERROR;
	}
	s->top++;
	s->elem[s->top] = data;
	printf("\t%d已压入栈!\n", data);
	return SUCCESS;
}

//出栈
Status popStack(SqStack *s,ElemType *pdata)
{
	if(s->top == -1 || s->size == 0)
	{
		printf("\t栈为空!无法再出栈!\n");
		return ERROR;
	}
	*pdata =  s->elem[s->top];
	s->top--;
	printf("\t%d已弹出栈!\n", *pdata);
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