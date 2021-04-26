#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK5\INC\binary_sort_tree.h"
#include<stdio.h>
#include<stdlib.h>

//初始化二叉排序树
BST_Status BST_init(NodePtr *pRoot)
{
	*pRoot = (BST_Node *)malloc(sizeof(BST_Node));
	if(!pRoot)
	{
		printf("\t分配内存失败!\n");
		return failed;
	}
	(*pRoot)->left = (*pRoot)->right = NULL;
	(*pRoot)->value = 0;
	return succeed;
}

//插入元素
BST_Status BST_insert(NodePtr *pRoot, ElemType *e)
{
	if(*pRoot == NULL) //节点为空时，先开辟空间再插入
	{
		//printf("\t树不存在!要先初始化!\n");
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
			printf("\t元素%d已存在!\n", *e);
			return failed;
		}
		if(*e < (*pRoot)->value) //通过递归找到对的位置插入
		{
			BST_insert(&(*pRoot)->left, e);
		}
		else if(*e > (*pRoot)->value) //通过递归找到对的位置插入
		{
			BST_insert(&(*pRoot)->right, e);
		}
		else return failed;
	}
	//return succeed;
}

//删除指定元素
BST_Status BST_delete(NodePtr *pRoot, ElemType *del)
{
	if(*pRoot == NULL)
	{
		//printf("\t请先初始化！\n");
		//return failed;
	}
	else
	{
		if(*del < (*pRoot)->value) //通过递归找到要删除元素的位置
		{
			BST_delete(&(*pRoot)->left, del);
		}
		else if(*del > (*pRoot)->value) //通过递归找到要删除元素的位置
		{
			BST_delete(&(*pRoot)->right, del);
		}
		else //此时已经找到了待删除节点 *del=(*pRoot)->value
		{
			NodePtr pDel = *pRoot;
			if(pDel->left == NULL && pDel->right == NULL) //根节点
			{
				pDel = NULL;
				return succeed;
			} 
			if(pDel->left == NULL) //只有右孩子 
			{
				*pRoot = pDel->right;
				free(pDel);
				return succeed;
			}
			else if(pDel->right == NULL)//只有左孩子 
			{
				*pRoot = pDel->left;
				free(pDel);
				return succeed;
			}
			else //左右孩子都有
			{
				//找左子树中最大的值替换当前节点 
				ElemType max = findMax(pDel->left);
				pDel->value = max;
				BST_delete(&(pDel->left), del);
				//return succeed;
			} 
		} 
	}
}

//左子树中最大的值
ElemType findMax(BST_Node *left) 
{
	if(left == NULL)
	{
		return 0;
	}
	if(left->right == NULL)//右子树无时，根节点最大 
	{
		return left->value;
	}
	return findMax(left->right);
}

//查找元素
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

//递归前序遍历 
BST_Status BST_preorderR(NodePtr *pRoot, void (*visit)(NodePtr p))
{
	if((*pRoot) == NULL)//遍历结束 
	{
		return succeed;
	}
	(*visit)(*pRoot);//打印当前根节点数据 
	BST_preorderR(&(*pRoot)->left, visit);
	BST_preorderR(&(*pRoot)->right, visit);
}

//递归中序遍历
BST_Status BST_inorderR(NodePtr *pRoot, void (*visit)(NodePtr p))
{
	if((*pRoot) == NULL)//遍历结束
	{
		return succeed;
	} 
	BST_inorderR(&(*pRoot)->left, visit);//先打印左子树孩子 
	(*visit)(*pRoot);//打印首根节点数据
	BST_inorderR(&(*pRoot)->right, visit);
}


//递归后序遍历
BST_Status BST_postorderR(NodePtr *pRoot, void (*visit)(NodePtr p))
{
	if((*pRoot) == NULL)//遍历结束
	{
		return succeed;
	} 
	BST_postorderR(&(*pRoot)->left, visit);//先打印左子树孩子 
	BST_postorderR(&(*pRoot)->right, visit);//和右子树孩子 
	(*visit)(*pRoot);//最后打印首根节点数据
}

//迭代前序遍历
BST_Status BST_preorderI(NodePtr *pRoot, void (*visit)(NodePtr p))
{
	//初始化栈 
	/*ElemType statu, *e, *pdata;
	LinkStack *s = (LinkStack*)malloc(sizeof(StackNode));
	e = (ElemType*)malloc(sizeof(ElemType));
	pdata = (ElemType*)malloc(sizeof(ElemType));
	statu = initLStack(s);*/
	//创建遍历指针
	NodePtr T = *pRoot;
	BST_Node *stack[MaxSize];//栈存放节点指针 
	int top = 0;//栈顶下标 
	//开始遍历循环
	while(T || top > 0)
	{
		if(T != NULL)
		{
			(*visit)(T);//打印
			stack[top++] = T;//statu = pushLStack(s, &(T->value));//入栈
			//P = T;//记录位置 
			T = T->left;//遍历左子树 
		}
		else
		{
			//statu = getTopLStack(s, e);
			//T = e;
			T = stack[--top];//statu = popLStack(s, pdata);//出栈 
			T = T->right;//遍历右子树 
		}
	}
	//statu = destroyLStack(s);
	return succeed;
}

//迭代中序遍历
BST_Status BST_inorderI(NodePtr *pRoot, void (*visit)(NodePtr p))
{
	//初始化栈 
	/*ElemType statu, *e, *pdata;
	LinkStack *s = (LinkStack*)malloc(sizeof(StackNode));
	e = (ElemType*)malloc(sizeof(ElemType));
	pdata = (ElemType*)malloc(sizeof(ElemType));
	statu = initLStack(s);*/
	//创建遍历指针
	NodePtr T = *pRoot;
	BST_Node *stack[MaxSize];//栈存放节点指针 
	int top = 0;//栈顶下标 
	//开始遍历循环
	while(T || top > 0)
	{
		if(T != NULL)
		{
			stack[top++] = T;//statu = pushLStack(s, &(T->value));//入栈
			T = T->left;//遍历左子树 
		}
		else
		{
			//statu = getTopLStack(s, e);
			//T = e;
			T = stack[--top];//statu = popLStack(s, pdata);//出栈 
			(*visit)(T);//打印
			T = T->right;//遍历右子树 
		}
	}
	//statu = destroyLStack(s);
	return succeed;
}

//迭代后序遍历
BST_Status BST_postorderI(NodePtr *pRoot, void (*visit)(NodePtr p))
{
	//初始化栈 
	/*ElemType statu, *e, *pdata;
	LinkStack *s = (LinkStack*)malloc(sizeof(StackNode));
	e = (ElemType*)malloc(sizeof(ElemType));
	pdata = (ElemType*)malloc(sizeof(ElemType));
	statu = initLStack(s);*/
	//创建遍历指针
	NodePtr pCur = *pRoot, pLast;//pCur为当前节点，pLast为上一次访问的节点 
	BST_Node *stack[MaxSize];//栈存放节点指针
	int top = 0;//栈顶下标 
	//开始遍历循环
	while(pCur || top > 0)
	{
		if(pCur != NULL)
		{
			stack[top++] = pCur;//statu = pushLStack(s, &(T->value));//入栈
			pCur = pCur->left;//遍历左子树,直到左子树最下边 
		}
		else
		{
			//statu = getTopLStack(s, e);
			//T = e;
			pCur = stack[top-1];//取栈顶元素
			//若当前节点没有右孩子或 右孩子刚刚访问过了 
			if(pCur->right == NULL || pCur->right == pLast)
			{
				(*visit)(pCur);//打印当前节点
				pLast = pCur;//将当前节点赋给pLast 
				pCur = NULL;//置空当前节点 
				top--;//栈顶元素出栈 
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

//层序遍历
BST_Status BST_levelOrder(NodePtr *pRoot, void (*visit)(NodePtr p))
{
	BST_Node *queue[MaxSize];//创建存放节点的队列
	int front = 0, rear = 0;
	NodePtr P = *pRoot;//根节点 
	if(P != NULL)
	{
		queue[rear] = P;//根节点入队
		rear = (rear + 1) % MaxSize;
		while(rear != front)//首尾指针不同 
		{
			P = queue[front];//指向队列第一个元素 
			(*visit)(P);//打印队列头元素 
			front = (front + 1) % MaxSize;//P出队 
			if(P->left != NULL)
			{
				queue[rear] = P->left ;//左孩子入队 
				rear = (rear + 1) % MaxSize;
			}
			if(P->right != NULL)
			{
				queue[rear] = P->right ;//右孩子入队
				rear = (rear + 1) % MaxSize;
			}
		}
	}
	return succeed; 
}

//计算二叉树效率的深度
ElemType getBSTdepth(NodePtr *pRoot)
{
	ElemType leftH, rightH, maxH;//左子树深度，右子树深度，最大深度 
	NodePtr T = *pRoot;
	if(T != NULL)
	{
		leftH = getBSTdepth(&(T->left));//左子树深度
		rightH = getBSTdepth(&(T->right));//右子树深度
		maxH = leftH > rightH ? leftH : rightH;//最大深度
		return maxH+1;
	}
	else
	{
		return 0;
	}
}

//打印
 void visit(NodePtr p)
 {
 	printf("\t%d", p->value);
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
			printf("\t输入错误!请重新输入:");
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
