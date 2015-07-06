#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int value;
	ListNode* next;
};

typedef ListNode* ListPNode;

ListPNode MergeTwoList(ListPNode list1, ListPNode list2)
{
	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}

	ListPNode newListHead;
	if (list1->value > list2->value)
	{
		newListHead = list1;
		newListHead->next = MergeTwoList(list1->next, list2);
	}
	else
	{
		newListHead = list2;
		newListHead->next = MergeTwoList(list1, list2->next);
	}

	return newListHead;
}