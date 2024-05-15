#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n, int minRand=0, int maxRand=100);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);

int* pop_back(int arr[], int& n);

int** push_row_back(int** arr, int& rows, const int cols);
int** pop_row_back(int** arr, int& rows, const int cols);

void push_col_back(int** arr, const int rows, int& cols);

void push_col_front(int** arr, const int rows, int& cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define PERFOMANCE_CHECK


void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое число: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое число: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элеметнов строк: "; cin >> cols;

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
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элеметнов строк: "; cin >> cols;

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
	//1) создаем массив указателей:
	int** arr = new int*[rows];
	//2) выделяем память под строки:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}

void Clear(int** arr, const int rows)
{
	//1)Сначала удаляем строки:
	for(int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2) Удаляем массив указателей:
	delete[] arr;
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	//обращение к элементам массива через арифметику указателей и  оператор разыменования
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand; 
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

void Print(int arr[], const int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab; // обращение к элементам массива через оператор индексирования - []
	}
	cout << endl;
}

void Print(int** arr, const int rows, const int cols)
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
int* push_back(int arr[], int& n, int value)
{
	// Создаем буфеный массив нужного размера:
	int* buffer = new int[n + 1];
	// копируем значения из исходного маассива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// удаляем исходный массив
	delete[] arr;
	// подменяем адрес исходного массива адресом нового массива
	arr = buffer;
	// только после этого в конце массива появлятся свободное место, куда можно добавить значение
	arr[n] = value;
	n++;
	//Print(arr, n);
	return arr;

}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	//1) Создаем буферный массив указателей нужного размера:
	int** buffer = new int* [rows+1];

	//2) Копируем строки из исходного массива в массив указателей:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];

	//3) Удалеяем исходный массив указателей:
	delete[] arr;

	//4) Создаем строку и добавляем ее в массив:
	buffer[rows] = new int[cols] {};

	//5) После добавления строки в массив, количество его строк увеличивается:
	rows++;
	return buffer;
}
int** pop_row_back(int** arr, int& rows, const int cols)
{
	
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr[rows]; // !!!Удаляем удаляемую строку из памяти
	delete[] arr;
	return buffer;
}
void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//создаем буфферную строку
		int* buffer = new int[cols + 1] {};
		// копируем значения из исходной строки в буферную:
		for(int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//удалем исходую строку:
		delete[] arr[i];
		//подменяем адрес строки в массиве указателей
		arr[i] = buffer;
	}
	cols++;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//создаем буфферную строку
		int* buffer = new int[1 + cols] {};
		// копируем значения из исходной строки в буферную:
		for (int j = 0; j < cols; j++)buffer[j+1] = arr[i][j];
		//удалем исходую строку:
		delete[] arr[i];
		//подменяем адрес строки в массиве указателей
		arr[i] = buffer;
	}
	++cols;
}