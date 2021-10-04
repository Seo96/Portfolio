#include "StackType.h"
#include <iostream>

using namespace std;
/*
* 4�� a��
void ReplaceItem(StackType& st, int oldItem, int newItem) {
	StackType temp_stack;
	int item;
	while (!st.IsEmpty()) {
		item = st.Top();
		if (item == oldItem) {
			temp_stack.Push(newItem);
		}
		else {
			temp_stack.Push(item);
		}
		st.Pop();
	}
	while (!temp_stack.IsEmpty()) {
		item = temp_stack.Top();
		st.Push(item);
		temp_stack.Pop();
	}
}
*/

int main() {
	StackType stack;
	stack.Push(8);
	stack.Push(3);
	stack.Push(9);
	stack.Push(8);
	stack.Push(3);
	stack.Push(7);
	stack.Push(5);
	stack.Push(3);
	// ReplaceItem(stack, 3, 5);  4�� a��
	stack.ReplaceItem(3, 5);

	while (!stack.IsEmpty()) {
		int item = stack.Top();
		stack.Pop();
		cout << "Item : " << item << endl;
		
	}
	return 0;
}