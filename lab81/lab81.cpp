#include<iostream>

#include<fstream>
#include <sstream>
#include<stdlib.h>
#include <stdio.h>  
#include<time.h>
#include <algorithm> 
#define N 10
int firstDigit(int n)
{
	int k;
	do
	{
		k = n;
		n /= 10;
	} while (n);
	return k;
}

//1.Упорядочить последовательность по неубыванию первой цифры числа 
//числа с одинаковыми первыми цифрами дополнительно упорядочить по неубыванию произведения цифр числа 
//числа с одинаковыми первыми цифрами и одинаковыми произведениями цифр дополнительно упорядочить по неубыванию самого числа.
using namespace std;

int main()
{
	bool fl = false;
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	std::ofstream outchanged("outputchanged.txt");
	srand(time(0));
	int  i, l, first[N], prod[N],n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < N; i++)
	{		
		a[i] = rand() % 100 + 1;//задаем последовательность
		l = a[i];
		first[i] = firstDigit(l);// первая цифра числа
		cout << a[i] << '\t';
	}
	cout << endl;
	for (i = 0; i < N; i++)// произведение цифр числа
	{
		prod[i] = 1;
		int x = a[i];
		while (x > 0)
		{
			prod[i] *= x % 10;
			x /= 10;
		}
		//cout << prod[i] << '\t';
	}
	//cout << endl;

	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
		{
			if (first[i] >= first[j])
			{
				std::swap(a[i], a[j]);
				std::swap(first[i], first[j]);
				std::swap(prod[i], prod[j]);
			}
			if (first[i] == first[j] && prod[i] >= prod[j])
			{
				std::swap(a[i], a[j]);
				std::swap(first[i], first[j]);
				std::swap(prod[i], prod[j]);
			}
			if (first[i] == first[j] && prod[i] == prod[j] && a[i] > a[j])
			{
				std::swap(a[i], a[j]);
				std::swap(first[i], first[j]);
				std::swap(prod[i], prod[j]);
			}
		}

	for (i = 0; i < N; i++)
	{
		cout << a[i] << '\t';
	}
	delete[] a;
	return 0;

}
