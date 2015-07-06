#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int*a, int n, int value)
{
	int low = 0;
	int high = n - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == value)
		{
			return mid;
		}
		else if (a[mid] < value)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int position = BinarySearch(a, 10, 10);
	if (-1 != position)
		printf("%d\n", a[position]);
	return 0;
}