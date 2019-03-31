#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
/*
	Пинарин Олег
	1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
	2. Реализовать функцию возведения числа a в степень b:
	a. без рекурсии;
	b. рекурсивно;
	c. *рекурсивно, используя свойство чётности степени.

	3. Исполнитель Калькулятор преобразует целое число, записанное на экране. У исполнителя две команды, каждой команде присвоен номер:
	Прибавь 1 2.Умножь на 2 Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза. Сколько существует программ, 
	которые число 3 преобразуют в число 20? а) с использованием массива; б) с использованием рекурсии.
	Записывайте в начало программы условие и свою фамилию. Все решения создавайте в одной программе. Со звёздочками выполняйте в том случае, если вы решили задачи без звёздочек.
*/

void menu();

void DecConvertToBinary();
void NumberRate();
void NumberRateRecursiveDemonstr();
int NumberRateRecursive(int, int);
void NumberRateRecursiveOddUseDemonstr();
int NumberRateOddUse(int, int);
int NumberRateRecursiveOddUse(int, int);
long Counter = 0;
void Calculator();
void Calculate(long, long);

int main()
{
	setlocale(LC_ALL, "Rus");
	int TaskNumber = 0;
	
	do
	{
		system("cls");
		menu();
		scanf("%i", &TaskNumber);
		switch (TaskNumber)
		{
			case 1:
				DecConvertToBinary();
				break;
			case 2:
				NumberRate();
				break;
			case 3:
				NumberRateRecursiveDemonstr();
				break;
			case 4:
				NumberRateRecursiveOddUseDemonstr();
				break;
			case 5:
				Calculator();
				break;
			default:
				printf("Неверный ввод!!!\n");
		}
	} while (TaskNumber != 0);
	system("pause");
	return 0;
}

void menu()
{
	printf("Введите номер задачи\n");
	printf("1. Целое число для преобразования в двоичную систему исчисления:\n");
	printf("2. Реализовать функцию возведения числа a в степень b без рекурсии:\n");
	printf("3. Реализовать функцию возведения числа a в степень b рекурсивно:\n");
	printf("4. Реализовать функцию возведения числа a в степень b рекурсивно, используя свойство четности степени:\n");
	printf("5. Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза.\n   Определить, сколько существует программ, которые преобразуют число 3 в число 20.\n");
}

//1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
void DecConvertToBinary()
{
	int number = 0;
	printf("1. Целое число для преобразования в двоичную систему исчисления:\n");
	scanf("%i", &number);

	while (number >= 2)
	{
		printf("%i", number % 2);
		number /= 2;
	}
	printf("%i", number);
}

//2. Реализовать функцию возведения числа a в степень b:
//a.без рекурсии;
void NumberRate()
{
	printf("2. Реализовать функцию возведения числа a в степень b без рекурсии:\n");
	int a, b;
	int result = 0;
	printf("Введите число a:\n");
	scanf("%i", &a);
	printf("введите число b:\n");
	scanf("%i", &b);
	result = a;
	while (b-2>=0)
	{
		result *= a;
		b--;
	}
	printf("Результат возведения в степень: %i\n", result);
	system("pause");
}

// 2. Реализовать функцию возведения числа a в степень b :
//b.рекурсивно;
void NumberRateRecursiveDemonstr()
{
	printf("2. Реализовать функцию возведения числа a в степень b рекурсивно:\n");
	int a, b;
	int result = 0;
	printf("Введите число a:\n");
	scanf("%i", &a);
	printf("введите число b:\n");
	scanf("%i", &b);
	result = NumberRateRecursive(a, b);
	printf("Результат возведения в степень: %i\n", result);
	system("pause");
}

int NumberRateRecursive(int a, int b)
{
	int result = a;
	if(b>=2)
		result = a * NumberRateRecursive(a, b - 1);
	return result;
}

// 2. Реализовать функцию возведения числа a в степень b :
//c. *рекурсивно, используя свойство чётности степени.
void NumberRateRecursiveOddUseDemonstr()
{
	printf("2. Реализовать функцию возведения числа a в степень b рекурсивно, используя свойство четности степени:\n");
	int a, b;
	int result = 0;
	printf("Введите число a:\n");
	scanf("%i", &a);
	printf("введите число b:\n");
	scanf("%i", &b);
	//result = NumberRateOddUse(a, b);
	result = NumberRateRecursiveOddUse(a, b);
	printf("Результат возведения в степень: %i\n", result);
	system("pause");
}

//Не рекурсивно, используя свойство четности степени
int NumberRateOddUse(int a, int b)
{
	int n = 1;
	int s = a;
	int k = b;
	while(k!=0)
	{
		if (k%2==0)
		{
			s *= s;
			k /= 2;
		}
		else
		{
			k--;
			n = n * s;
		}
	}
	return n;
	printf("Результат возведения в степень: %i\n", n);
	system("pause");
}

//Рекурсивно, используя свойство четности степени
int NumberRateRecursiveOddUse(int a, int b)
{
	int n = 1;
	int s = a;
	int k = b;
	if (k !=0&&k>1)
	{
		if (k % 2 == 0)
		{
			n = NumberRateRecursiveOddUse(a, b / 2);
			s = n * n;			
		}
		else
		{
			n = NumberRateRecursiveOddUse(a, (b - 1) / 2);
			s = a * n * n;			
		}
	}
	return s;
}

//3. **Исполнитель «Калькулятор» преобразует целое число, записанное на экране.У исполнителя две команды, каждой присвоен номер :
//	1. Прибавь 1.
//	2. Умножь на 2.
//Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза.Определить, сколько существует программ, которые преобразуют число 3 в число 20 :
//	а.С использованием массива.
//	b.*С использованием рекурсии.
void Calculator()
{
	printf("3. Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза.\n	Определить, сколько существует программ, которые преобразуют число 3 в число 20.\n");
	int a, b;
	
	printf("Введите число a:\n");
	scanf("%i", &a);
	printf("введите число b:\n");
	scanf("%i", &b);
	
	char *charList = "";
	Counter = 0;
	Calculate(a, b, charList);
	printf("Существует: %i решений данной задачи!!!\n", Counter);
	system("pause");
}
void Calculate(long a, long b, char* charList)
{
	if (a == b)
	{
		Counter++;
		printf("Последовательность действий: %s\n", charList);
	}
	if (a < b)
	{
		size_t len = strlen(charList);
		char *str2 = malloc(len + 1 + 1); /* one for extra char, one for trailing zero */
		strcpy(str2, charList);		
		
		str2[len] = '+';
		str2[len + 1] = '\0';
		Calculate(a+1, b, str2);
		str2[len] = '*';		
		Calculate(a*2, b, str2);
	}
}
