#include"C:\USERS\86135\DESKTOP\QG\CALCULATOR\CALCULATOR\CALCULATOR\calcul.h"
#include<stdio.h>
#include<stdlib.h>

//����ȫ�ֱ���
ElemType pr[100];/*Ҫ�������ļ���ͷ���壬�����ں�����*/

//�жϷ������ȼ�
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

//����׺���ʽת��Ϊ��׺���ʽ
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
				b = (pr[j-1] - '0')*10 + (a[i] - '0');//��λ���Ĵ洢
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
			statu = pushLStack(s, a[i]);//������ֱ����ջ
		}
		if((a[i] == '+') || (a[i] == '-') || (a[i] == '*') || (a[i] == '/'))
		{
			//if(a[i] == '-')printf("\n��ǰ��'-'�Ƚϵ�ջ�ڷ���Ϊ%c\n", s->top->data);
			while(precedence(a[i]) <= precedence(s->top->data))
			{
				printf("%c", s->top->data);
				pr[j++] = s->top->data;
				statu = popLStack(s, pdata);//a[i]�뵱ǰջ�����űȽϣ����������ȼ������ջ
			}
			statu = pushLStack(s, a[i]);//���ܽ����Σ�a[i]���ն�����ջ
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
			printf(" ��������!\n");
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

//�����׺���ʽ
ElemType CalculSuffixExpression(LinkStack *s)
{
	int i=0, j=0, statu, ret, m, n;
	ElemType *pdata, tur;
	extern ElemType pr[];
	pdata = (ElemType*)malloc(sizeof(ElemType));
	while(pr[i] != '\0')
	{
		if(pr[i] >= '0')//����ֱ�ӽ�ջ
		{
			statu = pushLStack(s, pr[i]);
			if(pr[i] > '9')
			{
				printf("\n��λ��Ϊ%d\n", pr[i]-'0');
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
			statu = pushLStack(s, tur);//������ѹ��ջ
		}
		i++;
	}
	if(s->count == 1 && pr[i] == '\0')
	{
		statu = popLStack(s, pdata);//���ս��
		//if(*pdata > '9')
	}
	return *pdata ;
}