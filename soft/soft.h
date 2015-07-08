#ifndef __SOFT_H__
#define __SOFT_H__

#include <stdio.h>
#include <stdlib.h>

//直接插入排序
void InsertSort(int a[], int length);

//折半插入排序
void BinarySort(int a[], int length);

//希尔排序
void ShellSort(int a[], int length);

//冒泡排序
void BobbleSort(int a[], int length);

//冒泡排序加强版
void BobbleSort2(int a[], int length);

//快速排序
void QuickSort(int a[], int length);

void QuickSortCore(int a[], int lenght, int low, int high);

int Particial(int a[], int length, int low, int high);

//简单选择排序
void ChooseSort(int a[], int length);

//堆排序
void HeapSort(int a[], int length);

void HeapSortCore(int a[], int low, int high);

//二路归并排序
int* back_array = NULL;

void MergeSort(int a[], int length);

void Merge(int a[], int low, int mid, int high);

void MergeSortCore(int a[], int low, int high);

#endif /*__SOFT_H__*/
