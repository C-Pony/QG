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
	statu = initLStack(s); //��ʼ����ջ
	do
	{
		//system("cls");
		printf("\t�����������������\n");
		printf("***��ע�⣺��ʹ��Ӣ�����뷨����ȫ���ַ���***\n");
		printf("***��ע�⣺Ŀǰ��֧�ָ�λ�����ڵļ��㣡***\n");
		printf("������Ҫ����ı��ʽ��");
		gets(init);
		printf("��׺���ʽΪ��");
		suf = converInfixExpression(s, init);//תΪ��׺���ʽ
		/*for(j=0;pr[j]!='\0';j++)
		{
			printf("%s", p[j]);//�ж��Ƿ񽫴�ӡ�����ķ��Ű�˳��ŵ���pr������
		}*/
		for(j=0;init[j]!='\0';j++)
			{
				init[j] = '\0';//�������
			}
		res = CalculSuffixExpression(s);//�����׺���ʽ
		printf("��Ϊ��%d\n", res-'0');
		printf("\n���ʻ�Ҫ������һ�����ʽ�(yes=1,no=0)\n");
		scanf("%d", &statu);
		if(!statu)
		{
			exit(0);
		}
		system("pause");
	}while(1);
}