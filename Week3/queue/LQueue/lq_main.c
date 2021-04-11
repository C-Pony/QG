#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK3\QUEUE\LQUEUE\LQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

void menu()
{
	printf("\n\n\t��ʽ�洢�ķ��Ͷ���\n\n");
	printf("\t1.��ʼ������\n");
	printf("\t2.���ٶ���\n");
	printf("\t3.�������Ƿ�Ϊ��\n");
	printf("\t4.�鿴��ͷԪ��\n");
	printf("\t5.�����еĳ���\n");
	printf("\t6.���\n");
	printf("\t7.����\n");
	printf("\t8.��ն���\n");
	printf("\t9.��������\n");
	printf("\t10.�˳�\n\n");
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
		printf("\t������ѡ��(����1-10):");
		switch(checkinput())
		{
		case 1://��ʼ������
			{
				InitLQueue(Q);
				break;
			}
		case 2://���ٶ���
			{
				DestoryLQueue(Q);
				break;
			}
		case 3://�������Ƿ�Ϊ��
			{
				status = IsEmptyLQueue(Q);
				if(status == 0 && Q->front != NULL)
				{
					printf("\t���в�Ϊ��!\n");
				}
				else if(status)
				{
					printf("\t����Ϊ��!\n");
				}
				break;
			}
		case 4://�鿴��ͷԪ��
			{
				e = (void*)malloc(21);
				status = GetHeadLQueue(Q, e);
				break;
			}
		case 5://�����г���
			{
				d = LengthLQueue(Q);
				printf("\t���г���Ϊ��%d\n", d);
				break;
			}
		case 6://���
			{
				data = (void*)malloc(21);
				checktype(data);
				status = EnLQueue(Q, data);
				break;
			}
		case 7://����
			{
				status = DeLQueue(Q);
				if(status)
				{
					printf("\t���ӳɹ�!\n");
				}
				break;
			}
		case 8://��ն���
			{
				ClearLQueue(Q);
				break;
			}
		case 9://��������
			{
				status = TraverseLQueue(Q, LPrint);
				break;
			}
		case 10://�˳�
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