#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK3\QUEUE\AQueue\Aqueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>

void menu()
{
	printf("\n\n\t顺序存储的泛型队列\n\n");
	printf("\t1.初始化队列\n");
	printf("\t2.销毁队列\n");
	printf("\t3.检查队列是否已满\n");
	printf("\t4.检查队列是否为空\n");
	printf("\t5.查看队头元素\n");
	printf("\t6.检测队列的长度\n");
	printf("\t7.入队\n");
	printf("\t8.出队\n");
	printf("\t9.清空队列\n");
	printf("\t10.遍历队列\n");
	printf("\t11.退出\n\n");
}

void main()
{
	int status, d;
	void *e;
	AQueue *Q;
	Q = (AQueue*)malloc(sizeof(AQueue));
	Q->data[0] = NULL;
	Q->front = Q->rear = Q->length =0;
	do
	{
		system("cls");
		menu();
		printf("\t请输入选择(数字1-11):");
		switch(checkinput())
		{
		case 1://初始化队列
			{
				InitAQueue(Q);
				break;
			}
		case 2://销毁队列
			{
				DestoryAQueue(Q);
				break;
			}
		case 3://检查队列是否已满
			{
				status = IsFullAQueue(Q);
				if(status == 0 && Q->data[Q->front] != NULL && IsEmptyAQueue(Q) != 1)
				{
					printf("\t队列还未满!\n");
				}
				else if(status)
				{
					printf("\t队列已满!\n");
				}
				break;
			}
		case 4://检查队列是否为空
			{
				status = IsEmptyAQueue(Q);
				if(status == 0 && Q->data[Q->front] != NULL)
				{
					printf("\t队列不为空!\n");
				}
				else if(status)
				{
					printf("\t队列为空!\n");
				}
				break;
			}
		case 5://查看队头元素
			{
				e = (void*)malloc(21);
				status = GetHeadAQueue(Q, e);
				break;
			}
		case 6://检测队列长度
			{
				d = LengthAQueue(Q);
				printf("\t队列长度为：%d\n", d);
				break;
			}
		case 7://入队
			{
				checktype(Q);
				break;
			}
		case 8://出队
			{
				status = DeAQueue(Q);
				if(status)
				{
					printf("\t出队成功!\n");
				}
				break;
			}
		case 9://清空队列
			{
				ClearAQueue(Q);
				break;
			}
		case 10://遍历队列
			{
				status = TraverseAQueue(Q, APrint);
				break;
			}
		case 11://退出
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