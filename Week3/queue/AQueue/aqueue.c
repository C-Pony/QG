#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK3\QUEUE\AQueue\Aqueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>

void *data;

//��ʼ������
void InitAQueue(AQueue *Q)
{
	int i;
	for(i = 0; i < MAXQUEUE; i++)
		Q->data[i] = (void*)malloc(N*4);
	Q->length = MAXQUEUE;
	Q->front = Q->rear = 0;
	printf("\t�ѳɹ���ʼ������!\n");
}

//���ٶ���
void DestoryAQueue(AQueue *Q)
{
	int i = 0;
	if(Q->data == NULL)
	{
		printf("\t���л�δ��ʼ��!���ȳ�ʼ������!\n");
		return;
	}
	while(i < MAXQUEUE)
	{
		free(Q->data[i++]);
	}
	Q->data[0] = NULL;
	printf("\t����������!\n");
	return;
}

//�������Ƿ�����
Status IsFullAQueue(const AQueue *Q)
{
	if(Q->data == NULL)
	{
		printf("\t���л�δ��ʼ��!���ȳ�ʼ������!\n");
		return FALSE;
	}
	if(IsEmptyAQueue(Q))
	{
		printf("\t����Ϊ��!\n");
		return FALSE;
	}
	return (Q->front == ((Q->rear + 1) % MAXQUEUE)? TRUE: FALSE);
}

//�������Ƿ�Ϊ��
Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->data == NULL)
	{
		printf("\t���л�δ��ʼ��!���ȳ�ʼ������!\n");
		return FALSE;
	}
	return (Q->front == Q->rear? TRUE: FALSE);
}

//�鿴��ͷԪ��
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if(Q->data == NULL)
	{
		printf("\t���л�δ��ʼ��!���ȳ�ʼ������!\n");
		return FALSE;
	}
	if(IsEmptyAQueue(Q))
	{
		printf("\t����Ϊ��!�޶�ͷԪ��!\n");
		return FALSE;
	}
	memcpy(e, Q->data[Q->front], 20);
	printf("\t��ͷԪ��Ϊ��");
	APrint(e);
	printf("\n");
	return TRUE;
}

//ȷ�����г���
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}	

//���
Status EnAQueue(AQueue *Q, void *data)
{
	//void *e = (void*)malloc(21);
	if(Q->data[0] == NULL)
	{
		printf("\t���л�δ��ʼ��!���ȳ�ʼ������!\n");
		return FALSE;
	}
	if(IsFullAQueue(Q) == 1)
	{
		printf("\t��������!�޷������!\n");
		return FALSE;
	}
	if(IsEmptyAQueue(Q))
	{
		memcpy(Q->data[Q->front], data, 20);
		//Q->data[Q->front] = data;
	}
	else
	{
		memcpy(Q->data[Q->rear], data, 20);
		//Q->data[Q->rear] = data;
	}
	Q->rear = (Q->rear + 1) % Q->length;
	printf("\t����%d\n", *(int*)data);
	printf("\t����");
	APrint(data);
	printf("�����!\n");
	return TRUE;
}

//��������������
void checktype(AQueue *Q)
{
	int choice1, status;
	printf("\tѡ���㽫��ӵ��������ͣ�\n");
	printf("\t1.���� 2.������ 3.�ַ��� 4.�ַ���\n\t");
	scanf("%d", &choice1);
	while(choice1 < 1 || choice1 > 4)
	{
		printf("\n\tֻ����������[1,4]�ϵ�����!���������룺");
		scanf("%d", &choice1);
	}
	printf("\t����ӵ����ݣ�");
	fflush(stdin);
	switch(choice1)
	{
	case 1:
		{
			int *data = (int*)malloc(sizeof(int));
			scanf("%d", data);
			printf("\t����%d\n", *data);
			type = '1';
			status = EnAQueue(Q, (void*)data);
			break;
		}
	case 2:
		{
			float *data = (float*)malloc(sizeof(float));
			scanf("%f", data);
			type = '2';
			printf("\t����%f\n", *data);
			status = EnAQueue(Q, (void*)data);
			break;
		}
	case 3:
		{
			char *data = (char*)malloc(sizeof(char));
			scanf("%c", data);
			type = '3';
			printf("\t����%c\n", *data);
			status = EnAQueue(Q, (void*)data);
			break;
		}
	case 4:
		{
			char *data = (char*)malloc(sizeof(char));
			scanf("%s", data);
			type = '4';
			printf("\t����%s\n", data);
			status = EnAQueue(Q, (void*)data);
			break;
		}
	}
}

//���Ӳ���
Status DeAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q))
	{
		printf("\t����Ϊ��!�޷�����!\n");
		return FALSE;
	}
	Q->front = (Q->front + 1) % Q->length ;
	return TRUE;
}

//��ն���
void ClearAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q))
	{
		printf("\t������Ϊ��!\n");
		return;
	}
	Q->front = Q->rear = 0;
}

//��������
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	int i=0;
	if(Q->data == NULL)
	{
		printf("\t���л�δ��ʼ��!���ȳ�ʼ������!\n");
		return FALSE;
	}
	if(IsEmptyAQueue(Q))
	{
		printf("\t����Ϊ��!\n");
		return FALSE;
	}
	while(i < (MAXQUEUE - Q->front +Q->rear) % MAXQUEUE)
	{
		foo(Q->data[Q->front + i]);
		i = (i + 1) % MAXQUEUE;
	}
	return TRUE;
}

//��������
void APrint(void *q)
{
	//strcpy(datatype, q);
	//printf("\t����%c\n", datatype);
	//puts(datatype);
	/*if(sizeof(datatype) == sizeof(int))
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
	return;*/
	void *e = (void*)malloc(21);
	e = q;
	printf("\t����%d\n", *(int*)e);
	if(type = '1')
	{
		printf("\t����!!!\n");
		printf("%d", *(int*)e);
	}
	if(type = '2')
	{
		printf("%lf", *(double*)e);
	}
	if(type = '3')
	{
		printf("%c", *(char*)e);
	}
	if(type = '4')
	{
		printf("%s", (char*)e);
	}
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
				if(str[i-2] == '1' && str[i-1] >= '0' && str[i-1] <= '1')
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

