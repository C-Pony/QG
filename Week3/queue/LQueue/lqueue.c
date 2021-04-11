#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK3\QUEUE\LQUEUE\LQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

//初始化队列
void InitLQueue(LQueue *Q)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	Q->front = Q->rear = p;
	printf("\t已成功初始化队列!\n");
}

//销毁队列
void DestoryLQueue(LQueue *Q)
{
	int i = 0;
	if(Q->front == NULL)
	{
		printf("\t队列还未初始化!请先初始化队列!\n");
		return;
	}
	if(IsEmptyLQueue(Q))
	{
		printf("\t队列为空!无需再销毁!\n");
		return;
	}
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
	printf("\t队列已销毁!\n");
	return;
}


//检查队列是否为空
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front == NULL)
	{
		printf("\t队列还未初始化!请先初始化队列!\n");
		return FALSE;
	}
	return (Q->front == Q->rear? TRUE: FALSE);
}

//查看队头元素
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->front == NULL)
	{
		printf("\t队列还未初始化!请先初始化队列!\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q))
	{
		printf("\t队列为空!无队头元素!\n");
		return FALSE;
	}
	memcpy(e, Q->front->next->data, 20);
	printf("\t队头元素为：");
	LPrint(e);
	printf("\n");
	return TRUE;
}

//确定队列长度
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

//入队
Status EnLQueue(LQueue *Q, void *data)
{
	Node *p = (Node*)malloc(sizeof(Node));
	if(Q->front == NULL)
	{
		printf("\t队列还未初始化!请先初始化队列!\n");
		return FALSE;
	}
	if(p == NULL)
	{
		printf("\t分配内存失败!\n");
		return FALSE;
	}
	p->data = (Node*)malloc(sizeof(Node));
	memcpy(p->data, data, 20);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	printf("\t数据");
	LPrint(data);
	printf("已入队!\n");
	return TRUE;
}

//检查入队数据类型
void checktype(void *data)
{
	int choice1;
	printf("\t选择你将入队的数据类型：\n");
	printf("\t1.整形 2.浮点型 3.字符型 4.字符串\n\t");
	scanf("%d", &choice1);
	while(choice1 < 1 || choice1 > 4)
	{
		printf("\n\t只能输入区间[1,4]上的整数!请重新输入：");
		scanf("%d", &choice1);
	}
	printf("\t想入队的数据：");
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

//出队操作
Status DeLQueue(LQueue *Q)
{
	void* e = (void*)malloc(21);
	Node *p = (Node*)malloc(sizeof(Node));
	if(IsEmptyLQueue(Q))
	{
		printf("\t队列为空!无法出队!\n");
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

//清空队列
void ClearLQueue(LQueue *Q)
{
	Node *p, *q;
	if(Q->front == NULL)
	{
		printf("\t队列还未初始化!请先初始化队列!\n");
		return ;
	}
	if(IsEmptyLQueue(Q) == 1 && Q->front != NULL)
	{
		printf("\t队列已为空!\n");
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

//遍历队列
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	int i=0;
	Node *p = (Node*)malloc(sizeof(Node));
	if(Q->front == NULL)
	{
		printf("\t队列还未初始化!请先初始化队列!\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q))
	{
		printf("\t队列为空!\n");
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

//操作函数
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
				if(str[i-2] == '1' && str[i-1] == '0')
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


