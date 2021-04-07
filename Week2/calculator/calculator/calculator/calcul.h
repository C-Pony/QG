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

//声明全局变量
extern ElemType pr[];

//链栈
Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s,ElemType *e);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s,int *length);//检测栈长度
Status pushLStack(LinkStack *s,ElemType data);//入栈
Status popLStack(LinkStack *s,ElemType *pdata);//出栈
int checkinput();//检查非法输入

//基于栈链的整数四则运算计算器
int precedence(char a);//判断符号优先级
ElemType converInfixExpression(LinkStack *s, ElemType a[]);//将中缀表达式转化为后缀表达式
ElemType CalculSuffixExpression(LinkStack *s);//计算后缀表达式

#endif