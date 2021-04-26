//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define BST_Status int
#define MaxSize 50

typedef int ElemType;

typedef struct BST_Node{
    ElemType value;
    struct BST_Node *left, *right;
}BST_Node, *NodePtr;

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
BST_Status BST_init(NodePtr *pRoot);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
BST_Status BST_insert(NodePtr *pRoot, ElemType *e);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
BST_Status BST_delete(NodePtr *pRoot, ElemType *del);

//左子树中最大的值
ElemType findMax(BST_Node *left) ;

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
BST_Status BST_search(NodePtr *pRoot, ElemType *s);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_preorderI(NodePtr *pRoot, void (*visit)(NodePtr p));

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_preorderR(NodePtr *pRoot, void (*visit)(NodePtr p));

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_inorderI(NodePtr *pRoot, void (*visit)(NodePtr p));

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_inorderR(NodePtr *pRoot, void (*visit)(NodePtr p));

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_postorderI(NodePtr *pRoot, void (*visit)(NodePtr p));

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_postorderR(NodePtr *pRoot, void (*visit)(NodePtr p));

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_levelOrder(NodePtr *pRoot, void (*visit)(NodePtr p));

//计算二叉树效率的深度
ElemType getBSTdepth(NodePtr *pRoot);

//打印 
void visit(NodePtr p);

//检查非法输入
int checkinput();

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
