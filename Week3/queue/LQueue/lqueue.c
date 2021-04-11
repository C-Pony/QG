#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK3\QUEUE\LQUEUE\LQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

//��ʼ������
void InitLQueue(LQueue *Q)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	Q->front = Q->rear = p;
	printf("\t�ѳɹ���ʼ������!\n");
}

//���ٶ���
void DestoryLQueue(LQueue *Q)
{
	int i = 0;
	if(Q->front == NULL)
	{
		printf("\t���л�δ��ʼ��!���ȳ�ʼ������!\n");
		return;
	}
	if(IsEmptyLQueue(Q))
	{
		printf("\t����Ϊ��!����������!\n");
		return;
	}
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
	printf("\t����������!\n");
	return;
}


//�������Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front == NULL)
	{
		printf("\t���л�δ��ʼ��!���ȳ�ʼ������!\n");
		return FALSE;
	}
	return (Q->front == Q->rear? TRUE: FALSE);
}

//�鿴��ͷԪ��
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->front == NULL)
	{
		printf("\t���л�δ��ʼ��!���ȳ�ʼ������!\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q))
	{
		printf("\t����Ϊ��!�޶�ͷԪ��!\n");
		return FALSE;
	}
	memcpy(e, Q->front->next->data, 20);
	printf("\t��ͷԪ��Ϊ��");
	LPrint(e);
	printf("\n");
	return TRUE;
}

//ȷ�����г���
int LengthLQueue(LQueue *Q)
{
	int length;
	Node *p = (Node*)malloc(sizeof(Node));
	p = Q->front;
	for(length=0;p != Q->rear;length++)
	{
		p = p->next ; 
	}
	return length;
}	

//���
Status EnLQueue(LQueue *Q, void *data)
{
	Node *p = (Node*)malloc(sizeof(Node));
	if(Q->front == NULL)
	{
		printf("\t���л�δ��ʼ��!���ȳ�ʼ������!\n");
		return FALSE;
	}
	if(p == NULL)
	{
		printf("\t�����ڴ�ʧ��!\n");
		return FALSE;
	}
	p->data = (Node*)malloc(sizeof(Node));
	memcpy(p->data, data, 20);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	printf("\t����");
	LPrint(data);
	printf("�����!\n");
	return TRUE;
}

//��������������
void checktype(void *data)
{
	int choice1;
	printf("\tѡ���㽫��ӵ��������ͣ�\n");
	printf("\t1.���� 2.������ 3.�ַ��� 4.�ַ���\n\t");
	scanf("%d", &choice1);
	while(choice1 < 1 || choice1 > 4)
	{
		printf("\n\tֻ����������[1,4]�ϵ�����!���������룺");
		scanf("%d", &choice1);
	}
	printf("\t����ӵ����ݣ�");
	switch(choice1)
	{
	case 1:
		{
			scanf("%d", data);
			type = '1';
			break;
		}
	case 2:
		{
			scanf("%lf", data);
			type = '2';
			break;
		}
	case 3:
		{
			scanf("%c", data);
			type = '3';
			break;
		}
	case 4:
		{
			scanf("%s", data);
			type = '4';
			break;
		}
	}
}

//���Ӳ���
Status DeLQueue(LQueue *Q)
{
	void* e = (void*)malloc(21);
	Node *p = (Node*)malloc(sizeof(Node));
	if(IsEmptyLQueue(Q))
	{
		printf("\t����Ϊ��!�޷�����!\n");
		return FALSE;
	}
	p = Q->front->next ;
	e = p->data ;
	Q->front->next = p->next ;
	if(p == Q->rear)
		Q->rear = Q->front ;
	free(p);
	return TRUE;
}

//��ն���
void ClearLQueue(LQueue *Q)
{
	Node *p, *q;
	if(Q->front == NULL)
	{
		printf("\t���л�δ��ʼ��!���ȳ�ʼ������!\n");
		return ;
	}
	if(IsEmptyLQueue(Q) == 1 && Q->front != NULL)
	{
		printf("\t������Ϊ��!\n");
		return;
	}
	Q->rear = Q->front;
	p = Q->front->next;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	return;
}

//��������
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	int i=0;
	Node *p = (Node*)malloc(sizeof(Node));
	if(Q->front == NULL)
	{
		printf("\t���л�δ��ʼ��!���ȳ�ʼ������!\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q))
	{
		printf("\t����Ϊ��!\n");
		return FALSE;
	}
	p = Q->front->next;
	printf("\t");
	while(p != NULL)
	{
		if(i % 5 == 0) printf("\n");
		foo(p->data);
		p = p->next ;
		i++;
	}
	printf("\n");
	return TRUE;
}

//��������
void LPrint(void *q)
{
	strcpy(datatype, q);
	if(sizeof(datatype) == sizeof(int))
	{
		printf("%d", *(int*)q);
		return;
	}
	if(sizeof(datatype) == sizeof(double))
	{
		printf("%lf", *(double*)q);
		return;
	}
	if(sizeof(datatype) == sizeof(char))
	{
		printf("%c", *(char*)q);
		return;
	}
	printf("%s", (char*)q);
	return;
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
		status = TRUE;
		for(i=0;str[i]!='\0';)
		{
			i++;
		}
		if(i==1)
		{
			if(str[i-1] <= '0' || str[i-1] > '9')
			{
				status = FALSE;
			}
			else status = TRUE;
		}
		else if(i==2)
			{
				if(str[i-2] == '1' && str[i-1] == '0')
				{
					status = TRUE;
				}
				else status = FALSE;
			}
			else status = FALSE;
		if(status == FALSE)
		{
			printf("\t�������!����������:");
			for(j=0;j<i;j++)
			{
				str[j] = '\0';
			}
		}
	}while(status == FALSE);
	if(i==1)
	{
		input = str[i-1] - 48;
	}
	if(i==2)
	{
		input = (str[i-2] - 48)*10 + (str[i-1] - 48);
	}
	return input;
}


