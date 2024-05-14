#include "Header.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	system("chcp1251");

	cout << N << "Запустить программу (Y): ";
	cin >> StartApp;
	while ((StartApp != 'Y'))
	{
		cin.clear();
		cin.ignore(1200, N);
		cout << endl << "Введите (Y):";
		cin >> StartApp;
	}

	cout << N << "Выберете метод. Крамер/Матричный (K/R): ";
	cin >> Change;
	while ((Change != 'K') && (Change != 'R'))
	{
		cin.clear();
		cin.ignore(1200, N);
		cout << N << "Ошибка! Выберите метод решения: ";
		cin >> Change;
	}
	if (Change == 'K')
	{
		Kramer(ReadSizeOfSystem());
	}
	else if (Change == 'R')
	{
		Reverse(ReadSizeOfSystem());
	}


	cout << NN << "Завершить программу (Y): ";

	cin >> StopApp;
	while (StopApp != 'Y')
	{
		cin.clear();
		cin.ignore(1200, N);
		cout << N << "Другого не дано, прости! Введите (Y): ";
		cin >> StopApp;
	}
	if (StopApp == 'Y')
	{
		cout << N << "Программа была завершина. Хорошего дня!";
		return 0;
	}
}