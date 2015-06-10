//插入类
//直接插入排序
void InsertSort(int* a, int n)
{
	int i, j, temp;
	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		temp = a[i];
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = temp;
	}
}


//折半插入排序
void BinarySort(int* a, int n)
{
	int i, j, temp, low, mid, high;
	for (i = 1; i < n; ++i)
	{
		temp = a[i];
		low = 0;
		high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			
			if (temp < a[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		for (j = i; j > low; ++j)
		{
			a[j] = a[j - 1];
		}
		a[low] = temp;
	}
}

//希尔排序
void ShellSort(int* a, int n)
{
	int i;
	for (i = n / 2; i > 0; --1)
	{
		ShellStep(a, n, i);
	}
}

void ShellStep(int* a, int n, int d)
{
	int i, j, temp;
	for (i = d; i < n; ++i)
	{
		j = i - d;
		temp = a[i];
		while (j >= 0 && a[j] > temp)
		{
			a[j + d] = a[j];
			j -= d;
		}
		a[j + d] = temp;
	}
}

//交换类
//冒泡排序
void BubbleSort(int* a, int n)
{
	int i, j, temp, isSorted = 0;
	for (i = 0; i < n - 1; ++i)
	{
		for (j = 0; j < n - 1 - i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				isSorted = 1;
			}
		}
		if (!isSorted)
		{
			break;
		}
	}
}

//快速排序
void QuickSort(int* a, int n)
{
	int midPos = QuickStep(a, 0, n - 1);
	QuickSort(a, midPos);
	QuickSort(a + midPos + 1, n - midPos - 1);
}

void QuickStep(int* a, int low, int high)
{
	if (low < high)
	{
		int key = a[low];
		while (low < high)
		{
			while (low < high && a[high] > key)
			{
				--high;
			}
			
			if (low < high)
			{
				a[low] = a[high];
				++low;
			}
			
			while (low < high && a[low] < key)
			{
				++low;
			}
			
			if (low < high)
			{
				a[high] = a[low];
				--high;
			}
		}
		a[low] = key;
	}
	return low;
}

//选择类
//简单选择排序
void ChooseSort(int* a, int n)
{
	
}

//堆排序
void HeapSort(int* a, int n)
{
	
}

//归并类
//二路归并排序
void MergeSort(int* a, int n)
{
	
}

