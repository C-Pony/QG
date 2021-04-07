#ifndef CALCUL_H_INCLUDE
#define CALCUL_H_INCLUDE

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef char ElemType;

typedef struct StackNode
{
	ElemType data;
	struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int	count;
} LinkStack;

//����ȫ�ֱ���
extern ElemType pr[];

//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *s,ElemType *e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *s);//���ջ
Status destroyLStack(LinkStack *s);//����ջ
Status LStackLength(LinkStack *s,int *length);//���ջ����
Status pushLStack(LinkStack *s,ElemType data);//��ջ
Status popLStack(LinkStack *s,ElemType *pdata);//��ջ
int checkinput();//���Ƿ�����

//����ջ���������������������
int precedence(char a);//�жϷ������ȼ�
ElemType converInfixExpression(LinkStack *s, ElemType a[]);//����׺���ʽת��Ϊ��׺���ʽ
ElemType CalculSuffixExpression(LinkStack *s);//�����׺���ʽ

#endif