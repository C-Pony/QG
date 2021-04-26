#include"C:\USERS\86135\DESKTOP\QGDATASTRUCTURE\WEEK5\INC\binary_sort_tree.h"
#include<stdio.h>
#include<stdlib.h>

void menu()
{
	printf("\n\n\t����������ADT\n\n");
	printf("\t1.��ʼ��\n");
	printf("\t2.����Ԫ��\n");
	printf("\t3.ɾ��ָ��Ԫ��\n");
	printf("\t4.����Ԫ��\n");
	printf("\t5.����ǰ�����\n");
	printf("\t6.�ݹ�ǰ�����\n");
	printf("\t7.�����������\n");
	printf("\t8.�ݹ��������\n");
	printf("\t9.�����������\n");
	printf("\t10.�ݹ�������\n");
	printf("\t11.�������\n");
	printf("\t12.���������Ч�ʵ����\n");
	printf("\t13.�˳�����\n\n");
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
		printf("\t������ѡ��(����1-12):");
		switch(checkinput())
		{
		case 1://��ʼ��
			{
				status = BST_init(&root);
				if(status)
				{
					printf("\t�ѳɹ���ʼ��!\n");
				}
				break;
			}
		case 2://����Ԫ��
			{
				if(&root == NULL)
				{
					printf("\t��������!Ҫ�ȳ�ʼ��!\n");
					//BST_init(tree);
					//return failed;
				}
				else
				{
					printf("\t������Ҫ��������֣�");
					scanf("%d", e);
					//printf("Ҫ���������Ϊ%d", *e);
					status = BST_insert(&root, e);
					if(status)
					{
						printf("\tԪ��%d�ѳɹ�����!\n", *e);
					}
					else printf("\t����ʧ��!\n");
				}
				break;
			}
		case 3://ɾ��ָ��Ԫ��
			{
				if(&root == NULL)
				{
					printf("\t��������!Ҫ�ȳ�ʼ��!\n");
				}
				else
				{
					printf("\t������Ҫɾ�������֣�");
					scanf("%d", d);
					status = BST_delete(&root, d);
					if(status)
					{
						printf("\t�ɹ�ɾ����Ԫ��%d!\n", *d);
					}
					else printf("\tɾ��ʧ��!\n", *d);
				}
				break;
			}
		case 4://����Ԫ��
			{
				if(&root == NULL)
				{
					printf("\t��������!Ҫ�ȳ�ʼ��!\n");
				}
				else
				{
					printf("\t������Ҫ���ҵ����֣�");
					scanf("%d", s);
					status = BST_search(&root, s);
					if(status)
					{
						printf("\t�������ҵ���Ԫ��%d!\n", *s);
					}
					else printf("\tԪ��%d��������!\n", *s);
				}
				break;
			}
		case 5://����ǰ�����
			{
				if(&root == NULL)
				{
					printf("\t��������!Ҫ�ȳ�ʼ��!\n");
				}
				else
				{
					printf("����ǰ��������Ϊ��");
					status = BST_preorderI(&root, &visit);
					if(status)
					{
						printf("\t�������!\n");
					}
					else printf("\t����ʧ��!\n");
				}
				break;
			}
		case 6://�ݹ�ǰ�����
			{
				if(&root == NULL)
				{
					printf("\t��������!Ҫ�ȳ�ʼ��!\n");
				}
				else
				{
					printf("�ݹ�ǰ��������Ϊ��");
					status = BST_preorderR(&root, &visit);
					if(status)
					{
						printf("\t�������!\n");
					}
					else printf("\t����ʧ��!\n");
				}
				break;
			}
		case 7://�����������
			{
				if(&root == NULL)
				{
					printf("\t��������!Ҫ�ȳ�ʼ��!\n");
				}
				else
				{
					printf("��������������Ϊ��");
					status = BST_inorderI(&root, &visit);
					if(status)
					{
						printf("\t�������!\n");
					}
					else printf("\t����ʧ��!\n");
				}
				break;
			}
		case 8://�ݹ��������
			{
				if(&root == NULL)
				{
					printf("\t��������!Ҫ�ȳ�ʼ��!\n");
				}
				else
				{
					printf("�ݹ�����������Ϊ��");
					status = BST_inorderR(&root, &visit);
					if(status)
					{
						printf("\t�������!\n");
					}
					else printf("\t����ʧ��!\n");
				}
				break;
			}
		case 9://�����������
			{
				if(&root == NULL)
				{
					printf("\t��������!Ҫ�ȳ�ʼ��!\n");
				}
				else
				{
					printf("��������������Ϊ��");
					status = BST_postorderI(&root, &visit);
					if(status)
					{
						printf("\t�������!\n");
					}
					else printf("\t����ʧ��!\n");
				}
				break;
			}
		case 10://�ݹ�������
			{
				if(&root == NULL)
				{
					printf("\t��������!Ҫ�ȳ�ʼ��!\n");
				}
				else
				{
					printf("�ݹ����������Ϊ��");
					status = BST_postorderR(&root, &visit);
					if(status)
					{
						printf("\t�������!\n");
					}
					else printf("\t����ʧ��!\n");
				}
				break;
			}
		case 11://�������
			{
				if(&root == NULL)
				{
					printf("\t��������!Ҫ�ȳ�ʼ��!\n");
				}
				else
				{
					printf("����������Ϊ��");
					status = BST_levelOrder(&root, &visit);
					if(status)
					{
						printf("\t�������!\n");
					}
					else printf("\t����ʧ��!\n");
				}
				break;
			}
		case 12://���������Ч�ʵ����
			{
				printf("��ǰ�����Ϊ��%d\n", getBSTdepth(&root));
				break;
			}
		case 13://�˳�����
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
