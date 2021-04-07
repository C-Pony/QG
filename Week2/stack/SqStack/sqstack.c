#include"C:\USERS\86135\DESKTOP\QG\STACK\HEAD\SqStack.h"
#include<stdio.h>
#include<stdlib.h>

//��ʼ��ջ
Status initStack(SqStack *s,int sizes)
{
	if(sizes <= 0)
	{
		printf("\tջ�ĳ��ȱ������0!\n");
		return ERROR;
	}
	else
	{
		s->top = -1;
		s->size = sizes;
		s->elem = (ElemType*)malloc(sizes*sizeof(ElemType));
		printf("\t�ɹ���������Ϊ%d��˳��ջ!\n", sizes);
		return SUCCESS;
	}
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s)
{
	if(s->top == -1 || s->size == 0)
	{
		printf("\tջΪ��!\n");
		return SUCCESS;
	}
	else
	{
		printf("\tջ��Ϊ��!\n"); 
		return ERROR;
	}
}

//�õ�ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e)
{
	if(s->size == 0 || s->top == -1)
	{
		printf("\tջΪ��!��ջ��Ԫ��!\n");
		return ERROR;
	}
	else
	{
		*e = s->elem[s->top];
		printf("\tջ��Ԫ��Ϊ%d!\n", *e);
		return SUCCESS;
	}
}

//���ջ
Status clearStack(SqStack *s)
{
	if(s->size == 0)
	{
		printf("\tջ����Ϊ��!\n");
		return ERROR;
	}
	else
	{
		s->top = -1;
		printf("\tջ�����!\n");
		return SUCCESS;
	}
}

//����ջ
Status destroyStack(SqStack *s)
{
	if(s->elem == NULL)
	{
		printf("\tջ��δ��ʼ��!�޷�����!\n");
		return ERROR;
	}
	else
	{
		free(s->elem);
		s->size = 0;
		s->elem = NULL;
		printf("\tջ������!\n");
		return SUCCESS;
	}
}

//���ջ����
Status stackLength(SqStack *s,int *length)
{
	if(s == NULL || s->size == 0)
	{
		printf("\t���ȳ�ʼ��ջ!\n");
		return ERROR;
	}
	else
	{
		*length = s->top + 1;
		printf("\tջ����Ϊ%d!\n", *length);
		return SUCCESS;
	}
}

//��ջ
Status pushStack(SqStack *s,ElemType data)
{
	if(s->top == s->size -1)
	{
		printf("\tջ����!�޷��ٽ�ջ!\n");
		return ERROR;
	}
	if(s == NULL || s->size == 0)
	{
		printf("\t���ȳ�ʼ��ջ!\n");
		return ERROR;
	}
	s->top++;
	s->elem[s->top] = data;
	printf("\t%d��ѹ��ջ!\n", data);
	return SUCCESS;
}

//��ջ
Status popStack(SqStack *s,ElemType *pdata)
{
	if(s->top == -1 || s->size == 0)
	{
		printf("\tջΪ��!�޷��ٳ�ջ!\n");
		return ERROR;
	}
	*pdata =  s->elem[s->top];
	s->top--;
	printf("\t%d�ѵ���ջ!\n", *pdata);
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