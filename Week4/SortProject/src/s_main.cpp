#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK4\SORTPROJECT\INC\qgsort.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("\n\t\t排序及排序算法效率测试程序\n\n");
	printf("\t现有三个层次的数据量可用于测试六大排序算法！\n");
	printf("\t1、10000\n");
	printf("\t2、50000\n");
	printf("\t3、200000\n");
	printf("\t\t其他排序！\n");
	printf("\t4、颜色排序(只含0，1，2元素)\n");
	printf("\t5、在一个无序序列中找到第K大/小的数\n");
	printf("\t6、退出\n");
	printf("\t请输入您的选择：");
}

//生成随机数并写入文件中
void randomNumGenerator(int n)
{
	int *a = (int *)malloc(n* sizeof(int));
	int i;
	FILE *pf = NULL;//声明文件指针
	srand((unsigned)time(NULL));//先种种子
	if(n == 10000)//在指定目录下创建txt文件
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
		fprintf(pf, "%d	", a[i]);//把随机数写入文件
	}
	fclose(pf);//关闭文件
	free(a);
	a = NULL;
}

//判断是否成功排序
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

//生成待排序数组
void newarray(int *a, int n)
{
	int i;
	FILE *fw;
	if(n == 10000)//打开对应文件
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
	printf("待排序数组数据：\t");
	for(i=0; i<n; i++)
	{
		fscanf(fw, "%d", &a[i]);//读取文件数据，遇到空格和换行停止读
		printf("%5d  ", a[i]);
	}
	//printf("\t测试\t");
	fclose(fw);
}

//计算每个排序算法的运行时间
void timer(int size)
{
	int *a = (int *)malloc(size* sizeof(int));
	int i;


	/*system("cls");
	printf("\n\t归并排序\n");
	{
		clock_t start_time, end_time;
		newarray(a, size);
		printf("\t测试\t");
		start_time = clock();
		{
			MergeSort(a, 0, size-1, a);
		}
		end_time = clock();
		printf("\n归并排序运行时间为：%lfms\n", static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
		printf("SORTED %s!", isSorted(a, size) == SUCCESS ? "SUCCESS":"ERROR");
		printf("\n");
		system("pause");
	}*/


	system("cls");
	printf("\n\t插入排序\n");
	{
		clock_t start_time, end_time;
		newarray(a, size);
		start_time = clock();
		{
			insertSort(a, size);
		}
		end_time = clock();
		printf("\n插入排序运行时间为：%lfms\n", static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
		printf("SORTED %s!", isSorted(a, size) == SUCCESS ? "SUCCESS":"ERROR");
		printf("\n");
		system("pause");
	}

	
	system("cls");
	printf("\n\t快速排序（递归版）\n");
	{
		clock_t start_time, end_time;
		newarray(a, size);
		start_time = clock();
		{
			QuickSort_Recursion(a, 0, size-1);
		}
		end_time = clock();
		printf("\n快速排序（递归版）运行时间为：%lfms\n", static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
		printf("SORTED %s!", isSorted(a, size) == SUCCESS ? "SUCCESS":"ERROR");
		printf("\n");
		system("pause");
	}


	system("cls");
	printf("\n\t快速排序（非递归版）\n");
	{
		clock_t start_time, end_time;
		newarray(a, size);
		start_time = clock();
		{
			QuickSort(a, size);
		}
		end_time = clock();
		printf("\n快速排序（非递归版）的运行时间为：%lfms\n", static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
		printf("SORTED %s!", isSorted(a, size) == SUCCESS ? "SUCCESS":"ERROR");
		printf("\n");
		system("pause");
	}


	system("cls");
	printf("\n\t计数排序\n");
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
		printf("\n计数排序的运行时间为：%lfms\n", static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
		printf("SORTED %s!", isSorted(a, size) == SUCCESS ? "SUCCESS":"ERROR");
		printf("\n");
		system("pause");
	}


	system("cls");
	printf("\n\t基数计数排序\n");
	{
		clock_t start_time, end_time;
		newarray(a, size);
		start_time = clock();
		{
			RadixCountSort(a, size);
		}
		end_time = clock();
		printf("\n基数计数排序的运行时间为：%lfms\n", static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
		printf("SORTED %s!", isSorted(a, size) == SUCCESS ? "SUCCESS":"ERROR");
		printf("\n");
	}

	free(a);
}

void main()
{
	int n;
	//需要生成时取消注释
	/*randomNumGenerator(10000);//生成1万随机数并写入文件
	randomNumGenerator(50000);//生成5万随机数并写入文件
	randomNumGenerator(200000);//生成20万随机数并写入文件*/
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
				printf("\n\t颜色排序\n");
				{
					clock_t start_time, end_time;
					int i, *a, size;
					printf("请输入数组长度（整数）：");
					scanf("%d", &size);
					a = (int *)malloc(size * sizeof(int));
					printf("请输入只含0、1、2三个元素的数组：");
					for(i=0; i<size; i++)
					{
						scanf("%d", &a[i]);
					}
					start_time = clock();
					{
						ColorSort(a, size);
					}
					end_time = clock();
					printf("运行时间为：%lfms\n", static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
					printf("SORTED %s!", isSorted(a, size) == SUCCESS ? "SUCCESS":"ERROR");
					printf("排序后的数组：");
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
				printf("\n\t在一个无序序列中找到第K大/小的数\n");
				printf("\t以10000随机数数组为例\n");
				{
					int k, size=10000, num;
					int *a = (int *)malloc(size * sizeof(int));
					newarray(a, size);
					printf("\n请输入k：");
					scanf("%d", &k);
					num = find(a, 0, size-1, k);
					printf("k为%d\n", num);
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
