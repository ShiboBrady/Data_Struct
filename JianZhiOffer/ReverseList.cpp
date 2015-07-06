#include <stdio.h>

struct Node
{
	int value;
	Node* next;
};

typedef Node* pNode;

//逆置链表
void ReverseList(pNode* head)
{
	if (head == NULL || (*head)->next == NULL)
	{
		return;
	}

	pNode pre = NULL;
	pNode mid = *head;
	pNode tail = (*head)->next;

	while (tail)
	{
		mid->next = pre;
		pre = mid;
		mid = tail;
		tail = tail->next;
	}

	mid->next = pre;
	*head = mid;
}

//逆向打印链表
void printListReverse(pNode head)
{
	if (head == NULL)
	{
		return;
	}
	else if (head->next == NULL)
	{
		printf("%d\t", head->value);
	}
	else
	{
		printListReverse(head->next);
	}
}

int main()
{
	
}