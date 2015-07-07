#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//求二叉树的深度
int TreeDepth(TreePNode root)
{
    if (root == NULL)
    {
        return 0;
    }

    int nLeft = TreeDepth(root->lchild);
    int nRight = TreeDepth(root->rchild);
    {
        return 0;
    }

    int nLeft = TreeDepth(root->lchild);
    int nRight = TreeDepth(root->rchild);

    return nLeft > nRight ? (nLeft + 1) : (nRight + 1);
}

//判断一棵树是否是平衡二叉树
bool IsBalanced(TreePNode root, int* pDepth)
{      
    if (root == NULL)
    {
        *pDepth = 0;
        return true;       
    }                      
                           
    int left, right;       
    if (IsBalanced(root->lchild, &left) 
        && IsBalanced(root->rchild, &right))
    {
        int diff = left - right;
        if (diff <= 1 && diff >= -1)
        {
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }
    return false;
} 
