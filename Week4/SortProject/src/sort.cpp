#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK4\SORTPROJECT\INC\qgsort.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//插入排序
void insertSort(int *a,int n)
{
	int i, j, key;
	for(i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while((a[j] > key) && (j >= 0))
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

//归并排序（合并数组）
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
	int i, j, k, l;
	i = begin;
	printf("\t测试\t");
	for(j=mid+1, k=begin;i<=mid && j<=end;k++)
	{
		if(a[i] < a[j])
			temp[k] = a[i++];
		else
			temp[k] = a[j++];
	}
	printf("\t测试\t");
	if(i<=mid)
	{
		for(l=0;l<=mid-i;l++)
			temp[k++] = a[i++];
	}
	if(j<=end)
	{
		for(l=0;l<=end-j;l++)
			temp[k++] = a[j++];
	}
}

//归并排序
void MergeSort(int *a,int begin,int end,int *temp)
{
	int m;
	int *b = (int *)malloc((end+1) * sizeof(int)); //以变量为长度定义数组
	//printf("\t测试\t");
	if(begin == end)
	{
		temp[begin] = a[begin];
	}
	else
	{
		m = (end + 1) / 2;
		MergeSort(a, begin, m, b);
		MergeSort(a, m+1, end, b);
		MergeArray(b, begin, m, end, temp);
	}
	/*for(i=0; i<=end; i++)
	{
		a[i] = temp[i];
	}
	a = temp;
	free(b);
	b = NULL;*/
}

//快速排序（递归版）
void QuickSort_Recursion(int *a, int begin, int end)
{
	int pivot;
	if(begin < end)
	{
		pivot = Partition(a, begin, end);//将数组一分为二并计算枢轴值
		QuickSort_Recursion(a, begin, pivot-1);//对低子表递归排序
		QuickSort_Recursion(a, pivot+1, end);//对高子表递归排序
	}
}

//快速排序（非递归版）使用栈
void QuickSort(int *a,int size)
{
	int i, j, begin, temp, end, top=0;
	stackNode *st = (stackNode* )malloc(size* sizeof(stackNode));
	if(!st)
	{
		printf("\t内存分配失败!\n");
		return;
	}
	st[top].begin = 0;
	st[top].end = size - 1;
	while(top > -1)
	{
		begin = st[top].begin;
		end = st[top].end;
		top--;
		i = begin;
		j = end;
		if(begin < end)
		{
			temp = a[begin];
			while(i < j)
			{
				while(i<j && a[j]>=temp)
				{
					j--;
				}
				while(i<j && a[i]<=temp)
				{
					i++;
				}
				swap(a, i, j);
			}
			a[i] = temp;
			if(i <= j)
			{
				top++;
				st[top].begin = begin;
				st[top].end = i-1;
				top++;
				st[top].begin = ++i;
				st[top].end = end;
			}
		}
	}
}

//快速排序的枢轴存放
int Partition(int *a, int begin, int end)
{
	int pivotkey = a[begin]; //用子表的第一个记录作为枢轴记录
	while(begin < end)
	{
		while(begin < end && a[end] >= pivotkey)
			end--;
		swap(a, begin, end);//将比枢轴记录小的记录交换到低端
		while(begin < end && a[begin] <= pivotkey)
			begin++;
		swap(a, begin, end); //将比枢轴记录大的记录交换到高端
	}
	return end; //返回枢轴所在位置
}

//计数排序
void CountSort(int *a, int size , int max)
{
	int i, j, min=a[0];
	for(i=0; i<size; i++)
	{
		if(a[i] < min)
			min = a[i];
	}
	{
		int range = max - min + 1;//定义变量必须在代码块开头
		int *b = (int*)calloc(range, sizeof(int));//calloc初始化自动清零
		for(i=0; i<size; i++)
		{
			b[a[i] - min]++;//要减去min防止越界
		}
		/*for(k=1; k<size; k++)
		{
			b[k] += b[k-1];
		}*/ //这样做好像没有什么用？
		for(i=j=0; i<range; i++)
		{
			while(b[i]--)
			{
				a[j++] = i + min; //要加上min的值
			}
		}
		free(b);//释放临时数组
		b = NULL;
	}
}

//基数计数排序
void RadixCountSort(int *a,int size)
{
	int i, j, k, x, num, temp=1, index;
	int *radixArrays[RADIX_10]; // 0~9的序列空间
	for(i=0; i<10; i++)
	{
		radixArrays[i] = (int *)malloc((size + 1) * sizeof(int));
		radixArrays[i][0] = 0; //index为0处记录数据个数
	}
	//printf("\t测试\t");
	for(j=1; j<=KEYNUM_5; j++) //从个位到万位
	{
		for(i=0; i<size; i++) //分配过程
		{
			for(x=0; x<j-1; x++)//找到a的从高位到低位的数据
			{
				temp *= 10;
			}
			num = (a[i] / temp) % 10;
			index = ++radixArrays[num][0];
			radixArrays[num][index] = a[i];
		}
		//printf("\t测试\t");
		for(i=0, j=0; i<RADIX_10; i++) //收集
		{
			for(k=1; k<=radixArrays[i][0]; k++)
			{
				a[j++] = radixArrays[i][k];
			}
			radixArrays[i][0] = 0; //复位
		}
	}
	//printf("\t测试\t");
}

//颜色排序(只含0，1，2元素)
void ColorSort(int *a,int size)
{
	int p1=0, p2=0, p3=size-1;
	while(p1 <= p3)
	{
		if(a[p1] == 1)
		{
			p1++;
		}
		else if(a[p1] == 0)
		{
			swap(a, p2, p1);
			p1++;
			p2++;
		}
		else
		{
			while(p1 < p3 && a[p3] == 2)
				p3--;
			swap(a, p3, p1);
			p3--;
		}
	}
}

//在一个无序序列中找到第K大/小的数
int find(int *a, int begin, int end, int k)
{
	int pos = Partition(a, begin, end);
	if(k-1 == pos)
	{
		return a[k-1];
	}
	else if(k-1 < pos)//进行下一次划分
	{
		find(a, begin, pos-1, k);
	}
	else
	{
		find(a, pos+1, end, k);
	}
}

//交换数组下标为x和y的值
void swap(int *a, int x, int y)
{
	int temp;
	temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

//打印结果
void Show(int *a, int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d	", a[i]);
	}
	printf("\n");
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
		status = SUCCESS;
		for(i=0;str[i]!='\0';)
		{
			i++;
		}
		if(i==1)
		{
			if(str[i-1] <= '0' || str[i-1] > '6')
			{
				status = ERROR;
			}
			else status = SUCCESS;
		}
		else status = ERROR;
		if(status == ERROR)
		{
			printf("\t输入错误!请重新输入:");
			for(j=0;j<i;j++)
			{
				str[j] = '\0';
			}
		}
	}while(status == ERROR);
	input = str[i-1] - 48;
	return input;
}