#include <stdio.h>
#include "soft.c"

const static int N = 10;

void display(int* a, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[N] = {35, 67, 93, 25, 19, 5, 38, 79, 29, 8};
	
	
	display(a, N);
	return 0;
}