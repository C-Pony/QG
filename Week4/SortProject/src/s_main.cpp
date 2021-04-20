#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK4\SORTPROJECT\INC\qgsort.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("\n\t\t���������㷨Ч�ʲ��Գ���\n\n");
	printf("\t����������ε������������ڲ������������㷨��\n");
	printf("\t1��10000\n");
	printf("\t2��50000\n");
	printf("\t3��200000\n");
	printf("\t\t��������\n");
	printf("\t4����ɫ����(ֻ��0��1��2Ԫ��)\n");
	printf("\t5����һ�������������ҵ���K��/С����\n");
	printf("\t6���˳�\n");
	printf("\t����������ѡ��");
}

//�����������д���ļ���
void randomNumGenerator(int n)
{
	int *a = (int *)malloc(n* sizeof(int));
	int i;
	FILE *pf = NULL;//�����ļ�ָ��
	srand((unsigned)time(NULL));//��������
	if(n == 10000)//��ָ��Ŀ¼�´���txt�ļ�
	{
		pf = fopen("C:\\Users\\86135\\Desktop\\QGDataStructure\\Week4\\SortProject\\data1.txt", "a");
	}
	if(n == 50000)
	{
		pf = fopen("C:\\Users\\86135\\Desktop\\QGDataStructure\\Week4\\SortProject\\data2.txt", "a");
	}
	if(n == 200000)
	{
		pf = fopen("C:\\Users\\86135\\Desktop\\QGDataStructure\\Week4\\SortProject\\data3.txt", "a");
	}
	for(i=0; i<n; i++)
	{
		a[i] = rand() % MAX;
		fprintf(pf, "%d	", a[i]);//�������д���ļ�
	}
	fclose(pf);//�ر��ļ�
	free(a);
	a = NULL;
}

//�ж��Ƿ�ɹ�����
int isSorted(int *a, int size)
{
	int i;
	for(i=0; i<size-1; i++)
	{
		if(a[i+1] < a[i])
		{
			return ERROR;
		}
	}
	return SUCCESS;
}

//���ɴ���������
void newarray(int *a, int n)
{
	int i;
	FILE *fw;
	if(n == 10000)//�򿪶�Ӧ�ļ�
	{
		fw = fopen("C:\\Users\\86135\\Desktop\\QGDataStructure\\Week4\\SortProject\\data1.txt", "r");
	}
	if(n == 50000)
	{
		fw = fopen("C:\\Users\\86135\\Desktop\\QGDataStructure\\Week4\\SortProject\\data2.txt", "r");
	}
	if(n == 200000)
	{
		fw = fopen("C:\\Users\\86135\\Desktop\\QGDataStructure\\Week4\\SortProject\\data3.txt", "r");
	}
	printf("�������������ݣ�\t");
	for(i=0; i<n; i++)
	{
		fscanf(fw, "%d", &a[i]);//��ȡ�ļ����ݣ������ո�ͻ���ֹͣ��
		printf("%5d  ", a[i]);
	}
	//printf("\t����\t");
	fclose(fw);
}

//����ÿ�������㷨������ʱ��
void timer(int size)
{
	int *a = (int *)malloc(size* sizeof(int));
	int i;


	/*system("cls");
	printf("\n\t�鲢����\n");
	{
		clock_t start_time, end_time;
		newarray(a, size);
		printf("\t����\t");
		start_time = clock();
		{
			MergeSort(a, 0, size-1, a);
		}
		end_time = clock();
		printf("\n�鲢��������ʱ��Ϊ��%lfms\n", static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
		printf("SORTED %s!", isSorted(a, size) == SUCCESS ? "SUCCESS":"ERROR");
		printf("\n");
		system("pause");
	}*/


	system("cls");
	printf("\n\t��������\n");
	{
		clock_t start_time, end_time;
		newarray(a, size);
		start_time = clock();
		{
			insertSort(a, size);
		}
		end_time = clock();
		printf("\n������������ʱ��Ϊ��%lfms\n", static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
		printf("SORTED %s!", isSorted(a, size) == SUCCESS ? "SUCCESS":"ERROR");
		printf("\n");
		system("pause");
	}

	
	system("cls");
	printf("\n\t�������򣨵ݹ�棩\n");
	{
		clock_t start_time, end_time;
		newarray(a, size);
		start_time = clock();
		{
			QuickSort_Recursion(a, 0, size-1);
		}
		end_time = clock();
		printf("\n�������򣨵ݹ�棩����ʱ��Ϊ��%lfms\n", static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
		printf("SORTED %s!", isSorted(a, size) == SUCCESS ? "SUCCESS":"ERROR");
		printf("\n");
		system("pause");
	}


	system("cls");
	printf("\n\t�������򣨷ǵݹ�棩\n");
	{
		clock_t start_time, end_time;
		newarray(a, size);
		start_time = clock();
		{
			QuickSort(a, size);
		}
		end_time = clock();
		printf("\n�������򣨷ǵݹ�棩������ʱ��Ϊ��%lfms\n", static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
		printf("SORTED %s!", isSorted(a, size) == SUCCESS ? "SUCCESS":"ERROR");
		printf("\n");
		system("pause");
	}


	system("cls");
	printf("\n\t��������\n");
	{
		clock_t start_time, end_time;
		int max=a[0];
		newarray(a, size);
		start_time = clock();
		{
			for(i=0; i<size; i++)
			{
				if(a[i] > max)
					max = a[i];
			}
			CountSort(a, size, max);
		}
		end_time = clock();
		printf("\n�������������ʱ��Ϊ��%lfms\n", static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
		printf("SORTED %s!", isSorted(a, size) == SUCCESS ? "SUCCESS":"ERROR");
		printf("\n");
		system("pause");
	}


	system("cls");
	printf("\n\t������������\n");
	{
		clock_t start_time, end_time;
		newarray(a, size);
		start_time = clock();
		{
			RadixCountSort(a, size);
		}
		end_time = clock();
		printf("\n�����������������ʱ��Ϊ��%lfms\n", static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
		printf("SORTED %s!", isSorted(a, size) == SUCCESS ? "SUCCESS":"ERROR");
		printf("\n");
	}

	free(a);
}

void main()
{
	int n;
	//��Ҫ����ʱȡ��ע��
	/*randomNumGenerator(10000);//����1���������д���ļ�
	randomNumGenerator(50000);//����5���������д���ļ�
	randomNumGenerator(200000);//����20���������д���ļ�*/
	do
	{
		system("cls");
		menu();
		n = checkinput();
		switch(n)
		{
		case 1:
			{
				timer(10000);
				break;
			}
		case 2:
			{
				timer(50000);
				break;
			}
		case 3:
			{
				timer(200000);
				break;
			}
		case 4:
			{
				system("cls");
				printf("\n\t��ɫ����\n");
				{
					clock_t start_time, end_time;
					int i, *a, size;
					printf("���������鳤�ȣ���������");
					scanf("%d", &size);
					a = (int *)malloc(size * sizeof(int));
					printf("������ֻ��0��1��2����Ԫ�ص����飺");
					for(i=0; i<size; i++)
					{
						scanf("%d", &a[i]);
					}
					start_time = clock();
					{
						ColorSort(a, size);
					}
					end_time = clock();
					printf("����ʱ��Ϊ��%lfms\n", static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
					printf("SORTED %s!", isSorted(a, size) == SUCCESS ? "SUCCESS":"ERROR");
					printf("���������飺");
					for(i=0; i<size; i++)
					{
						printf("%d", a[i]);
					}
					printf("\n");
					free(a);
					a = NULL;
				}
				break;
			}
		case 5:
			{
				system("cls");
				printf("\n\t��һ�������������ҵ���K��/С����\n");
				printf("\t��10000���������Ϊ��\n");
				{
					int k, size=10000, num;
					int *a = (int *)malloc(size * sizeof(int));
					newarray(a, size);
					printf("\n������k��");
					scanf("%d", &k);
					num = find(a, 0, size-1, k);
					printf("kΪ%d\n", num);
					free(a);
					a = NULL;
				}
				break;
			}
		case 6:
			{
				exit(0);
				break;
			}
		default:
                printf("\tNo such option.\n");
		}
		system("pause");
	}
	while(1);
}
