#include "soft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//交换函数
void Swap(int* a, int* b)
{
    if (a == NULL || b == NULL)
    {
        return;
    }

    int temp = *a;
    *a = *b;
    *b = temp;
}

//生成某个范围内随机数函数
int RandomInRange(int start, int end)
{
    int length = end - start + 1;
    srand(time(NULL));
    return (rand() % length) + start;
}

//直接插入排序
void InsertSort(int a[], int length)
{
    if (a == NULL || length < 2)
    {
        return;
    }
    int i;
    int j;
    int temp;
    for (i = 1; i < length; ++i)
    {
        j = i - 1;
        temp = a[i];
        while (j >= 0 && temp > a[j])
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = temp;
    }
}

//折半插入排序
void BinarySort(int a[], int length)
{
    if (a == NULL || length < 2)
    {
        return;
    }

    int i;
    int j;
    int temp;
    int low;
    int mid;
    int high;

    for (i = 1; i < length; ++i)
    {
        temp = a[i];
        low = 0;
        high = i - 1;

        while (low <= high)
        {
            mid = (low + high) >> 2;
            if (a[mid] > temp)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        for (j = i - 1; j >= high; --j)
        {
            a[j + 1] = a[j];
        }

        a[high] = temp;
    }
}

//希尔排序
void ShellSort(int a[], int length)
{
    if (a == NULL || length < 2)
    {
        return;
    }

    int i;
    for (i = length >> 2; i > 0; --i)
    {
        ShellSortCore(a, length, i);
    }
}

void ShellSortCore(int a[], int length, int step)
{
    int i;
    int j;
    int temp;
    for (i = step; i < length; ++i)
    {
        j = i - step;
        temp = a[i];
        while (j >= 0 && temp > a[j])
        {
            a[j + step] = a[j];
            j -= step;
        }
        a[j + step] = temp;
    }
}

//冒泡排序
void BobbleSort(int a[], int length)
{
    if (a == NULL || length < 2)
    {
        return;
    }

    int i;
    int j;
    bool bIsSwap = false;
    for (i = 0; i < lengh - 1; ++i)
    {
        for (j = 0; j < length - 1 - i; ++j)
        {
            if (a[j] > a[j + 1])
            {
                Swap(&a[j], &a[j + 1]);
                bIsSwap = true;
            }
        }
        if (bIsSwap == false)
        {
            break;
        }
    }
}

//冒泡排序加强版
void BobbleSort2(int a[], int length)
{
    int low = 0;
    int high = length - 1;
    int i;
    int j;

    while (low < high)
    {
        for (i = low; i < high; ++i)
        {
            if (a[i] > a[i + 1])
            {
                Swap(&a[i], &a[i + 1]);
            }
        }
        --high;

        for (j = high; j > low; --j)
        {
            if (a[j] < a[j - 1])
            {
                Swap(&a[j], &a[j - 1]);
            }
        }
        ++low;
    }
}


//快速排序
void QuickSort(int a[], int length)
{
    if (a == NULL || length < 2)
    {
        return;
    }

    QuickSortCore(a, length, 0, length - 1);
}

void QuickSortCore(int a[], int lenght, int low, int high)
{
    int position = Particial(a, length, low, high);
    if (low < position)
    {
        QuickSortCore(a, length, low, position - 1);
    }
    if (high > position)
    {
        QuickSortCore(a, length, position + 1, high);
    }
}

int Particial(int a[], int length, int low, int high)
{
    if (a == NULL || length < 2 || low < 0 || high >= length)
    {
        return;
    }
    
    int index = RandomInRange(low, high);
    Swap(&a[index], &a[high]);

    int i;
    int small = low - 1;
    for (i = low; i < high; ++i)
    {
        if (a[i] < a[high])
        {
            ++small;
            if (i != small)
            {
                Swap(&a[i], &a[small]);
            }
        }
    }

    ++small;
    Swap(&a[small], &a[high]);
    return small;
}

//简单选择排序
void ChooseSort(int a[], int length)
{
    int i;
    int j;
    int k;
    for (i = 0; i < n - 1; ++i)
    {
        k = i;
        for (j = i + 1; j < n; ++j)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }

        if (k != i)
        {
            Swap(&a[i], &a[k]);
        }
    }
}

//堆排序
void HeapSort(int a[], int length)
{
    int i;
    for (i = (length - 1) >> 2; i >= 0; --i)
    {
        HeapSortCore(a, i, length - 1);
    }

    for (i = length - 1; i > 0; --i)
    {
        Swap(&a[i], &a[0]);
        HeapSortCore(a, 0, i - 1);
    }
}

void HeapSortCore(int a[], int low, int high)
{
    int i = low;
    int j = i * 2 + 1;
    int back = a[i];
    while (j <= high)
    {
        if (j < high && a[j] < a[j + 1])
        {
             ++j;
        }

        if (temp < a[j])
        {
            a[i] = a[j];
            i = j;
            j = i * 2 + 1;
        }
        else
        {
            break;
        }
        a[i] = back;
    }
}

//二路归并排序

int* back_array = NULL;

void MergeSort(int a[], int length)
{
    if (a == NULL || length < 2)
    {
        return;
    }
    back_array = (int*)malloc(length * sizeof(int));
    MergeSortCore(a, 0, length - 1);
    free(back_array);
}

void Merge(int a[], int low, int mid, int high)
{
    memcopy(back_array + low, a + low, sizeof(int) * (high - low + 1));
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        a[k++] = back_array[i] < back_array[j] ? back_array[i++] : back_array[j++];
    }

    while (i <= mid)
    {
        a[k++] = back_array[i++];
    }

    while (j <= high)
    {
        a[k++] = back_array[j++];
    }
}

void MergeSortCore(int a[], int low, int high)
{
    if (a == NULL || low >= high)
    {
        return;
    }
    int mid = (low + high) >> 2;
    MergeSortCore(a, low, mid);
    MergeSortCore(a, mid + 1, high);
    Merge(a, low, mid, high);
}

