#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK4\SORTPROJECT\INC\qgsort.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//��������
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

//�鲢���򣨺ϲ����飩
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
	int i, j, k, l;
	i = begin;
	printf("\t����\t");
	for(j=mid+1, k=begin;i<=mid && j<=end;k++)
	{
		if(a[i] < a[j])
			temp[k] = a[i++];
		else
			temp[k] = a[j++];
	}
	printf("\t����\t");
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

//�鲢����
void MergeSort(int *a,int begin,int end,int *temp)
{
	int m;
	int *b = (int *)malloc((end+1) * sizeof(int)); //�Ա���Ϊ���ȶ�������
	//printf("\t����\t");
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

//�������򣨵ݹ�棩
void QuickSort_Recursion(int *a, int begin, int end)
{
	int pivot;
	if(begin < end)
	{
		pivot = Partition(a, begin, end);//������һ��Ϊ������������ֵ
		QuickSort_Recursion(a, begin, pivot-1);//�Ե��ӱ�ݹ�����
		QuickSort_Recursion(a, pivot+1, end);//�Ը��ӱ�ݹ�����
	}
}

//�������򣨷ǵݹ�棩ʹ��ջ
void QuickSort(int *a,int size)
{
	int i, j, begin, temp, end, top=0;
	stackNode *st = (stackNode* )malloc(size* sizeof(stackNode));
	if(!st)
	{
		printf("\t�ڴ����ʧ��!\n");
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

//���������������
int Partition(int *a, int begin, int end)
{
	int pivotkey = a[begin]; //���ӱ�ĵ�һ����¼��Ϊ�����¼
	while(begin < end)
	{
		while(begin < end && a[end] >= pivotkey)
			end--;
		swap(a, begin, end);//���������¼С�ļ�¼�������Ͷ�
		while(begin < end && a[begin] <= pivotkey)
			begin++;
		swap(a, begin, end); //���������¼��ļ�¼�������߶�
	}
	return end; //������������λ��
}

//��������
void CountSort(int *a, int size , int max)
{
	int i, j, min=a[0];
	for(i=0; i<size; i++)
	{
		if(a[i] < min)
			min = a[i];
	}
	{
		int range = max - min + 1;//������������ڴ���鿪ͷ
		int *b = (int*)calloc(range, sizeof(int));//calloc��ʼ���Զ�����
		for(i=0; i<size; i++)
		{
			b[a[i] - min]++;//Ҫ��ȥmin��ֹԽ��
		}
		/*for(k=1; k<size; k++)
		{
			b[k] += b[k-1];
		}*/ //����������û��ʲô�ã�
		for(i=j=0; i<range; i++)
		{
			while(b[i]--)
			{
				a[j++] = i + min; //Ҫ����min��ֵ
			}
		}
		free(b);//�ͷ���ʱ����
		b = NULL;
	}
}

//������������
void RadixCountSort(int *a,int size)
{
	int i, j, k, x, num, temp=1, index;
	int *radixArrays[RADIX_10]; // 0~9�����пռ�
	for(i=0; i<10; i++)
	{
		radixArrays[i] = (int *)malloc((size + 1) * sizeof(int));
		radixArrays[i][0] = 0; //indexΪ0����¼���ݸ���
	}
	//printf("\t����\t");
	for(j=1; j<=KEYNUM_5; j++) //�Ӹ�λ����λ
	{
		for(i=0; i<size; i++) //�������
		{
			for(x=0; x<j-1; x++)//�ҵ�a�ĴӸ�λ����λ������
			{
				temp *= 10;
			}
			num = (a[i] / temp) % 10;
			index = ++radixArrays[num][0];
			radixArrays[num][index] = a[i];
		}
		//printf("\t����\t");
		for(i=0, j=0; i<RADIX_10; i++) //�ռ�
		{
			for(k=1; k<=radixArrays[i][0]; k++)
			{
				a[j++] = radixArrays[i][k];
			}
			radixArrays[i][0] = 0; //��λ
		}
	}
	//printf("\t����\t");
}

//��ɫ����(ֻ��0��1��2Ԫ��)
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

//��һ�������������ҵ���K��/С����
int find(int *a, int begin, int end, int k)
{
	int pos = Partition(a, begin, end);
	if(k-1 == pos)
	{
		return a[k-1];
	}
	else if(k-1 < pos)//������һ�λ���
	{
		find(a, begin, pos-1, k);
	}
	else
	{
		find(a, pos+1, end, k);
	}
}

//���������±�Ϊx��y��ֵ
void swap(int *a, int x, int y)
{
	int temp;
	temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

//��ӡ���
void Show(int *a, int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d	", a[i]);
	}
	printf("\n");
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
			printf("\t�������!����������:");
			for(j=0;j<i;j++)
			{
				str[j] = '\0';
			}
		}
	}while(status == ERROR);
	input = str[i-1] - 48;
	return input;
}