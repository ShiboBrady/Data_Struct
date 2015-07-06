#include <stdio.h>
#include <iostream>

using namespace std;

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void ReorderOddEven(int* a, unsigned int n, bool (*func)(int))
{
	if (a == NULL || n == 0)
	{
		return;
	}
	int* pBegin = a;
	int* pEnd = a + n - 1;

	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin))
		{
			++pBegin;
		}

		while (pBegin < pEnd && func(*pEnd))
		{
			--pEnd;
		}

		if (pBegin != pEnd)
		{
			Swap(pBegin, pEnd);
		}
	}
}

bool isEven(int n)
{
	return (n & 0x1) == 0;
}

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	ReorderOddEven(a, 5, isEven);
	for (auto i : a)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}