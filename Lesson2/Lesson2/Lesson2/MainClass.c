#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
/*
	������� ����
	1. ����������� ������� �������� �� 10 ������� � �������� ��������� ��������.
	2. ����������� ������� ���������� ����� a � ������� b:
	a. ��� ��������;
	b. ����������;
	c. *����������, ��������� �������� �������� �������.

	3. ����������� ����������� ����������� ����� �����, ���������� �� ������. � ����������� ��� �������, ������ ������� �������� �����:
	������� 1 2.������ �� 2 ������ ������� ����������� ����� �� ������ �� 1, ������ ����������� ��� ����� � 2 ����. ������� ���������� ��������, 
	������� ����� 3 ����������� � ����� 20? �) � �������������� �������; �) � �������������� ��������.
	����������� � ������ ��������� ������� � ���� �������. ��� ������� ���������� � ����� ���������. �� ���������� ���������� � ��� ������, ���� �� ������ ������ ��� ��������.
*/

void menu();

void DecConvertToBinary();
void NumberRate();
void NumberRateRecursiveDemonstr();
int NumberRateRecursive(int, int);
void NumberRateRecursiveOddUseDemonstr();
int NumberRateOddUse(int, int);
int NumberRateRecursiveOddUse(int, int);

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
			default:
				printf("�������� ����!!!\n");
		}
	} while (TaskNumber != 0);
	system("pause");
	return 0;
}

void menu()
{
	printf("������� ����� ������\n");
}

//1. ����������� ������� �������� �� 10 ������� � �������� ��������� ��������.
void DecConvertToBinary()
{
	int number = 0;
	printf("1. ����� ����� ��� �������������� � �������� ������� ����������:\n");
	scanf("%i", &number);

	while (number >= 2)
	{
		printf("%i", number % 2);
		number /= 2;
	}
	printf("%i", number);
}

//2. ����������� ������� ���������� ����� a � ������� b:
//a.��� ��������;
void NumberRate()
{
	int a, b;
	int result = 0;
	printf("������� ����� a:\n");
	scanf("%i", &a);
	printf("������� ����� b:\n");
	scanf("%i", &b);
	result = a;
	while (b-2>=0)
	{
		result *= a;
		b--;
	}
	printf("��������� ���������� � �������: %i\n", result);
	system("pause");
}

// 2. ����������� ������� ���������� ����� a � ������� b :
//b.����������;
void NumberRateRecursiveDemonstr()
{
	int a, b;
	int result = 0;
	printf("������� ����� a:\n");
	scanf("%i", &a);
	printf("������� ����� b:\n");
	scanf("%i", &b);
	result = NumberRateRecursive(a, b);
	printf("��������� ���������� � �������: %i\n", result);
	system("pause");
}

int NumberRateRecursive(int a, int b)
{
	int result = a;
	if(b>=2)
		result = a * NumberRateRecursive(a, b - 1);
	return result;
}

// 2. ����������� ������� ���������� ����� a � ������� b :
//c. *����������, ��������� �������� �������� �������.
void NumberRateRecursiveOddUseDemonstr()
{
	int a, b;
	int result = 0;
	printf("������� ����� a:\n");
	scanf("%i", &a);
	printf("������� ����� b:\n");
	scanf("%i", &b);
	//result = NumberRateOddUse(a, b);
	result = NumberRateRecursiveOddUse(a, b);
	printf("��������� ���������� � �������: %i\n", result);
	system("pause");
}

//�� ����������, ��������� �������� �������� �������
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
	printf("��������� ���������� � �������: %i\n", n);
	system("pause");
}

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

//3. **����������� ������������ ����������� ����� �����, ���������� �� ������.� ����������� ��� �������, ������ �������� ����� :
//	1. ������� 1.
//	2. ������ �� 2.
//������ ������� ����������� ����� �� ������ �� 1, ������ ����������� ��� � 2 ����.����������, ������� ���������� ��������, ������� ����������� ����� 3 � ����� 20 :
//	�.� �������������� �������.
//	b.*� �������������� ��������.

