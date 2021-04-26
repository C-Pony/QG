#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK5\INC\binary_sort_tree.h"
#include<stdio.h>
#include<stdlib.h>

void menu()
{
	printf("\n\n\t二叉排序树ADT\n\n");
	printf("\t1.初始化\n");
	printf("\t2.插入元素\n");
	printf("\t3.删除指定元素\n");
	printf("\t4.查找元素\n");
	printf("\t5.迭代前序遍历\n");
	printf("\t6.递归前序遍历\n");
	printf("\t7.迭代中序遍历\n");
	printf("\t8.递归中序遍历\n");
	printf("\t9.迭代后序遍历\n");
	printf("\t10.递归后序遍历\n");
	printf("\t11.层序遍历\n");
	printf("\t12.计算二叉树效率的深度\n");
	printf("\t13.退出程序\n\n");
}

int main()
{
	ElemType status, *e, *d, *s;
	NodePtr root = NULL;//(Node *)malloc(sizeof(Node));
	//NodePtr head;
	e = (ElemType *)malloc(sizeof(ElemType));
	d = (ElemType *)malloc(sizeof(ElemType));
	s = (ElemType *)malloc(sizeof(ElemType));
	do
	{
		system("cls");
		//head = *pRoot;
		menu();
		printf("\t请输入选择(数字1-12):");
		switch(checkinput())
		{
		case 1://初始化
			{
				status = BST_init(&root);
				if(status)
				{
					printf("\t已成功初始化!\n");
				}
				break;
			}
		case 2://插入元素
			{
				if(&root == NULL)
				{
					printf("\t树不存在!要先初始化!\n");
					//BST_init(tree);
					//return failed;
				}
				else
				{
					printf("\t请输入要插入的数字：");
					scanf("%d", e);
					//printf("要插入的数字为%d", *e);
					status = BST_insert(&root, e);
					if(status)
					{
						printf("\t元素%d已成功插入!\n", *e);
					}
					else printf("\t插入失败!\n");
				}
				break;
			}
		case 3://删除指定元素
			{
				if(&root == NULL)
				{
					printf("\t树不存在!要先初始化!\n");
				}
				else
				{
					printf("\t请输入要删除的数字：");
					scanf("%d", d);
					status = BST_delete(&root, d);
					if(status)
					{
						printf("\t成功删除了元素%d!\n", *d);
					}
					else printf("\t删除失败!\n", *d);
				}
				break;
			}
		case 4://查找元素
			{
				if(&root == NULL)
				{
					printf("\t树不存在!要先初始化!\n");
				}
				else
				{
					printf("\t请输入要查找的数字：");
					scanf("%d", s);
					status = BST_search(&root, s);
					if(status)
					{
						printf("\t在树中找到了元素%d!\n", *s);
					}
					else printf("\t元素%d不在树中!\n", *s);
				}
				break;
			}
		case 5://迭代前序遍历
			{
				if(&root == NULL)
				{
					printf("\t树不存在!要先初始化!\n");
				}
				else
				{
					printf("迭代前序遍历输出为：");
					status = BST_preorderI(&root, &visit);
					if(status)
					{
						printf("\t遍历完成!\n");
					}
					else printf("\t遍历失败!\n");
				}
				break;
			}
		case 6://递归前序遍历
			{
				if(&root == NULL)
				{
					printf("\t树不存在!要先初始化!\n");
				}
				else
				{
					printf("递归前序遍历输出为：");
					status = BST_preorderR(&root, &visit);
					if(status)
					{
						printf("\t遍历完成!\n");
					}
					else printf("\t遍历失败!\n");
				}
				break;
			}
		case 7://迭代中序遍历
			{
				if(&root == NULL)
				{
					printf("\t树不存在!要先初始化!\n");
				}
				else
				{
					printf("迭代中序遍历输出为：");
					status = BST_inorderI(&root, &visit);
					if(status)
					{
						printf("\t遍历完成!\n");
					}
					else printf("\t遍历失败!\n");
				}
				break;
			}
		case 8://递归中序遍历
			{
				if(&root == NULL)
				{
					printf("\t树不存在!要先初始化!\n");
				}
				else
				{
					printf("递归中序遍历输出为：");
					status = BST_inorderR(&root, &visit);
					if(status)
					{
						printf("\t遍历完成!\n");
					}
					else printf("\t遍历失败!\n");
				}
				break;
			}
		case 9://迭代后序遍历
			{
				if(&root == NULL)
				{
					printf("\t树不存在!要先初始化!\n");
				}
				else
				{
					printf("迭代后序遍历输出为：");
					status = BST_postorderI(&root, &visit);
					if(status)
					{
						printf("\t遍历完成!\n");
					}
					else printf("\t遍历失败!\n");
				}
				break;
			}
		case 10://递归后序遍历
			{
				if(&root == NULL)
				{
					printf("\t树不存在!要先初始化!\n");
				}
				else
				{
					printf("递归后序遍历输出为：");
					status = BST_postorderR(&root, &visit);
					if(status)
					{
						printf("\t遍历完成!\n");
					}
					else printf("\t遍历失败!\n");
				}
				break;
			}
		case 11://层序遍历
			{
				if(&root == NULL)
				{
					printf("\t树不存在!要先初始化!\n");
				}
				else
				{
					printf("层序遍历输出为：");
					status = BST_levelOrder(&root, &visit);
					if(status)
					{
						printf("\t遍历完成!\n");
					}
					else printf("\t遍历失败!\n");
				}
				break;
			}
		case 12://计算二叉树效率的深度
			{
				printf("当前树深度为：%d\n", getBSTdepth(&root));
				break;
			}
		case 13://退出程序
			{
				exit(0);
				break;
			}
		default:
                printf("\tNo such option.\n");
		}
		system("pause");
	}while(1);
    return 0;
}
