#include<iostream>
using namespace std;
//#definer POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");

#if POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl; // вывод значения переменной a на экран
	cout << &a << endl; // взятие адреса переменной а прямо при выводе
	cout << pa << endl; // вывод адреса переменной а хранящегося в указателе pa 
	cout << *pa << endl; // разыменование указателя pa и вывод значения по адресу (значение переменной) а

#endif // POINTERS_BASICS

	const int n = 5; 
	int arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

}