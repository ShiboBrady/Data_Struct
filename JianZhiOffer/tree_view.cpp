#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode
{
	int value;
	TreeNode* lchild;
	TreeNode* rchild;
};

typedef TreeNode* TreePNode;

//非递归先序遍历
void preorder_non_recursive(TreePNode root)
{
	stack<TreePNode> nodeStack;
	TreePNode node = root;
	while (node != NULL || !nodeStack.empty())
	{
		while (node != NULL)
		{
			printf("%d\t", node->value);
			nodeStack.push(node);
			node = node->lchild;
		}

		if (!nodeStack.empty())
		{
			node = nodeStack.top();
			nodeStack.pop();
			node = node->rchild;
		}
	}
	printf("\n");
}

//非递归中序遍历
void inorder_non_recursive(TreePNode root)
{
	stack<TreePNode> nodeStack;
	TreePNode node = root;

	while (node != NULL || !nodeStack.empty())
	{
		while (node != NULL)
		{
			nodeStack.push(node);
			node = node->lchild;
		}
		if (!nodeStack.empty())
		{
			node = nodeStack.top();
			printf("%d\t", node->value);
			nodeStack.pop();
			node = node->rchild;
		}
	}
	printf("\n");
}

//非递归后序遍历
void beorder_non_recursive(TreePNode root)
{
	TreePNode pre = NULL;
	TreePNode cur = NULL;
	stack<TreePNode> nodeStack;
	nodeStack.push(root);
	while (!nodeStack.empty())
	{
		cur = nodeStack.top();
		if ((cur->lchild == NULL && cur->rchild == NULL) || (pre != NULL && (cur->lchild == pre || cur->rchild == pre)))
		{
			printf("%d\t", cur->value);
			pre = cur;
			nodeStack.pop();
		}
		else
		{
			if (cur->rchild != NULL)
			{
				nodeStack.push(cur->rchild);
			}
			if (cur->lchild != NULL)
			{
				nodeStack.push(cur->lchild);
			}
		}
	}
	printf("\n");
}

//广度优先遍历
void FromTopToButton(TreePNode root)
{
	queue<TreePNode> nodeQueue;
	nodeQueue.push(root);

	TreePNode node = NULL;

	while (!nodeQueue.empty())
	{
		node = nodeQueue.front();
		nodeQueue.pop();
		printf("%d\t", node->value);

		if (node->lchild)
		{
			nodeQueue.push(node->lchild);
		}
		if (node->rchild)
		{
			nodeQueue.push(node->rchild);
		}
	}
}

void preorder_recursive(TreePNode root)
{
	if (root)
	{
		printf("%d\n", root->value);
		preorder_recursive(root->lchild);
		preorder_recursive(root->rchild);
	}
}

void inorder_recursive(TreePNode root)
{
	if (root)
	{
		inorder_recursive(root->lchild);
		printf("%d\n", root->value);
		inorder_recursive(root->rchild);
	}
}

void beorder_recursive(TreePNode root)
{
	if (root)
	{
		beorder_recursive(root->lchild);
		beorder_recursive(root->rchild);
		printf("%d\n", root->value);
	}
}

//根据先序遍历和中序遍历得到二叉树
TreePNode GenerateTreeCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	TreePNode root = (TreePNode)malloc(sizeof(TreeNode));
	root->value = startPreorder[0];
	root->lchild = root->rchild = NULL;

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
		{
			return root;
		}
		else
		{
			printf("Invalid input.");
		}
	}

	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != startPreorder[0])
	{
		++rootInorder;
	}
	if (rootInorder == endInorder && *rootInorder != startPreorder[0])
	{
		printf("Invalid input.");
	}

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		//构建左子树
		root->lchild = GenerateTreeCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startInorder)
	{
		//构建右子树
		root->rchild = GenerateTreeCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}

TreePNode GenerateTree(int* preorder, int* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length < 0)
	{
		return NULL;
	}
	TreePNode root;
	root = GenerateTreeCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}