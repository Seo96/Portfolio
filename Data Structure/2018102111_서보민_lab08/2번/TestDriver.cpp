#include <iostream>
using namespace std;

/*
��͹����� �� ��ȿ�����̶�� �����մϴ�.
��� �������� ������ n��° ��Ҹ� ���ϱ� ���ؼ��� n-1, n-2�� �Ű������� ������
2���� �Լ��� ȣ���ؾ��ϸ� n-1, n-2�� 0 �Ǵ� 1�� �� ������ ���� ������ �ݺ��Ͽ� �Լ��� ȣ���Ͽ����մϴ�.
������ �� ��͹����� �迭�� ���Ͽ� �����Ѵٸ�, ���� �� ��Ҹ� ���Ͽ� n��° ��Ҹ� ���ϱ� ������
������ ����� �پ��� ������ �� ��͹����� �� ȿ�����̶�� �����մϴ�.
*/

int Fibonacci_recursive(int n);
int Fibonacci_non_recursive(int n);

int main() {
	cout << Fibonacci_recursive(10) << endl;
	cout << Fibonacci_non_recursive(10) << endl;
	return 0;

}

int Fibonacci_recursive(int n) {
	if (n == 1 || n == 0) 
		return n; 
	return Fibonacci_recursive(n - 1) + Fibonacci_recursive(n - 2);
}

int Fibonacci_non_recursive(int n) {
	int *fibo = new int[n + 1];
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i < n + 1; i++) {
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}
	return fibo[n];
	delete[] fibo;
}