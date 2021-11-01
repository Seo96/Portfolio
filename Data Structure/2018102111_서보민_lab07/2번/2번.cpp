#include "StackType.h"
#include <iostream>
using namespace std;

int main() {
	StackType stack1, stack2;
	stack1.Push(2); stack1.Push(4);
	stack1.Push(6); stack1.Push(8);
	cout << "stack1�� ��� �߰� �� stack2 copy" << endl;
	stack1.Print();
	cout << endl;

	stack2.Copy(stack1);
	
	stack1.Push(1); stack1.Push(3);
	cout << "copy�� stack1�� ��� �߰�" << endl;
	stack1.Print();
	cout << endl;
	cout << "stack2 ��� ���" << endl;
	while (!stack2.IsEmpty()) {
		int Item = stack2.Top();
		stack2.Pop();
		cout << Item << " ";
	}
	cout << endl;
	cout << "stack1�� �ּ� :" << &stack1 << endl;
	cout << "stack2�� �ּ� :" << &stack2 << endl;

}