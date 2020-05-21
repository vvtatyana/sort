#include <iostream>
#include <conio.h>
using namespace std;
void pus(int *arr, int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int b = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = b;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[]arr;
}
void shel(int *arr, int N)
{
	int i, j, step;
	int tmp;
	for (step = N / 2; step > 0; step /= 2)
		for (i = step; i < N; i++)
		{
			tmp = arr[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < arr[j - step])
					arr[j] = arr[j - step];
				else
					break;
			}
			arr[j] = tmp;
		}
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[]arr;
}
void temp(int *arr, int N)
{
	int a, b;
	cout << "Отсортировать массив (1) или создать новый массив(2): ";
	cin >> b;
	switch (b)
	{
	case 1:
		cout << "Выберите метод сортировки:"<<endl<<
			"1. Метод Пузырька"<<endl<<
			"2. Метод Шелла"<<endl;
		cin >> a;
		switch (a)
		{
		case 1:	cout << "Результат:" << endl;
			pus(arr, N);
			break;
		case 2:	cout << "Результат:" << endl;
			shel(arr, N);
			break;
		default:cout << "Выберите 1 или 2: ";
			temp(arr, N);
		}
	case 2: int main();
		break;
	default:cout << "Выберите 1 или 2: ";
	}
}
int main()
{
	system("chcp 1251>nul");
	int N;
	char q;
	do
	{
		cout << "Выберите размер массива: ";
		cin >> N;
		int *arr;
		arr = new int[N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = rand() % 10;
			cout << arr[i] << " ";
		}
		cout << endl;
		temp(arr, N);
		do
		{
			cout << "Создать новый массив (1) или выйти (2)\n";
			q = _getch();
		} while (q != '2' && q != '1');
	} while (q != '2');
	return 0;
}
