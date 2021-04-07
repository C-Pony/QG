#include"C:\USERS\86135\DESKTOP\QG\CALCULATOR\CALCULATOR\CALCULATOR\calcul.h"
#include<stdio.h>
#include<stdlib.h>

//��ʼ��ջ
Status initLStack(LinkStack *s)
{
	s->top = (StackNode*)malloc(sizeof(StackNode)); 
	s->top->next = NULL;
	s->count = 0;
	s->top->data = 0;
	//printf("\t�ɹ���ʼ����ջ!\n");
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s)
{
	if(s->top == NULL)
	{
		printf("\t��ջ������!���ȳ�ʼ����ջ!\n");
		return ERROR;
	}
	else
	{
		if(s->count == 0)
		{
			printf("\t��ջΪ��!\n");
			return SUCCESS;
		}
		else
		{
			printf("\t��ջ��Ϊ��!\n");
			return ERROR;
		}
	}
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(s->top == NULL)
	{
		printf("\t��ջ������!���ȳ�ʼ����ջ!\n");
		return ERROR;
	}
	if(s->count == 0)
	{
		printf("\t��ջΪ��!��ջ��Ԫ��!\n");
		return ERROR;
	}
	*e = s->top->data ;
	printf("\tջ��Ԫ��Ϊ%c!\n", *e);
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s)
{
	LinkStackPtr base = NULL;
	if(s->count == 0)
	{
		printf("\t��ջ��Ϊ��!�޷����ջ!\n");
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
	printf("\t�ѳɹ������ջ!\n");
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s)
{
	LinkStackPtr base = NULL;
	if(s->top == NULL)
	{
		printf("\t��ջ������!�޷�����ջ!\n");
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
	printf("\t�ѳɹ�������ջ!\n");
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length)
{
	if(s->count == 0 && s->top != NULL)
	{
		printf("\t��ջΪ��!ջ����Ϊ0!\n");
		return ERROR;
	}
	if(s->top == NULL)
	{
		printf("\t��ջ������!���ȳ�ʼ��ջ!\n");
		return ERROR;
	}
	*length = s->count ;
	printf("\t��ջ����Ϊ%d!\n", *length);
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if(s->top == NULL)
	{
		printf("\t��ջ������!���ȳ�ʼ��ջ!\n");
		return ERROR;
	}
	p->data = data;
	p->next = s->top;
	s->count++;
	s->top = p;
	//printf("\t%c��ѹ��ջ!\n", data);
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *pdata)
{
	LinkStackPtr p;
	if(s->top == NULL)
	{
		printf("\t��ջ������!���ȳ�ʼ��ջ!\n");
		return ERROR;
	}
	*pdata = s->top->data;
	//printf("ջ��Ԫ��:%c", s->top->data);
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
	//printf("\t%c�ѵ�����ջ!\n", *pdata);
	return SUCCESS;
}

//���Ƿ�����
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
			printf("\t�������!����������:");
			for(j=0;j<i;j++)
			{
				str[j] = '\0';
			}
		}
	}while(status == ERROR);
	input = str[i-1] - 48;
	return input;
}
