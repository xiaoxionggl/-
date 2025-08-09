#include "SortAlgorithms.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// 1. ֱ�Ӳ�������
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

// 2. �۰��������
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
// 3.ϣ������
void ShellSort(int arr[], int n) {
	// gap ��ʾ��ǰ����ļ������ʼΪ n/2��ÿ����Сһ��
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		// �� gap λ�ÿ�ʼ�����ζ�ÿ��Ԫ������������
		// ע�⣺���ﲻ����ͨ������������ڱȽϣ����ǿ� gap �Ƚ�
		for (int i = gap; i < n; i++)
		{
			int temp = arr[i]; // �ݴ�
			int j = i;         // j �����ڷ�������ǰ�Ƚ�

			// �ڵ�ǰ��������ǰ�Һ���λ��
			// ����1: j >= gap   ˵�� j-gap λ�ô���(��ֹԽ��)
			// ����2: arr[j-gap] > temp   ��ʾǰһ��ͬ��Ԫ�رȵ�ǰֵ����Ҫ�����
			while (j >= gap && arr[j - gap] > temp)
			{
				arr[j] = arr[j - gap]; // Ԫ�غ��� gap λ
				j -= gap;              // ������ gap �����ǰ��Ƚ�
			}

			// �ҵ�����λ�ú󣬰� temp �Ž�ȥ
			arr[j] = temp;
		}
	}
}

// 4. ð������
// ʱ�临�Ӷ� O(n^2)���ȶ�����
void BubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		bool swapped = false; // ��Ǳ����Ƿ�������
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) 
			break; // ���һ������û������˵���������
	}
}

// 5. �������򣨵ݹ�ʵ�֣�
// ƽ��ʱ�临�Ӷ� O(n log n)�����ȶ�
// �� Lomuto �������������һ��Ԫ��Ϊp�� pivot��
void QuickSortHelper(int arr[], int left, int right) {
	if (left >= right) return;

	int pivot = arr[right]; // ѡȡ����Ԫ��Ϊ��׼
	int i = left - 1;       // i ָ��С�� pivot �����ĩβ
	for (int j = left; j < right; j++) {
		if (arr[j] < pivot) {
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[right]); // �� pivot �ŵ���ȷλ��
	int p = i + 1;

	QuickSortHelper(arr, left, p - 1); // �ݹ�������
	QuickSortHelper(arr, p + 1, right);// �ݹ�������
}

void QuickSort(int arr[], int n) {
	QuickSortHelper(arr, 0, n - 1);
}

// 6. ѡ������
// ʱ�临�Ӷ� O(n^2)�����ȶ�
void SelectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i; // ���赱ǰ i ����С
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j; // �ҵ���Сֵ
			}
		}
		if (minIndex != i) {
			std::swap(arr[i], arr[minIndex]); // ����Сֵ�ŵ���ǰλ��
		}
	}
}


// 7. ������
// ����������ά������
void Heapify(int arr[], int n, int i) {
	int largest = i;       // ���赱ǰ�ڵ����
	int left = 2 * i + 1;  // ���ӽڵ�����
	int right = 2 * i + 2; // ���ӽڵ�����

	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;

	// ������ֵ���ǵ�ǰ�ڵ㣬�򽻻����ݹ��³�
	if (largest != i) {
		swap(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}

void HeapSort(int arr[], int n) {
	// 1. �������ѣ������һ����Ҷ�ӽڵ㿪ʼ�³���
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(arr, n, i);
	}

	// 2. �𲽰ѶѶ����ֵ����������ĩβ����������
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);      // �����ֵ�Ƶ�ĩβ
		Heapify(arr, i, 0);        // ����ʣ��Ԫ��Ϊ����
	}
}

//8. �鲢����
// �ϲ�������������
void Merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1; // �����䳤��
	int n2 = right - mid;    // �����䳤��

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

// 9. ��������
// ��֧�ַǸ�����
int GetMax(int arr[], int n) {
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx) mx = arr[i];
	return mx;
}

void CountSort(int arr[], int n, int exp) {
	vector<int> output(n);
	int count[10] = { 0 };

	// ����ǰλ (exp) ͳ�Ƴ��ִ���
	for (int i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// �ۻ��ͣ�����λ��
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// �ȶ����򣺴Ӻ���ǰ���� output
	for (int i = n - 1; i >= 0; i--) {
		int idx = (arr[i] / exp) % 10;
		output[count[idx] - 1] = arr[i];
		count[idx]--;
	}

	// ���ƻ�ԭ����
	for (int i = 0; i < n; i++)
		arr[i] = output[i];
}

void RadixSort(int arr[], int n) {
	int m = GetMax(arr, n); // �ҵ����ֵ��ȷ��λ��

	// ��λ���򣬴Ӹ�λ�����λ
	for (int exp = 1; m / exp > 0; exp *= 10)
		CountSort(arr, n, exp);
}

