#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK5\INC\binary_sort_tree.h"
#include<stdio.h>
#include<stdlib.h>

//��ʼ������������
BST_Status BST_init(NodePtr *pRoot)
{
	*pRoot = (BST_Node *)malloc(sizeof(BST_Node));
	if(!pRoot)
	{
		printf("\t�����ڴ�ʧ��!\n");
		return failed;
	}
	(*pRoot)->left = (*pRoot)->right = NULL;
	(*pRoot)->value = 0;
	return succeed;
}

//����Ԫ��
BST_Status BST_insert(NodePtr *pRoot, ElemType *e)
{
	if(*pRoot == NULL) //�ڵ�Ϊ��ʱ���ȿ��ٿռ��ٲ���
	{
		//printf("\t��������!Ҫ�ȳ�ʼ��!\n");
		//BST_init(tree);
		(*pRoot) = (BST_Node *)malloc(sizeof(BST_Node));
		(*pRoot)->left = (*pRoot)->right = NULL;
		(*pRoot)->value = *e;
		return succeed;
	}
	else 
	{
		if((*pRoot)->value == 0)
		{
			(*pRoot)->value = *e;
			return succeed;
		}
		if((*pRoot)->value == *e)
		{
			printf("\tԪ��%d�Ѵ���!\n", *e);
			return failed;
		}
		if(*e < (*pRoot)->value) //ͨ���ݹ��ҵ��Ե�λ�ò���
		{
			BST_insert(&(*pRoot)->left, e);
		}
		else if(*e > (*pRoot)->value) //ͨ���ݹ��ҵ��Ե�λ�ò���
		{
			BST_insert(&(*pRoot)->right, e);
		}
		else return failed;
	}
	//return succeed;
}

//ɾ��ָ��Ԫ��
BST_Status BST_delete(NodePtr *pRoot, ElemType *del)
{
	if(*pRoot == NULL)
	{
		//printf("\t���ȳ�ʼ����\n");
		//return failed;
	}
	else
	{
		if(*del < (*pRoot)->value) //ͨ���ݹ��ҵ�Ҫɾ��Ԫ�ص�λ��
		{
			BST_delete(&(*pRoot)->left, del);
		}
		else if(*del > (*pRoot)->value) //ͨ���ݹ��ҵ�Ҫɾ��Ԫ�ص�λ��
		{
			BST_delete(&(*pRoot)->right, del);
		}
		else //��ʱ�Ѿ��ҵ��˴�ɾ���ڵ� *del=(*pRoot)->value
		{
			NodePtr pDel = *pRoot;
			if(pDel->left == NULL && pDel->right == NULL) //���ڵ�
			{
				pDel = NULL;
				return succeed;
			} 
			if(pDel->left == NULL) //ֻ���Һ��� 
			{
				*pRoot = pDel->right;
				free(pDel);
				return succeed;
			}
			else if(pDel->right == NULL)//ֻ������ 
			{
				*pRoot = pDel->left;
				free(pDel);
				return succeed;
			}
			else //���Һ��Ӷ���
			{
				//��������������ֵ�滻��ǰ�ڵ� 
				ElemType max = findMax(pDel->left);
				pDel->value = max;
				BST_delete(&(pDel->left), del);
				//return succeed;
			} 
		} 
	}
}

//������������ֵ
ElemType findMax(BST_Node *left) 
{
	if(left == NULL)
	{
		return 0;
	}
	if(left->right == NULL)//��������ʱ�����ڵ���� 
	{
		return left->value;
	}
	return findMax(left->right);
}

//����Ԫ��
BST_Status BST_search(NodePtr *pRoot, ElemType *s)
{
	if((*pRoot) == NULL)
	{
		return failed;
	}
	if(*s == (*pRoot)->value)
	{
		return succeed;
	}
	if(*s < (*pRoot)->value)
	{
		BST_search(&(*pRoot)->left, s);
	}
	else if(*s > (*pRoot)->value)
	{
		BST_search(&(*pRoot)->right, s);
	}
	else return failed;
	//return succeed;
}

//�ݹ�ǰ����� 
BST_Status BST_preorderR(NodePtr *pRoot, void (*visit)(NodePtr p))
{
	if((*pRoot) == NULL)//�������� 
	{
		return succeed;
	}
	(*visit)(*pRoot);//��ӡ��ǰ���ڵ����� 
	BST_preorderR(&(*pRoot)->left, visit);
	BST_preorderR(&(*pRoot)->right, visit);
}

//�ݹ��������
BST_Status BST_inorderR(NodePtr *pRoot, void (*visit)(NodePtr p))
{
	if((*pRoot) == NULL)//��������
	{
		return succeed;
	} 
	BST_inorderR(&(*pRoot)->left, visit);//�ȴ�ӡ���������� 
	(*visit)(*pRoot);//��ӡ�׸��ڵ�����
	BST_inorderR(&(*pRoot)->right, visit);
}


//�ݹ�������
BST_Status BST_postorderR(NodePtr *pRoot, void (*visit)(NodePtr p))
{
	if((*pRoot) == NULL)//��������
	{
		return succeed;
	} 
	BST_postorderR(&(*pRoot)->left, visit);//�ȴ�ӡ���������� 
	BST_postorderR(&(*pRoot)->right, visit);//������������ 
	(*visit)(*pRoot);//����ӡ�׸��ڵ�����
}

//����ǰ�����
BST_Status BST_preorderI(NodePtr *pRoot, void (*visit)(NodePtr p))
{
	//��ʼ��ջ 
	/*ElemType statu, *e, *pdata;
	LinkStack *s = (LinkStack*)malloc(sizeof(StackNode));
	e = (ElemType*)malloc(sizeof(ElemType));
	pdata = (ElemType*)malloc(sizeof(ElemType));
	statu = initLStack(s);*/
	//��������ָ��
	NodePtr T = *pRoot;
	BST_Node *stack[MaxSize];//ջ��Žڵ�ָ�� 
	int top = 0;//ջ���±� 
	//��ʼ����ѭ��
	while(T || top > 0)
	{
		if(T != NULL)
		{
			(*visit)(T);//��ӡ
			stack[top++] = T;//statu = pushLStack(s, &(T->value));//��ջ
			//P = T;//��¼λ�� 
			T = T->left;//���������� 
		}
		else
		{
			//statu = getTopLStack(s, e);
			//T = e;
			T = stack[--top];//statu = popLStack(s, pdata);//��ջ 
			T = T->right;//���������� 
		}
	}
	//statu = destroyLStack(s);
	return succeed;
}

//�����������
BST_Status BST_inorderI(NodePtr *pRoot, void (*visit)(NodePtr p))
{
	//��ʼ��ջ 
	/*ElemType statu, *e, *pdata;
	LinkStack *s = (LinkStack*)malloc(sizeof(StackNode));
	e = (ElemType*)malloc(sizeof(ElemType));
	pdata = (ElemType*)malloc(sizeof(ElemType));
	statu = initLStack(s);*/
	//��������ָ��
	NodePtr T = *pRoot;
	BST_Node *stack[MaxSize];//ջ��Žڵ�ָ�� 
	int top = 0;//ջ���±� 
	//��ʼ����ѭ��
	while(T || top > 0)
	{
		if(T != NULL)
		{
			stack[top++] = T;//statu = pushLStack(s, &(T->value));//��ջ
			T = T->left;//���������� 
		}
		else
		{
			//statu = getTopLStack(s, e);
			//T = e;
			T = stack[--top];//statu = popLStack(s, pdata);//��ջ 
			(*visit)(T);//��ӡ
			T = T->right;//���������� 
		}
	}
	//statu = destroyLStack(s);
	return succeed;
}

//�����������
BST_Status BST_postorderI(NodePtr *pRoot, void (*visit)(NodePtr p))
{
	//��ʼ��ջ 
	/*ElemType statu, *e, *pdata;
	LinkStack *s = (LinkStack*)malloc(sizeof(StackNode));
	e = (ElemType*)malloc(sizeof(ElemType));
	pdata = (ElemType*)malloc(sizeof(ElemType));
	statu = initLStack(s);*/
	//��������ָ��
	NodePtr pCur = *pRoot, pLast;//pCurΪ��ǰ�ڵ㣬pLastΪ��һ�η��ʵĽڵ� 
	BST_Node *stack[MaxSize];//ջ��Žڵ�ָ��
	int top = 0;//ջ���±� 
	//��ʼ����ѭ��
	while(pCur || top > 0)
	{
		if(pCur != NULL)
		{
			stack[top++] = pCur;//statu = pushLStack(s, &(T->value));//��ջ
			pCur = pCur->left;//����������,ֱ�����������±� 
		}
		else
		{
			//statu = getTopLStack(s, e);
			//T = e;
			pCur = stack[top-1];//ȡջ��Ԫ��
			//����ǰ�ڵ�û���Һ��ӻ� �Һ��Ӹոշ��ʹ��� 
			if(pCur->right == NULL || pCur->right == pLast)
			{
				(*visit)(pCur);//��ӡ��ǰ�ڵ�
				pLast = pCur;//����ǰ�ڵ㸳��pLast 
				pCur = NULL;//�ÿյ�ǰ�ڵ� 
				top--;//ջ��Ԫ�س�ջ 
			}
			else
			{
				pCur = pCur->right;
			}
		}
	}
	//statu = destroyLStack(s);
	return succeed;
}

//�������
BST_Status BST_levelOrder(NodePtr *pRoot, void (*visit)(NodePtr p))
{
	BST_Node *queue[MaxSize];//������Žڵ�Ķ���
	int front = 0, rear = 0;
	NodePtr P = *pRoot;//���ڵ� 
	if(P != NULL)
	{
		queue[rear] = P;//���ڵ����
		rear = (rear + 1) % MaxSize;
		while(rear != front)//��βָ�벻ͬ 
		{
			P = queue[front];//ָ����е�һ��Ԫ�� 
			(*visit)(P);//��ӡ����ͷԪ�� 
			front = (front + 1) % MaxSize;//P���� 
			if(P->left != NULL)
			{
				queue[rear] = P->left ;//������� 
				rear = (rear + 1) % MaxSize;
			}
			if(P->right != NULL)
			{
				queue[rear] = P->right ;//�Һ������
				rear = (rear + 1) % MaxSize;
			}
		}
	}
	return succeed; 
}

//���������Ч�ʵ����
ElemType getBSTdepth(NodePtr *pRoot)
{
	ElemType leftH, rightH, maxH;//��������ȣ���������ȣ������� 
	NodePtr T = *pRoot;
	if(T != NULL)
	{
		leftH = getBSTdepth(&(T->left));//���������
		rightH = getBSTdepth(&(T->right));//���������
		maxH = leftH > rightH ? leftH : rightH;//������
		return maxH+1;
	}
	else
	{
		return 0;
	}
}

//��ӡ
 void visit(NodePtr p)
 {
 	printf("\t%d", p->value);
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
		status = true;
		for(i=0;str[i]!='\0';)
		{
			i++;
		}
		if(i==1)
		{
			if(str[i-1] <= '0' || str[i-1] > '9')
			{
				status = false;
			}
			else status = true;
		}
		else if(i==2)
			{
				if(str[i-2] == '1' && str[i-1] >= '0' && str[i-1] <= '3')
				{
					status = true;
				}
				else status = false;
			}
			else status = false;
		if(status == false)
		{
			printf("\t�������!����������:");
			for(j=0;j<i;j++)
			{
				str[j] = '\0';
			}
		}
	}while(status == false);
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
