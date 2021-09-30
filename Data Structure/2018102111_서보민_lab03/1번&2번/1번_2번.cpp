#include "sorted.h"
#include <iostream>
using namespace std;

ItemType item;
void MergeList(SortedType, SortedType, SortedType&);
int BinarySearch_a(int array[], int sizeOfArray, int value);
int BinarySearch_b(int array[], int sizeOfArray, int value);
int BinarySearch_c(int array[], int sizeOfArray, int value);

int main() {
    //1�� test�ڵ�
    SortedType s_list1, s_list2, s_list3;
    ItemType item1, item2, item3, item4;
    item1.Initialize(2);
    item2.Initialize(5);
    item3.Initialize(7);
    item4.Initialize(9);
    s_list1.InsertItem(item1);
    s_list1.InsertItem(item3);
    s_list2.InsertItem(item2);
    s_list2.InsertItem(item4);
    MergeList(s_list1, s_list2, s_list3);
    s_list3.Print();
    cout << endl;

    // 2�� test code
    int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int result = BinarySearch_a(list, sizeof(list) / sizeof(list[0]), 11);
    cout << result << endl;
    result = BinarySearch_a(list, sizeof(list) / sizeof(list[0]), 7);
    cout << result << endl;
    int list2[7] = { 2,4,5,6,8,9,10 };
    int result2 = BinarySearch_b(list2, sizeof(list2) / sizeof(list2[0]), 7);
    int result3 = BinarySearch_c(list2, sizeof(list2) / sizeof(list2[0]), 7);
    cout << result2 << endl;
    cout << result3 << endl;
}

// 1�� ���� a
void MergeList(SortedType list1, SortedType list2, SortedType& result) {
    //�Լ� : 2�������� ����Ʈ�� Merge�ؼ� �� ��° ���� ����Ʈ�������.
    //���� : list1�� list2�� �ʱ�ȭ�Ǿ� �ְ� ComparedTo ��� �Լ��� ����ؼ� Ű�� ���� ���ĵǾ� �ִ�. list1�� list2�� ���� Ű�� ���� �ʴ´�.
    //��� : ����� list1�� list2�� ��� ��Ҹ� ���� ���� ����Ʈ�̴�.
    list1.ResetList();
    list2.ResetList();
    result.ResetList();
    int length1 = list1.LengthIs();
    int length2 = list2.LengthIs();
    for (int i = 0; i < length1; i++) {
        list1.GetNextItem(item);
        result.InsertItem(item);
    }
    for (int i = 0; i < length2; i++) {
        list2.GetNextItem(item);
        result.InsertItem(item);
    }
}
/* 1�� ���� b
ResetList O(1) + O(1) + O(1) = O(1)
LengthIs  O(1) + O(1) = O(1)
GetNextItem O(N)
InsertItem  O(N)
*/

// 2�� ����
int BinarySearch_a(int array[], int sizeOfArray, int value) {
    int midPoint;
    int first = 0;
    int last = (sizeOfArray - 1);
    bool moreToSearch = (first <= last);
    bool found = false;
    int Pos = -1;
    while (moreToSearch && !found) {
        midPoint = (first + last) / 2;
        if (array[midPoint] > value) {
            last = midPoint - 1;
            moreToSearch = (first <= last);
        }
        else if (array[midPoint] < value) {
            first = midPoint + 1;
            moreToSearch = (first <= last);
        }
        else {
            found = true;
            Pos = midPoint;
            break;
        }
    }
    if (!found)
        Pos = -1;
    return Pos;
}
int BinarySearch_b(int array[], int sizeOfArray, int value) {
    int midPoint;
    int first = 0;
    int last = (sizeOfArray - 1);
    bool moreToSearch = (first <= last);
    bool found = false;
    int Pos = -1;
    while (moreToSearch && !found) {
        midPoint = (first + last) / 2;
        if (array[midPoint] > value) {
            last = midPoint - 1;
            moreToSearch = (first <= last);
        }
        else if (array[midPoint] < value) {
            first = midPoint + 1;
            moreToSearch = (first <= last);
        }
        else {
            found = true;
            Pos = midPoint;
            break;
        }
    }
    if (!found)
        Pos = last;
    return array[Pos];
}

int BinarySearch_c(int array[], int sizeOfArray, int value) {
    int midPoint;
    int first = 0;
    int last = (sizeOfArray - 1);
    bool moreToSearch = (first <= last);
    bool found = false;
    int Pos = -1;
    while (moreToSearch && !found) {
        midPoint = (first + last) / 2;
        if (array[midPoint] > value) {
            last = midPoint - 1;
            moreToSearch = (first <= last);
        }
        else if (array[midPoint] < value) {
            first = midPoint + 1;
            moreToSearch = (first <= last);
        }
        else {
            found = true;
            Pos = midPoint;
            break;
        }
    }
    if (!found)
        Pos = first;

    return array[Pos];
}