#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "SortAlgorithms.h" // ��֮ǰд��ͷ�ļ�

using namespace std;
using namespace chrono;

// ��ӡ����
void PrintArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

// ����ĳ�������㷨����ʱ��
template <typename Func>
void TestSort(const string& name, Func sortFunc, vector<int> arr) {
    cout << "==================== " << name << " ====================\n";

    cout << "����ǰ: ";
    PrintArray(arr);

    auto start = high_resolution_clock::now();
    sortFunc(arr.data(), arr.size()); // ����������
    auto end = high_resolution_clock::now();

    cout << "�����: ";
    PrintArray(arr);

    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "��ʱ: " << duration << " ms\n\n";
}

int main() {
    // �������ݣ���� + �̶���Χ��
    vector<int> data = { 64, 25, 12, 22, 11, 90, 33, 78, 56, 45, 1, 99, 0 };

    // Ϊ�˱�֤ÿ���㷨��ͬ���ĳ�ʼ���ݣ�����ÿ�δ�����
    TestSort("ֱ�Ӳ�������", DirectInsertionSort, data);
    TestSort("�۰��������", BinaryInsertionSort, data);
    TestSort("ϣ������", ShellSort, data);
    TestSort("ð������", BubbleSort, data);
    TestSort("��������", QuickSort, data);
    TestSort("ѡ������", SelectionSort, data);
    TestSort("������", HeapSort, data);
    TestSort("�鲢����", MergeSort, data);
    TestSort("��������", RadixSort, data);

    return 0;
}
