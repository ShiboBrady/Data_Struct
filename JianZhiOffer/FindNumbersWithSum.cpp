#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool FindNumsWithSum(int a[], int length, int sum, int* num1, int* num2)
{
    bool result = false;

    if (NULL == a || length < 1 || num1 == NULL || num2 == NULL)
    {
        return result;
    }

    int head = 0;
    int behind = length - 1;

    while (behind > head)
    {
        long long curSum = a[head] + a[behind];
        if (curSum == sum)
        {
            *num1 = a[head];
            *num2 = a[behind];
            result = true;
            break;
        }
        else if (curSum < sum)
        {
            ++head;
        }
        else
        {
            --behind;
        }

    }

    return result;
}
