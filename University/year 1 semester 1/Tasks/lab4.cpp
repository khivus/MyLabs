// lab210121.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <locale.h>
#include <math.h>

using namespace std;
int main()
{

	double x, y, z;
	setlocale(LC_ALL, "Russian");
	cout << "Лабораторная работа 4. Вариант 46" << endl << "Выполнил: Колупаев Александр\n";
	cout << "Введите переменную x=";//Запрос на ввод
	cin >> x;//Ввод с клавиатуры
	z = 3 * sin(2 * x);
	if (z < 0)//if(x>-5.1 && x<0) if(x*x+y*y==0 && y>0)
		y = 1.5*pow(fabs(z*z + sin(z)), 1. / 3);
	else if (z == 0)
		y = sin(x) / sqrt(fabs(x + 1));
	else y = 2 * log2(z);
	cout << "\nРезультат:" << y << endl;
	system("pause");
	return 0;
}
