#include<iostream>

using namespace std;
#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* pop_back(int arr[], int& n);

void main()
{
	setlocale(LC_ALL, "");
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

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100; //обращение к элементам массива через арифметику указателей и  оператор разыменования
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