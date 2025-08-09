#include "SortAlgorithms.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// 1. 直接插入排序
void DirectInsertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = temp;
	}
}

// 2. 折半插入排序
void BinaryInsertionSort(int arr[], int n) {
	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		int left = 0, right = i - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr[mid] > key) right = mid - 1;
			else left = mid + 1;
		}
		for (int j = i - 1; j >= left; --j)
			arr[j + 1] = arr[j];
		arr[left] = key;
	}
}
// 3.希尔排序
void ShellSort(int arr[], int n) {
	// gap 表示当前分组的间隔，初始为 n/2，每次缩小一半
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		// 从 gap 位置开始，依次对每个元素做插入排序
		// 注意：这里不是普通插入排序的相邻比较，而是跨 gap 比较
		for (int i = gap; i < n; i++)
		{
			int temp = arr[i]; // 暂存
			int j = i;         // j 用来在分组中向前比较

			// 在当前分组中向前找合适位置
			// 条件1: j >= gap   说明 j-gap 位置存在(防止越界)
			// 条件2: arr[j-gap] > temp   表示前一个同组元素比当前值大，需要向后移
			while (j >= gap && arr[j - gap] > temp)
			{
				arr[j] = arr[j - gap]; // 元素后移 gap 位
				j -= gap;              // 继续向 gap 距离的前面比较
			}

			// 找到合适位置后，把 temp 放进去
			arr[j] = temp;
		}
	}
}

// 4. 冒泡排序
// 时间复杂度 O(n^2)，稳定排序
void BubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		bool swapped = false; // 标记本轮是否发生交换
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) 
			break; // 如果一轮下来没交换，说明已排序好
	}
}

// 5. 快速排序（递归实现）
// 平均时间复杂度 O(n log n)，不稳定
// 用 Lomuto 分区法（以最后一个元素为p： pivot）
void QuickSortHelper(int arr[], int left, int right) {
	if (left >= right) return;

	int pivot = arr[right]; // 选取最右元素为基准
	int i = left - 1;       // i 指向小于 pivot 区域的末尾
	for (int j = left; j < right; j++) {
		if (arr[j] < pivot) {
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[right]); // 把 pivot 放到正确位置
	int p = i + 1;

	QuickSortHelper(arr, left, p - 1); // 递归左区间
	QuickSortHelper(arr, p + 1, right);// 递归右区间
}

void QuickSort(int arr[], int n) {
	QuickSortHelper(arr, 0, n - 1);
}

// 6. 选择排序
// 时间复杂度 O(n^2)，不稳定
void SelectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i; // 假设当前 i 是最小
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j; // 找到更小值
			}
		}
		if (minIndex != i) {
			std::swap(arr[i], arr[minIndex]); // 把最小值放到当前位置
		}
	}
}


// 7. 堆排序
// 辅助函数：维护最大堆
void Heapify(int arr[], int n, int i) {
	int largest = i;       // 假设当前节点最大
	int left = 2 * i + 1;  // 左子节点索引
	int right = 2 * i + 2; // 右子节点索引

	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;

	// 如果最大值不是当前节点，则交换并递归下沉
	if (largest != i) {
		swap(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}

void HeapSort(int arr[], int n) {
	// 1. 建立最大堆（从最后一个非叶子节点开始下沉）
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(arr, n, i);
	}

	// 2. 逐步把堆顶最大值交换到数组末尾，并调整堆
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);      // 将最大值移到末尾
		Heapify(arr, i, 0);        // 调整剩余元素为最大堆
	}
}

//8. 归并排序
// 合并两个有序区间
void Merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1; // 左区间长度
	int n2 = right - mid;    // 右区间长度

	vector<int> L(n1), R(n2);
	for (int i = 0; i < n1; i++) L[i] = arr[left + i];
	for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) arr[k++] = L[i++];
		else arr[k++] = R[j++];
	}

	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];
}

void MergeSortHelper(int arr[], int left, int right) {
	if (left >= right) return;

	int mid = left + (right - left) / 2;
	MergeSortHelper(arr, left, mid);
	MergeSortHelper(arr, mid + 1, right);
	Merge(arr, left, mid, right);
}

void MergeSort(int arr[], int n) {
	MergeSortHelper(arr, 0, n - 1);
}

// 9. 基数排序
// 仅支持非负整数
int GetMax(int arr[], int n) {
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx) mx = arr[i];
	return mx;
}

void CountSort(int arr[], int n, int exp) {
	vector<int> output(n);
	int count[10] = { 0 };

	// 按当前位 (exp) 统计出现次数
	for (int i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// 累积和，计算位置
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// 稳定排序：从后往前放入 output
	for (int i = n - 1; i >= 0; i--) {
		int idx = (arr[i] / exp) % 10;
		output[count[idx] - 1] = arr[i];
		count[idx]--;
	}

	// 复制回原数组
	for (int i = 0; i < n; i++)
		arr[i] = output[i];
}

void RadixSort(int arr[], int n) {
	int m = GetMax(arr, n); // 找到最大值，确定位数

	// 按位排序，从个位到最高位
	for (int exp = 1; m / exp > 0; exp *= 10)
		CountSort(arr, n, exp);
}

