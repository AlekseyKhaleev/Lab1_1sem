﻿
// Lab1.cpp – Листинг программы для 1-ой лабораторной работы
// Вариант 8
//*******************************************************************
// Имя файла : Lab1.cpp
// Резюме : Пример программы написанной на языке программирования С++
// Описание :  Программа запрашивает значения a и x от пользователя.
// Вычисляет значения выражений  Y(a, x) и Z(a, x). Выводит на консоль
// полученные значения.
// Дата создания : 2022 / 01 / 14
// Автор : Студент НГТУ ИРИТ, Халеев А.А., гр. 21-ИВТз
// Платформа : OS Microsoft Windows, MS Visual Studio 2019 (Community)
// ******************************************************************

/* Подключение модулей */
#include <stdio.h>
#include <locale.h>
#include <cmath>

/* Определение констант корректных данных для ввода*/
const double CorrectA = 0.35;
const double CorrectX = 0.21;

/* Прототип функции для инициализации переменных корректными значениями */
void CorrectInit(double&, double&);

/* Начало главной функции */
int main() {
	setlocale(LC_ALL, "RUS"); // Вызов функции для отображения русских символов

	// Логотип программы
	const  char* logo = "*********************************************************\n\
* Нижегородский государственный технический университет *\n\
* Лабораторная работа №1. Задание 1. Вариант 8.         *\n\
* Выполнил студент группы 21 - ИВТз Халеев Алексей      *\n\
*********************************************************\n";
	printf_s(logo);

	// Объявление переменных ввода пользователя и результатов вычислений
	double a, x, y, z;

	// Инициализация переменных a и x корректными значениями, запрашиваемыми у пользователя
	CorrectInit(a, x);

	// Запись результатов вычисления выражений в соответствующие переменные
	y = pow(fabs(sin(x - pow(a, 2))), 4);
	z = exp(2 * x) + acos(2 * x + a);

	// Вывод на консоль результатов вычислений
	printf("\nY = %lf, Z = %lf\n\n", y, z);
	system("pause"); // Команда задержки экрана
	return 0; //  Возврат управления ОС в случае успешной работы
} //  END: Конец кода главной функции модуля

void CorrectInit(double& a, double& x) {
	// Цель: Инициализация переменных корректными значениями */
	// Исходные данные:
	//	а – ссылка на первую переменную
	//	x – ссылка на вторую переменную
	// Результат: функция ничего не возвращает, переменным присвоены 
	// корректные значения по соответствующим ссылкам
	// Вызываемые модули: нет
	/* Описание алгоритма :
	В функции присутствуют 2 схожих блока для соответствующих переменных, 
	в каждом из которых	создается бесконечный цикл, продолжающийся, пока
	корректное значение не будет введено.
	1) На консоль выводится приглашение ввести значение переменной,
	при этом указывается, какое именно значение требуется ввести - 
	оно соответствует константе, определенной до описания функции main().
	2) Пользователь вводит значение, которое присваивается соответствующей
	переменной по ссылке.
	3) Производится очистка буфера потока ввода. Это необходимо для того 
	чтобы избежать ошибочного считывания данных из буфера при следующей 
	итерации в случае неверного ввода. К примеру, без очистки буфера, в 
	случае ввода литерала получим бесконечный цикл.
	4) Проверка корректности введенного значения:
	Так как вновь введенное значение сохранено в переменной, проверяем 
	ее на равенство	соответствующей константе.
	- если значения не равны, на консоль выводится сообщение об ошибке,
	затем цикл повторяется
	- если значения равны - прерываем цикл иструкцией break. */
	// Дата: 2022 / 01 / 14 Версия 1.01
	// Автор: Студент НГТУ ИРИТ, Халеев А. А. гр. 21-ИВТз
	// Исправления: нет
	/***********************************************************************/

	// Ввод переменной a
	while (true) {
		printf_s("\nВведите корректное значение a (a = %.2lf)\n", CorrectA); // приглашение
		scanf_s("%lf", &a); // введенное значение присваивается переменной по ссылке
		scanf_s("%*[^\n]"); // Очистка буфера ввода

		// Проверка корректности введенного значения
		if (a != CorrectA) printf_s("Ошибка ввода – неверное значение a\n");
		else break;
	}
	// Ввод переменной x
	while (true) {
		printf_s("\nВведите корректное значение x (x = %.2lf)\n", CorrectX); // приглашение
		scanf_s("%lf", &x);// введенное значение присваивается переменной по ссылке
		scanf_s("%*[^\n]"); // Очистка буфера ввода

		// Проверка корректности введенного значения
		if (x != CorrectX) printf_s("Ошибка ввода – неверное значение x\n");
		else break;
	}
}
