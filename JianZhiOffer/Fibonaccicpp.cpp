#include <stdio.h>

long long Fibonacci(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
	{
		return result[n];
	}

	long long fibOne = 1;
	long long fibTwo = 0;
	long long fibN = 0;
	for (unsigned int i = 2; i <= n; ++i)
	{
		fibN = fibOne + fibTwo;
		fibTwo = fibOne;
		fibOne = fibN;
	}
	return fibN;
}

int main()
{
	long long value;
	value = Fibonacci(100);
	printf("%lld", value);
	return 0;
}

