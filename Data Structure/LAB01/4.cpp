//#define MAX_ROWS 50
//#define MAX_COLS 50

#include <iostream>

using namespace std;


//#define MAX_ROWS 50
//#define MAX_COLS 50
const int MAX_ROWS = 50;
class SquareMatrix // n x n (최대 50)의 정사각형 매트릭스를 갖고있다.
{
private:
	int matrix[50][50];
public: 
	void MakeEmpty(int); // 기능: 매트릭스의 n행 n열까지 0으로 초기화 시킨다. 조건: n의 최대 크기는 50이다. 결과 : n행 n열까지 모두 0으로 초기화된다.
	void StoreValue(int, int, int); //기능: 매트릭스의 n_1행, n_2열에 n_3값을 저장한다. 조건 : n_1과 n_2의 최대 크기는 50이며 n_3는 정수이다. 결과 : n_1행, n_2열에 n_3값이 저장된다.
	void Add(SquareMatrix&, SquareMatrix&); // 기능: self의 각 행렬값과 a의 각 행렬값을 더하여 b의 각 행렬값에 저장한다. 조건: self에서 a을 더한 결과가 b이다.  결과: 두 행렬의 합이 b에 저장된다.
	void Subtract(SquareMatrix&, SquareMatrix&); // 기능: self의 각 행렬값으로부터 a의 각 행렬값을 빼 b의 각 행렬값에 저장한다. 조건 : self에서 a를 뺀 결과가 b이다. 결과: 두 행렬의 차가 b에 저장된다.
	void Copy(SquareMatrix&); // 기능: self의 각 행렬값을 a의 각 행렬값에 저장시킨다. 조건 : 두 행렬의 크기가 같다. 결과 : a의 행렬값이 self의 행렬값과 동일해진다.
	void Print();// 기능: 50 x 50의 매트릭스를 출력한다. 조건 : 행렬이 초기화 되어야 한다. 결과 : 매트릭스가 행렬의 순서를 맞춰 화면에 출력된다.
};

void SquareMatrix::MakeEmpty(int n)
{
	int i, j = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			matrix[i][j] = 0;
}

void SquareMatrix::StoreValue(int i, int j, int value)
{
	matrix[i][j] = value;
}

void SquareMatrix::Add(SquareMatrix& m, SquareMatrix& result)
{
	for (int i = 0;i < 50;i++)
	{
		for (int j = 0;j < 50;j++)
		{
			result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
		}
	}
}

void SquareMatrix::Subtract(SquareMatrix& m, SquareMatrix& result)
{
	for (int i = 0;i < 50;i++)
	{
		for (int j = 0;j < 50;j++)
		{
			result.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
		}
	}
}

void SquareMatrix::Copy(SquareMatrix& result)
{
	for (int i = 0;i < 50;i++)
	{
		for (int j = 0;j < 50;j++)
		{
			result.matrix[i][j] = matrix[i][j];
		}
	}
}

void SquareMatrix::Print()
{
	for (int i = 0;i < 50;i++)
	{
		for (int j = 0;j < 50;j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	SquareMatrix test1;
	test1.MakeEmpty(50);
	cout << "(MakeEmpty테스트)모두 0으로 이루어져있어야 한다." << endl;
	test1.Print();
	SquareMatrix test2;
	test2.MakeEmpty(50);
	test2.StoreValue(0, 0, 100);
	cout << "(StoreValue테스트)1행 1열의 값만 100으로 되어있어야 한다." << endl;
	test2.Print();
	SquareMatrix test3;
	test2.Copy(test3);
	cout << "(Copy테스트)1행 1열의 값만 100으로 되어있어야 한다." << endl;
	test3.Print();
	test3.StoreValue(49, 49, 500);
	test2.Add(test3, test1);
	cout << "(Add테스트)1행 1열의 값은 200,50행 50열의 값은 500으로 되어있어야 한다." << endl;
	test1.Print();
	test1.Subtract(test2, test3);
	cout << "(Subtract테스트)1행 1열의 값은 100,50행 50열의 값은 500으로 되어있어야 한다." << endl;
	test3.Print();

	cout << "모두 예상과 맞다면 시험 종료." << endl;


	return 0;
}