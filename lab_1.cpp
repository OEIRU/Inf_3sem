#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
using namespace std;

#define n 20
char A[n], B[n];

int number(char a)
{
	if (a < 58)	
		return a - '0';
	else
		return a - 'A' + 10;
} // перевод символа в число

char symbol(int a) 
{
	if (a < 10)
		return a + 48;
	else
		return a + 55;
} // если символ - буква (10+ система счисления)

float ofRin10(char A[n], int r)  // перевод из r-ичной в 10-ную
{
	int k = 1, j = 0;
	float N = 0;
	while (A[k] != '\0') // пока не конец строки
	{
		if (A[k] == '.')
			break; 
		k++;
	}

	for (int i = k - 1; i >= 0; i--) // посчитали целую часть
		N += (number(A[j++])) * powf(r, i);

	k = -1; 

	while (A[j++] != '\0')
		N += (number(A[j])) * powf(r, k--);
	return N;
}

char* of10inR(float N, int r)
{
	int N2 = N, H, i = 0; // целая часть и дробная часть
	float N4 = N - N2, N3 = N;
	A[i++] = '.';
	while (N2 >= r)
	{
		H = N2 / r;
		N2 = N2 - (H * r);
		A[i++] = symbol(N2);
		N2 = H;
	} // Целая часть переведена в r-ичную СС, далее перевод дробной части
	A[i++] = symbol(N2);
	A[i] = '\0';
	_strrev(A);
	if (N4 != 0)
	{
		i = 0;
		for (int j = 0; j < 10; j++)
		{
			N2 = N4 * r;
			N3 = N4 * r - N2;
			B[i++] = symbol(N2);
			N4 = N3;
		} // Дробная часть переведена с точностью до 5-ми знаков
		B[10] = '\0';
		strcat(A, B);
	}
	else
		A[i - 1] = '\0';

	return A;
}

int main()
{
	bool T = true;
	setlocale(LC_ALL, "Rus");
	int r, a, R1, R2;
	float N, N1, N2;
	char b;
	
	while (T)
	{
		cout << "\n 1. Перевод числа из одной системы счисления в другую систему счисления.\n";
		cout << "   2. Сложение двух чисел в различной или одной системе счисления.\n";
		cout << "   3. Вычитание двух чисел в различной или одной системе счисления.\n";
		cout << "   4. Умножение двух чисел в различной или одной системе счисления.\n";
		cout << "   5. Деление двух чисел в различной или одной системе счисления.\n";
		cout << "   6. Выход.\n";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			cout << "Введите исходную систему счисления:\n";
			cin >> R1;
			cout << "Введите систему счисления в которую необходимо выполнить перевод:\n";
			cin >> R2;
			cout << "Введите число:\n";
			if (R1 == 10)
			{
				cin >> N;
				of10inR(N, R2);
				cout << A << "\n";
			}
			else
			{
				cin >> A;
				if (R2 == 10)
					cout << ofRin10(A, R1) << "\n";
				else
				{
					N = ofRin10(A, R1);
					of10inR(N, R2);
					cout << A << "\n";
				}
			}
			break;
		}
		case 2:
		{
			cout << "Введите систему счисления первого числа:\n";
			cin >> R1;
			cout << "Введите первое число:\n";
			if (R1 == 10)
				cin >> N1;
			else
				cin >> A;
			cout << "Введите систему счисления второго числа:\n";
			cin >> R2;
			cout << "Введите второе число:\n";
			if (R2 == 10)
				cin >> N2;
			else
				cin >> B;
			cout << "Введите систему счисления в которой необходимо вывести ответ:\n";
			cin >> r;
			if (R1 == 10 && R2 == 10)
				N = N1 + N2;
			if (R1 != 10 && R2 == 10)
				N = ofRin10(A, R1) + N2;
			if (R1 == 10 && R2 != 10)
				N = N1 + ofRin10(B, R2);
			if (R1 != 10 && R2 != 10)
				N = ofRin10(A, R1) + ofRin10(B, R2);
			if (r == 10)
				cout << N << "\n";
			else
				cout << of10inR(N, r) << "\n";
			break;
		}
		case 3:
		{
			cout << "Введите систему счисления первого числа:\n";
			cin >> R1;
			cout << "Введите первое число:\n";
			if (R1 == 10)
				cin >> N1;
			else
				cin >> A;
			cout << "Введите систему счисления второго числа:\n";
			cin >> R2;
			cout << "Введите второе число:\n";
			if (R2 == 10)
				cin >> N2;
			else
				cin >> B;
			cout << "Введите систему счисления в которой необходимо вывести ответ:\n";
			cin >> r;
			if (R1 == 10 && R2 == 10)
				N = N1 - N2;
			if (R1 != 10 && R2 == 10)
				N = ofRin10(A, R1) - N2;
			if (R1 == 10 && R2 != 10)
				N = N1 - ofRin10(B, R2);
			if (R1 != 10 && R2 != 10)
				N = ofRin10(A, R1) - ofRin10(B, R2);
			if (r == 10)
				cout << N << "\n";
			else
				cout << of10inR(N, r) << "\n";
			break;
		}
		case 4:
		{
			cout << "Введите систему счисления первого числа:\n";
			cin >> R1;
			cout << "Введите первое число:\n";
			if (R1 == 10)
				cin >> N1;
			else
				cin >> A;
			cout << "Введите систему счисления второго числа:\n";
			cin >> R2;
			cout << "Введите второе число:\n";
			if (R2 == 10)
				cin >> N2;
			else
				cin >> B;
			cout << "Введите систему счисления в которой необходимо вывести ответ:\n";
			cin >> r;
			if (R1 == 10 && R2 == 10)
				N = N1 * N2;
			if (R1 != 10 && R2 == 10)
				N = ofRin10(A, R1) * N2;
			if (R1 == 10 && R2 != 10)
				N = N1 * ofRin10(B, R2);
			if (R1 != 10 && R2 != 10)
				N = ofRin10(A, R1) * ofRin10(B, R2);
			if (r == 10)
				cout << N << "\n";
			else
				cout << of10inR(N, r) << "\n";
			break;
		}
		case 5:
		{

			cout << "Введите систему счисления первого числа:\n";
			cin >> R1;
			cout << "Введите первое число:\n";
			if (R1 == 10)
				cin >> N1;
			else
				cin >> A;
			cout << "Введите систему счисления второго числа:\n";
			cin >> R2;
			cout << "Введите второе число:\n";
			if (R2 == 10)
				cin >> N2;
			else
				cin >> B;
			cout << "Введите систему счисления в которой необходимо вывести ответ:\n";
			cin >> r;
			if (R1 == 10 && R2 == 10)
				N = N1 / N2;
			if (R1 != 10 && R2 == 10)
				N = ofRin10(A, R1) / N2;
			if (R1 == 10 && R2 != 10)
				N = N1 / ofRin10(B, R2);
			if (R1 != 10 && R2 != 10)
				N = ofRin10(A, R1) / ofRin10(B, R2);
			if (r == 10)
				cout << N << "\n";
			else
				cout << of10inR(N, r) << "\n";
			break;
		}
		case 6:
			T = false;
		}
	}
	
}