#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n, int minRand=0, int maxRand=100);
void FillRand(double arr[], const int n, int minRand=0, int maxRand=100);
void FillRand(char arr[], const int n);

void FillRand(int** arr, const int rows, const int cols);

template<typename T>
void Print(T arr[], const int n);
template<typename T>
void Print(T** arr, const int rows, const int cols);

template<typename T>
T* push_back(T arr[], int& n, T value);
template<typename T>
T* push_front(T arr[], int& n, T value);
template<typename T>
T* pop_back(T arr[], int& n);

template<typename T>
T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>
T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T>
void push_col_back(T** arr, const int rows, int& cols);

void push_col_front(int** arr, const int rows, int& cols);

#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2
//#define PERFOMANCE_CHECK


void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "������� ������ �������: "; cin >> n;
	typedef char DataType;
	DataType* arr = new DataType[n];

	FillRand(arr, n);
	Print(arr, n);

	DataType value;
	cout << "������� ����������� �����: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "������� ����������� �����: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

	int rows;
	int cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� �����: "; cin >> cols;

	int** arr = Allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);
	
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	
	Clear(arr, rows);
	
#endif // DYNAMIC_MEMORY_2
#ifdef PERFOMANCE_CHECK

	int rows;
	int cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� �����: "; cin >> cols;

	int** arr = Allocate(rows, cols);
	cout << "Memory allocated" << endl;
	system("PAUSE");

	arr = push_row_back(arr, rows, cols);
	cout << "Row added" << endl;
	system("PAUSE");

	Clear(arr, rows);
	cout << "Memory clean" << endl;

#endif // PERFOMANCE_CHECK

}
int** Allocate(const int rows, const int cols)
{
	//1) ������� ������ ����������:
	int** arr = new int*[rows];
	//2) �������� ������ ��� ������:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}

void Clear(int** arr, const int rows)
{
	//1)������� ������� ������:
	for(int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2) ������� ������ ����������:
	delete[] arr;
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	//��������� � ��������� ������� ����� ���������� ���������� �  �������� �������������
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand; 
		*(arr + i) /= 100;
	}
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	//��������� � ��������� ������� ����� ���������� ���������� �  �������� �������������
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand; 
		*(arr + i) /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	//��������� � ��������� ������� ����� ���������� ���������� �  �������� �������������
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand(); 
	}
}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
		cout << endl;
	}
}

template<typename T>
void Print(T arr[], const int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab; // ��������� � ��������� ������� ����� �������� �������������� - []
	}
	cout << endl;
}

template<typename T>
void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}
template<typename T>
T* push_back(T arr[], int& n, T value)
{
	// ������� ������� ������ ������� �������:
	T* buffer = new T[n + 1];
	// �������� �������� �� ��������� �������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// ������� �������� ������
	delete[] arr;
	// ��������� ����� ��������� ������� ������� ������ �������
	arr = buffer;
	// ������ ����� ����� � ����� ������� ��������� ��������� �����, ���� ����� �������� ��������
	arr[n] = value;
	n++;
	//Print(arr, n);
	return arr;

}
template<typename T>
T* push_front(T arr[], int& n, T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
template<typename T>
T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>
T** push_row_back(T** arr, int& rows, const int cols)
{
	//1) ������� �������� ������ ���������� ������� �������:
	T** buffer = new T* [rows+1];

	//2) �������� ������ �� ��������� ������� � ������ ����������:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];

	//3) �������� �������� ������ ����������:
	delete[] arr;

	//4) ������� ������ � ��������� �� � ������:
	buffer[rows] = new int[cols] {};

	//5) ����� ���������� ������ � ������, ���������� ��� ����� �������������:
	rows++;
	return buffer;
}
template<typename T>
T** pop_row_back(T** arr, int& rows, const int cols)
{
	
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr[rows]; // !!!������� ��������� ������ �� ������
	delete[] arr;
	return buffer;
}
template<typename T>
void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//������� ��������� ������
		int* buffer = new int[cols + 1] {};
		// �������� �������� �� �������� ������ � ��������:
		for(int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//������ ������� ������:
		delete[] arr[i];
		//��������� ����� ������ � ������� ����������
		arr[i] = buffer;
	}
	cols++;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//������� ��������� ������
		int* buffer = new int[1 + cols] {};
		// �������� �������� �� �������� ������ � ��������:
		for (int j = 0; j < cols; j++)buffer[j+1] = arr[i][j];
		//������ ������� ������:
		delete[] arr[i];
		//��������� ����� ������ � ������� ����������
		arr[i] = buffer;
	}
	++cols;
}