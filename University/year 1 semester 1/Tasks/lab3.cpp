// lab210121.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <locale.h>
#include <math.h>

using namespace std;
int main()
{

	double a, b, c, x, y, resultat, chisl, znam;
	setlocale(LC_ALL, "Russian");
	cout << "Лабораторная работа 3. Вариант 44" << endl << "Выполнил: Колупаев Александр\n";
	cout << "Введите переменную a=";//Запрос на ввод
	cin >> a;//Ввод с клавиатуры
	cout << "Введите переменную b=";//Запрос на ввод
	cin >> b;//Ввод с клавиатуры
	cout << "Введите переменную c=";//Запрос на ввод
	cin >> c;//Ввод с клавиатуры
	cout << "Введите переменную x=";//Запрос на ввод
	cin >> x;//Ввод с клавиатуры
	cout << "Введите переменную y=";//Запрос на ввод
	cin >> y;//Ввод с клавиатуры
	cout << "Введены переменные a=" << a << " b=" << b << " c=" << c << " x=" << x << " y=" << y << "\n";
	chisl = log(fabs(x + 2 * y)) / log(c);
	znam = sin(x / a) + log10(fabs(y / b));
	resultat = chisl / znam;
	cout << "\nРезультат:" << resultat << endl;
	system("pause");
	return 0;
}
