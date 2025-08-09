#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

// 直接插入排序
// 功能：对整数数组arr进行直接插入排序（升序）
// 参数：arr - 待排序的整数数组；n - 数组元素个数
void DirectInsertionSort(int arr[], int n);

// 折半插入排序
// 功能：对整数数组arr进行折半插入排序（升序）
// 参数：arr - 待排序的整数数组；n - 数组元素个数
void BinaryInsertionSort(int arr[], int n);

// 希尔排序
// 功能：对整数数组arr进行希尔排序（升序）
// 参数：arr - 待排序的整数数组；n - 数组元素个数
void ShellSort(int arr[], int n);

// 冒泡排序
// 功能：对整数数组arr进行冒泡排序（升序）
// 参数：arr - 待排序的整数数组；n - 数组元素个数
void BubbleSort(int arr[], int n);

// 快速排序
// 功能：对整数数组arr进行快速排序（升序）
// 参数：arr - 待排序的整数数组；n - 数组元素个数
void QuickSort(int arr[], int n);

// 选择排序
// 功能：对整数数组arr进行选择排序（升序）
// 参数：arr - 待排序的整数数组；n - 数组元素个数
void SelectionSort(int arr[], int n);

// 堆排序
// 功能：对整数数组arr进行堆排序（升序）
// 参数：arr - 待排序的整数数组；n - 数组元素个数
void HeapSort(int arr[], int n);

// 归并排序
// 功能：对整数数组arr进行归并排序（升序）
// 参数：arr - 待排序的整数数组；n - 数组元素个数
void MergeSort(int arr[], int n);

// 基数排序
// 功能：对整数数组arr进行基数排序（升序，仅支持非负整数）
// 参数：arr - 待排序的整数数组；n - 数组元素个数
void RadixSort(int arr[], int n);




#endif // SORT_ALGORITHMS_H
