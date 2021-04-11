#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK3\QUEUE\LQUEUE\LQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

void menu()
{
	printf("\n\n\t链式存储的泛型队列\n\n");
	printf("\t1.初始化队列\n");
	printf("\t2.销毁队列\n");
	printf("\t3.检查队列是否为空\n");
	printf("\t4.查看队头元素\n");
	printf("\t5.检测队列的长度\n");
	printf("\t6.入队\n");
	printf("\t7.出队\n");
	printf("\t8.清空队列\n");
	printf("\t9.遍历队列\n");
	printf("\t10.退出\n\n");
}

void main()
{
	int status, d;
	void *e, *data;
	LQueue *Q;
	Q = (LQueue*)malloc(sizeof(LQueue));
	Q->front = Q->rear = NULL;
	Q->length = 0;
	do
	{
		system("cls");
		menu();
		printf("\t请输入选择(数字1-10):");
		switch(checkinput())
		{
		case 1://初始化队列
			{
				InitLQueue(Q);
				break;
			}
		case 2://销毁队列
			{
				DestoryLQueue(Q);
				break;
			}
		case 3://检查队列是否为空
			{
				status = IsEmptyLQueue(Q);
				if(status == 0 && Q->front != NULL)
				{
					printf("\t队列不为空!\n");
				}
				else if(status)
				{
					printf("\t队列为空!\n");
				}
				break;
			}
		case 4://查看队头元素
			{
				e = (void*)malloc(21);
				status = GetHeadLQueue(Q, e);
				break;
			}
		case 5://检测队列长度
			{
				d = LengthLQueue(Q);
				printf("\t队列长度为：%d\n", d);
				break;
			}
		case 6://入队
			{
				data = (void*)malloc(21);
				checktype(data);
				status = EnLQueue(Q, data);
				break;
			}
		case 7://出队
			{
				status = DeLQueue(Q);
				if(status)
				{
					printf("\t出队成功!\n");
				}
				break;
			}
		case 8://清空队列
			{
				ClearLQueue(Q);
				break;
			}
		case 9://遍历队列
			{
				status = TraverseLQueue(Q, LPrint);
				break;
			}
		case 10://退出
			{
				exit(0);
				break;
			}
		default:
                printf("\tNo such option.\n");
		}
		system("pause");
	}while(1);
}