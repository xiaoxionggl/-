#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "SortAlgorithms.h" // 你之前写的头文件

using namespace std;
using namespace chrono;

// 打印数组
void PrintArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

// 测试某个排序算法并测时间
template <typename Func>
void TestSort(const string& name, Func sortFunc, vector<int> arr) {
    cout << "==================== " << name << " ====================\n";

    cout << "排序前: ";
    PrintArray(arr);

    auto start = high_resolution_clock::now();
    sortFunc(arr.data(), arr.size()); // 调用排序函数
    auto end = high_resolution_clock::now();

    cout << "排序后: ";
    PrintArray(arr);

    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "耗时: " << duration << " ms\n\n";
}

int main() {
    // 测试数据（随机 + 固定范围）
    vector<int> data = { 64, 25, 12, 22, 11, 90, 33, 78, 56, 45, 1, 99, 0 };

    // 为了保证每个算法用同样的初始数据，这里每次传副本
    TestSort("直接插入排序", DirectInsertionSort, data);
    TestSort("折半插入排序", BinaryInsertionSort, data);
    TestSort("希尔排序", ShellSort, data);
    TestSort("冒泡排序", BubbleSort, data);
    TestSort("快速排序", QuickSort, data);
    TestSort("选择排序", SelectionSort, data);
    TestSort("堆排序", HeapSort, data);
    TestSort("归并排序", MergeSort, data);
    TestSort("基数排序", RadixSort, data);

    return 0;
}
