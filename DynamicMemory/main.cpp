#include<iostream>

using namespace std;
#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
	cout << "¬ведите размер массива"; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100; //обращение к элементам массива через арифметику указателей и  оператор разыменовани€
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab; // обращение к элементам массива через оператор индексировани€ - []
	}
	cout << endl;
}