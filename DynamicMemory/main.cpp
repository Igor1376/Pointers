#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

template<typename T>
T** Allocate( int rows,  int cols);
template<typename T>
void clear(T** arr, const int rows);

void FillRand(int arr[], const int n, int minRand=0, int maxRand=100);
void FillRand(double arr[], const int n, int minRand=0, int maxRand=100);
void FillRand(char arr[], const int n);

void FillRand(double** arr, const int rows, const int cols);

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
T* pop_front(T arr[], int& n);
template<typename T>
T* insert(T arr[], int& n, int indx, int val);
template<typename T>
T* erase(T arr[], int& n, int indx, int val);

template<typename T>
T** push_row_back(T** arr, int& rows, const int cols);

template<typename T>
T** pop_row_back(T** arr, int& rows, const int cols);

template<typename T>
void push_col_back(T** arr, const int rows, int& cols);
template<typename T>
T** push_col_front(T** arr, const int rows, int& cols);
template<typename T>
T** insert_col(T** arr, const int rows, int& cols, int icol);

template<typename T>
T** pop_col_back(T** arr, const int rows, int& cols);
template<typename T>
T** pop_col_front(T** arr, const int rows, int& cols);
template<typename T>
T** erase_col(T** arr, const int rows, int& cols, int ecol);


//define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define PERFOMANCE_CHECK


void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	typedef double DataType;
	DataType* arr = new DataType[n];

	FillRand(arr, n);
	Print(arr, n);

	DataType value;
	cout << "Введите добавляемое число: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое число: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	arr = insert(arr, n, indx, v);
	print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

	int rows;
	int cols;
	int icol, ecol;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элеметнов строк: "; cin >> cols;

	typedef double DataType;
	DataType** arr = Allocate<DataType>(rows, cols);

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
	
	cout << "Добавьте номер добавления: "; cin >> icol;
	insert_col(arr, rows, cols, icol);
	
	
	arr=pop_col_front(arr, rows, cols);
	cout << "Введите номер удаления: "; cin >> ecol;
	arr=erase_col(arr, rows, cols, ecol);

	clear(arr, rows);
	
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
template<typename T>
T** Allocate( int rows, int cols)
{
	//1) создаем массив указателей:
	T** arr = new T*[rows];
	//2) выделяем память под строки:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T [cols] {};
	}
	return arr;
}
template<typename T>
void clear(T** arr, const int rows)
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
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	//обращение к элементам массива через арифметику указателей и  оператор разыменования
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand; 
		*(arr + i) /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	//обращение к элементам массива через арифметику указателей и  оператор разыменования
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand(); 
	}
}

void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
		cout << endl;
	}
}

template<typename T>
void Print(T arr[], const int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab; // обращение к элементам массива через оператор индексирования - []
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
	// Создаем буфеный массив нужного размера:
	T* buffer = new T[n + 1];
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
T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}
template<typename T>
T* insert(T arr[], int& n, int indx, int val)
{
	T* buffer = new T[++n];
	for (int i = 0; i < n; i++)
	{
		if (i >= indx)buffer[i + 1] = arr[i];
		else buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[indx] = val;
	return buffer;
}
template<typename T>
T* erase(T arr[], int& n, int indx, int val)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		if (i >= indx)buffer[i] = arr[i+1];
		else buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	return push_back(arr, rows, new T[cols]{});
}

template<typename T>
T** pop_row_back(T** arr, int& rows, const int cols)
{
	delete[] arr[rows-1]; // !!!Удаляем удаляемую строку из памяти
	return pop_back (arr, rows);
}
template<typename T>
void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//T() - значение по умолчанию для шаблонного типа
		arr[i] = push_back(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template<typename T>
T** push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
	/*for (int i = 0; i < rows; i++)
	{
		T** buff = Allocate<T>(rows, ++cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols - 1; j++)buff[i][j + 1] = arr[i][j];
			buff[i][0] = rand() % 100;
		}
		clear(arr, rows);
		return buff;

	}
	++cols;*/
}
template<typename T>
T** insert_col(T** arr, const int rows, int& cols, int icol)
{
	T** buffer = Allocate<T>(rows, ++cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if ( j >= icol - 1)buffer[i][j + 1] = arr[i][j];
			else buffer[i][j] = arr[i][j];
			if (j == icol - 1)buffer[i][j] = 0;
		}
	}
	clear(arr, rows);
	return buffer;
}
template<typename T>
T** pop_col_back(T** arr, const int rows, int& cols)
{
	T** buffer = Allocate<T>(rows, --cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)buffer[i][j] = arr[i][j];
	clear(arr, rows);
	return buffer;
}
template<typename T>
T** pop_col_front(T** arr, const int rows, int& cols)
{
	T** buffer = Allocate<T>(rows, --cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)buffer[i][j] = arr[i][j];
	clear(arr, rows);
	return buffer;
}
template<typename T>
T** erase_col(T** arr, const int rows, int& cols, int ecol)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++)
			buffer[j] = (j < ex ? arr[i][j] : arr[i][j + 1]);
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}