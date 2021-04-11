#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK3\QUEUE\AQueue\Aqueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>

void menu()
{
	printf("\n\n\t˳��洢�ķ��Ͷ���\n\n");
	printf("\t1.��ʼ������\n");
	printf("\t2.���ٶ���\n");
	printf("\t3.�������Ƿ�����\n");
	printf("\t4.�������Ƿ�Ϊ��\n");
	printf("\t5.�鿴��ͷԪ��\n");
	printf("\t6.�����еĳ���\n");
	printf("\t7.���\n");
	printf("\t8.����\n");
	printf("\t9.��ն���\n");
	printf("\t10.��������\n");
	printf("\t11.�˳�\n\n");
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
		printf("\t������ѡ��(����1-11):");
		switch(checkinput())
		{
		case 1://��ʼ������
			{
				InitAQueue(Q);
				break;
			}
		case 2://���ٶ���
			{
				DestoryAQueue(Q);
				break;
			}
		case 3://�������Ƿ�����
			{
				status = IsFullAQueue(Q);
				if(status == 0 && Q->data[Q->front] != NULL && IsEmptyAQueue(Q) != 1)
				{
					printf("\t���л�δ��!\n");
				}
				else if(status)
				{
					printf("\t��������!\n");
				}
				break;
			}
		case 4://�������Ƿ�Ϊ��
			{
				status = IsEmptyAQueue(Q);
				if(status == 0 && Q->data[Q->front] != NULL)
				{
					printf("\t���в�Ϊ��!\n");
				}
				else if(status)
				{
					printf("\t����Ϊ��!\n");
				}
				break;
			}
		case 5://�鿴��ͷԪ��
			{
				e = (void*)malloc(21);
				status = GetHeadAQueue(Q, e);
				break;
			}
		case 6://�����г���
			{
				d = LengthAQueue(Q);
				printf("\t���г���Ϊ��%d\n", d);
				break;
			}
		case 7://���
			{
				checktype(Q);
				break;
			}
		case 8://����
			{
				status = DeAQueue(Q);
				if(status)
				{
					printf("\t���ӳɹ�!\n");
				}
				break;
			}
		case 9://��ն���
			{
				ClearAQueue(Q);
				break;
			}
		case 10://��������
			{
				status = TraverseAQueue(Q, APrint);
				break;
			}
		case 11://�˳�
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