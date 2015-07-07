#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FindTwoNumsAppearOnce(int* a, int length, int* num1, int* num2)
{
    if (a == NULL || length < 2)
    {
        return;
    }

    int resultExclusiveOr = 0;
    for (int i = 0; i < length; ++i)
    {
        resultExclusiveOr ^= a[i];
    }

    unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOr);

    *num1 = *num2 = 0;

    for (int j = 0; j < length; ++j)
    {
        if (isBit1(a[j], indexof1))
        {
            *num1 ^= a[j];
        }
        else
        {
            *num2 ^= a[j];
        }
    }
}

unsigned int FindFirstBitIs1(int num)
{
    int indexBit = 0;
    while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
    {
        num = num >> 1;
        ++indexBit;
    }

    return indexBit;
}

bool isBit1(int num, unsigned int index)
{
    num = num >> index;
    return (num & 0x1);
}
