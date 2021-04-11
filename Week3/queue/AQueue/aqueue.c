#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK3\QUEUE\AQueue\Aqueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>

void *data;

//初始化队列
void InitAQueue(AQueue *Q)
{
	int i;
	for(i = 0; i < MAXQUEUE; i++)
		Q->data[i] = (void*)malloc(N*4);
	Q->length = MAXQUEUE;
	Q->front = Q->rear = 0;
	printf("\t已成功初始化队列!\n");
}

//销毁队列
void DestoryAQueue(AQueue *Q)
{
	int i = 0;
	if(Q->data == NULL)
	{
		printf("\t队列还未初始化!请先初始化队列!\n");
		return;
	}
	while(i < MAXQUEUE)
	{
		free(Q->data[i++]);
	}
	Q->data[0] = NULL;
	printf("\t队列已销毁!\n");
	return;
}

//检查队列是否已满
Status IsFullAQueue(const AQueue *Q)
{
	if(Q->data == NULL)
	{
		printf("\t队列还未初始化!请先初始化队列!\n");
		return FALSE;
	}
	if(IsEmptyAQueue(Q))
	{
		printf("\t队列为空!\n");
		return FALSE;
	}
	return (Q->front == ((Q->rear + 1) % MAXQUEUE)? TRUE: FALSE);
}

//检查队列是否为空
Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->data == NULL)
	{
		printf("\t队列还未初始化!请先初始化队列!\n");
		return FALSE;
	}
	return (Q->front == Q->rear? TRUE: FALSE);
}

//查看队头元素
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if(Q->data == NULL)
	{
		printf("\t队列还未初始化!请先初始化队列!\n");
		return FALSE;
	}
	if(IsEmptyAQueue(Q))
	{
		printf("\t队列为空!无队头元素!\n");
		return FALSE;
	}
	memcpy(e, Q->data[Q->front], 20);
	printf("\t队头元素为：");
	APrint(e);
	printf("\n");
	return TRUE;
}

//确定队列长度
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}	

//入队
Status EnAQueue(AQueue *Q, void *data)
{
	//void *e = (void*)malloc(21);
	if(Q->data[0] == NULL)
	{
		printf("\t队列还未初始化!请先初始化队列!\n");
		return FALSE;
	}
	if(IsFullAQueue(Q) == 1)
	{
		printf("\t队列已满!无法再入队!\n");
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
	printf("\t测试%d\n", *(int*)data);
	printf("\t数据");
	APrint(data);
	printf("已入队!\n");
	return TRUE;
}

//检查入队数据类型
void checktype(AQueue *Q)
{
	int choice1, status;
	printf("\t选择你将入队的数据类型：\n");
	printf("\t1.整形 2.浮点型 3.字符型 4.字符串\n\t");
	scanf("%d", &choice1);
	while(choice1 < 1 || choice1 > 4)
	{
		printf("\n\t只能输入区间[1,4]上的整数!请重新输入：");
		scanf("%d", &choice1);
	}
	printf("\t想入队的数据：");
	fflush(stdin);
	switch(choice1)
	{
	case 1:
		{
			int *data = (int*)malloc(sizeof(int));
			scanf("%d", data);
			printf("\t测试%d\n", *data);
			type = '1';
			status = EnAQueue(Q, (void*)data);
			break;
		}
	case 2:
		{
			float *data = (float*)malloc(sizeof(float));
			scanf("%f", data);
			type = '2';
			printf("\t测试%f\n", *data);
			status = EnAQueue(Q, (void*)data);
			break;
		}
	case 3:
		{
			char *data = (char*)malloc(sizeof(char));
			scanf("%c", data);
			type = '3';
			printf("\t测试%c\n", *data);
			status = EnAQueue(Q, (void*)data);
			break;
		}
	case 4:
		{
			char *data = (char*)malloc(sizeof(char));
			scanf("%s", data);
			type = '4';
			printf("\t测试%s\n", data);
			status = EnAQueue(Q, (void*)data);
			break;
		}
	}
}

//出队操作
Status DeAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q))
	{
		printf("\t队列为空!无法出队!\n");
		return FALSE;
	}
	Q->front = (Q->front + 1) % Q->length ;
	return TRUE;
}

//清空队列
void ClearAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q))
	{
		printf("\t队列已为空!\n");
		return;
	}
	Q->front = Q->rear = 0;
}

//遍历队列
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	int i=0;
	if(Q->data == NULL)
	{
		printf("\t队列还未初始化!请先初始化队列!\n");
		return FALSE;
	}
	if(IsEmptyAQueue(Q))
	{
		printf("\t队列为空!\n");
		return FALSE;
	}
	while(i < (MAXQUEUE - Q->front +Q->rear) % MAXQUEUE)
	{
		foo(Q->data[Q->front + i]);
		i = (i + 1) % MAXQUEUE;
	}
	return TRUE;
}

//操作函数
void APrint(void *q)
{
	//strcpy(datatype, q);
	//printf("\t测试%c\n", datatype);
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
	printf("\t测试%d\n", *(int*)e);
	if(type = '1')
	{
		printf("\t测试!!!\n");
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

//检查非法输入
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
			printf("\t输入错误!请重新输入:");
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

