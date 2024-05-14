#include "Header.h"
// Общии функции
struct SystemData
{
	double x, y, z, b;
	bool errors;
};
int ReadSizeOfSystem()
{
	cout << N << "Введите количество неизвестных величин в системе: ";
	while (!(cin >> SizeOfSystem) || (SizeOfSystem < 2 || SizeOfSystem > 3))
	{
		cin.clear();
		cin.ignore(1200, N);
		cout << N << "Ошибка! Введите количество неизвестных величин в системе (от 2 до 3): ";
	}
	return SizeOfSystem;
}
SystemData ReadTheSystem(int SizeOfSystem)
{
	SystemData Sys{};

	cout << N << "Введите коэффициент X: ";
	while (!(cin >> Sys.x))
	{
		cin.clear();
		cin.ignore(1200, '\n');
		cout << N << "Ошибка! Введите коэффициент X: ";
	}

	cout << "Введите коэффициент Y: ";
	while (!(cin >> Sys.y))
	{
		cin.clear();
		cin.ignore(1200, N);
		cout << N << "Ошибка! Введите коэффициент Y: ";
	}

	if (SizeOfSystem == 3)
	{
		cout << "Введите коэффициент Z: ";
		while (!(cin >> Sys.z))
		{
			cin.clear();
			cin.ignore(1200, '\n');
			cout << N << "Ошибка! Введите коэффициент Z: ";
		}
	}

	cout << "Введите коэффициент B: ";
	while (!(cin >> Sys.b))
	{
		cin.clear();
		cin.ignore(1200, '\n');
		cout << N << "Ошибка! Введите коэффициент B: ";
	}


	if (SizeOfSystem == 2)
	{
		if (Sys.x == 0 && Sys.y == 0 && Sys.b == 0)
		{
			Sys.errors = 1;
			return Sys;

		}
		else
		{
			Sys.errors = 0;
			return Sys;
		}
	}

	else
	{
		if (Sys.x == 0 && Sys.y == 0 && Sys.z == 0 && Sys.b == 0)
		{
			Sys.errors = 1;
			return Sys;

		}
		else
		{
			Sys.errors = 0;
			return Sys;
		}
	}


}
void PrintTheSystem(int SizeOfSystem, SystemData Row[])
{
	int K(0);
	cout << N << "Вывод системы: " << N;
	for (int i = 0; i < SizeOfSystem; i++)
	{

		if (Row[i].errors == 1)
		{
			K++;
			cout << N << "Данная строка системы не имеет смысла " << N;
		}
		else
		{
			if (Row[i].x == 0)
				cout;
			else
				cout << Row[i].x << 'x';

			if (Row[i].y > 0 && Row[i].x != 0)
				cout << "+" << Row[i].y << 'y';
			else if (Row[i].y == 0)
				cout;
			else
				cout << Row[i].y << 'y';

			if (SizeOfSystem == 3)
			{
				if (Row[i].z > 0 && Row[i].y != 0)
					cout << "+" << Row[i].z << 'z';
				else if (Row[i].z == 0)
					cout;
				else
					cout << Row[i].z << 'z';

				if (Row[i].b == 0 && (Row[i].x != 0 || Row[i].y != 0 || Row[i].z != 0))
					cout << "=0" << N;
				else if (Row[i].b != 0 && (Row[i].x == 0 && Row[i].y == 0 && Row[i].z == 0))
					cout << Row[i].b << "b" << N;
				else
					cout << "=" << Row[i].b << "b" << N;
			}
			else
			{
				if (Row[i].b == 0 && (Row[i].x != 0 || Row[i].y != 0))
					cout << "=0" << N;
				else if (Row[i].b != 0 && (Row[i].x == 0 && Row[i].y == 0))
					cout << Row[i].b << "b" << N;
				else
					cout << "=" << Row[i].b << "b" << N;
			}

		}

	}

	if (K == SizeOfSystem)
	{
		cout << N << "Данная система не существует! ";
	}
	else
	{
		cout << N << N << "Ход решения системы линейных уравнений";
		cout << N << N << "Матрица А:";
		for (int d = 0; d < SizeOfSystem; d++)
		{
			if (SizeOfSystem == 2)
			{
				cout << N << Row[d].x << '\t' << Row[d].y;
			}
			else if (SizeOfSystem == 3)
			{
				cout << N << Row[d].x << '\t' << Row[d].y << '\t' << Row[d].z;
			}
		}

		cout << N << "Матрица-столбец неизвестных Х: ";
		for (int j = 0; j < SizeOfSystem; j++)
		{
			cout << N << "X" << j + 1;
		}
		cout << N << "Матрица-столбец свободных членов B: ";
		for (int k = 0; k < SizeOfSystem; k++)
		{
			cout << N << Row[k].b;
		}

	}

}
double FindDeterminant(int SizeOfSystem, SystemData Row[])
{
	if (SizeOfSystem == 2)
	{
		double DetA;
		DetA = Row[0].x * Row[1].y - Row[0].y * Row[1].x;
		return DetA;
	}

	else
	{
		double DetA;
		DetA = Row[0].x * Row[1].y * Row[2].z + Row[0].y * Row[1].z * Row[2].x + Row[0].z * Row[1].x * Row[2].y - Row[0].y * Row[1].x * Row[2].z - Row[0].x * Row[1].z * Row[2].y - Row[0].z * Row[1].y * Row[2].x;
		return DetA;
	}
}

// Функции для решения С.Л.А.У методом Крамера
double FindHelpersForDeterminant(int K, int SizeOfSystem, SystemData Row[])
{
	double DetH(0);
	if (SizeOfSystem == 2)
	{
		if (K == 1)
			DetH = Row[0].b * Row[1].y - Row[0].y * Row[1].b;
		else if (K == 2)
			DetH = Row[0].x * Row[1].b - Row[0].b * Row[1].x;

		return DetH;
	}
	else
	{
		if (K == 1)
			DetH = (Row[0].b * Row[1].y * Row[2].z + Row[0].y * Row[1].z * Row[2].b + Row[0].z * Row[1].b * Row[2].y - Row[0].y * Row[1].b * Row[2].z - Row[0].b * Row[1].z * Row[2].y - Row[0].z * Row[1].y * Row[2].b);
		else if (K == 2)
			DetH = (Row[0].x * Row[1].b * Row[2].z + Row[0].b * Row[1].z * Row[2].x + Row[0].z * Row[1].x * Row[2].b - Row[0].b * Row[1].x * Row[2].z - Row[0].x * Row[1].z * Row[2].b - Row[0].z * Row[1].b * Row[2].x);
		else
			DetH = (Row[0].x * Row[1].y * Row[2].b + Row[0].y * Row[1].b * Row[2].x + Row[0].b * Row[1].x * Row[2].y - Row[0].y * Row[1].x * Row[2].b - Row[0].x * Row[1].b * Row[2].y - Row[0].b * Row[1].y * Row[2].x);
		return DetH;
	}
}
double FindXiKramer(double DetA, double DetH)
{
	return double(DetH) / (DetA);
}
void Kramer(int SizeOfSystem)
{
	double DetA(0), Det1(0), Det2(0), Det3(0);
	double X1(0), X2(0), X3(0);

	SystemData* Row = new SystemData[SizeOfSystem];

	for (int i = 0; i < SizeOfSystem; i++)
	{
		Row[i] = ReadTheSystem(SizeOfSystem);
	}

	auto Start = chrono::high_resolution_clock::now(); // Старт замеров

	PrintTheSystem(SizeOfSystem, Row);

	DetA = FindDeterminant(SizeOfSystem, Row);
	if (DetA == 0)
		cout << endl << "Матрица несовместна!";
	else
	{

		if (SizeOfSystem == 2)
		{
			cout << NN << "Детерминант матрицы A (Формула) = X1 * Y2 - X2 * Y1";
			cout << N << "Детерминант матрицы А = " << DetA;
			Det1 = FindHelpersForDeterminant(1, SizeOfSystem, Row);
			Det2 = FindHelpersForDeterminant(2, SizeOfSystem, Row);
			cout << NN << "Определитель вспомогательной матрицы Det1 (Формула) = B1 * Y2 - Y1 * B2";
			cout << N << "Определитель вспомогательной матрицы Det1 = " << Det1;
			cout << NN << "Определитель вспомогательной матрицы Det2 (Формула) = X1 * B2 - X2 * B2";
			cout << N << "Определитель вспомогательной матрицы Det3 = " << Det2;
			X1 = FindXiKramer(DetA, Det1);
			X2 = FindXiKramer(DetA, Det2);
			cout << NN << "Матрица-столбец неизвестных X (Формулы): " << N << "X1 = Det1/DetA" << N << "X2 = Det2/DetA";
			cout << NN << "Матрица-столбец неизвестных Х:" << N << X1 << N << X2;
		}
		else
		{
			cout << NN << "Детерминант матрицы A (Формула) X1 * Y2 * Z3 + Y1 * Z2 * X3 + Z1 * X2 * Y3 - Z1 * Y2 * X3 - X1 * Z2 * Y3 - Y1 * X2 * Z3";
			cout << N << "Детерминант матрицы А = " << DetA;
			Det1 = FindHelpersForDeterminant(1, SizeOfSystem, Row);
			Det2 = FindHelpersForDeterminant(2, SizeOfSystem, Row);
			Det3 = FindHelpersForDeterminant(3, SizeOfSystem, Row);
			cout << NN << "Определитель вспомогательной матрицы Det1 (Формула) = B1 * Y2 * Z3 + Y1 * Z2 * B3 + Z1 * B2 * Y3 - Z1 * Y2 * B3 - B1 * Z2 * Y3 - Y1 * B2 * Z3";
			cout << N << "Определитель вспомогательной матрицы Det1 = " << Det1;
			cout << NN << "Определитель вспомогательной матрицы Det2 (Формула) = X1 * B2 * Z3 + B1 * Z2 * X3 + Z1 * X2 * B3 - Z1 * B2 * X3 - X1 * Z2 * B3 - B1 * X2 * Z3";
			cout << N << "Определитель вспомогательной матрицы Det2 = " << Det2;
			cout << NN << "Определитель вспомогательной матрицы Det3 (Формула) = X1 * Y2 * B3 + Y1 * B2 * X3 + B1 * X2 * Y3 - B1 * Y2 * X3 - X1 * B2 * Y3 - Y1 * X2 * B3";
			cout << N << "Определитель вспомогательной матрицы Det3 = " << Det3;
			X1 = FindXiKramer(DetA, Det1);
			X2 = FindXiKramer(DetA, Det2);
			X3 = FindXiKramer(DetA, Det3);
			cout << NN << "Матрица-стобец неизвестных X (Формулы): " << N << "X1 = Det1/DetA" << N << "X2 = Det2/DetA" << N << "X3 = Det3/DetA";
			cout << NN << "Матрица- столбец неизвестных Х:" << N << X1 << N << X2 << N << X3;
		}
		auto End = chrono::high_resolution_clock::now(); // Конец замеров
		chrono::duration <double> duration = End - Start;
		cout << NN << "Скорость решения системы методом Крамера: " << duration.count() << " (медленее на 1.2, чем методом обратной матрицы)";
	}
	delete[]Row;
}

// Функции для решения С.Л.А.У методом обратной матрицы
SystemData FindReverseSystem(int SizeOfSystem, SystemData Row[], int i, double DetA)
{
	SystemData ReverseRow{};
	if (SizeOfSystem == 2)
	{
		if (i == 0)
		{
			ReverseRow.x = double(Row[1].y) / DetA;											  //1.1
			ReverseRow.y = double(Row[0].y) / DetA * (-1);                                    //1.2
		}
		else
		{
			ReverseRow.x = double(Row[1].x) / DetA * (-1);                                    //2.1
			ReverseRow.y = double(Row[0].x) / DetA;											  //2.2
		}
	}
	else
	{
		if (i == 0)
		{
			ReverseRow.x = double((Row[1].y * Row[2].z - Row[1].z * Row[2].y)) / DetA;        //1.1
			ReverseRow.y = double((Row[0].y * Row[2].z - Row[2].y * Row[0].z)) / DetA * (-1); //2.1
			ReverseRow.z = double((Row[0].y * Row[1].z - Row[0].z * Row[1].y)) / DetA;        //3.1
		}
		else if (i == 1)
		{
			ReverseRow.x = double((Row[1].x * Row[2].z - Row[1].z * Row[2].x)) / DetA * (-1);  //1.2
			ReverseRow.y = double((Row[0].x * Row[2].z - Row[0].z * Row[2].x)) / DetA;         //2.2
			ReverseRow.z = double((Row[0].x * Row[1].z - Row[0].z * Row[1].x)) / DetA * (-1);  //3.2
		}
		else if (i == 2)
		{
			ReverseRow.x = double((Row[1].x * Row[2].y - Row[1].y * Row[2].x)) / DetA;        //1.3
			ReverseRow.y = double((Row[0].x * Row[2].y - Row[0].y * Row[2].x)) / DetA * (-1); //2.3
			ReverseRow.z = double((Row[0].x * Row[1].y - Row[0].y * Row[1].x)) / DetA;        //3.3
		}
	}

	return ReverseRow;
}
void PrintTheReverseSystem(int SizeOfSystem, SystemData ReverseRow[])
{
	cout << NN << "Обратная матрица к А (формулы):";
	if (SizeOfSystem == 2)
	{
		cout << N << "A11 = a11 * M11 / DetA" << "\t\t" << "A12 = a12 * M12 / DetA " << N << "A21 = a21 * M21 / DetA" << "\t\t" << "A22 = a22 * M22 / DetA";
		cout << NN << "Обратная матрица к А:";
		for (int i = 0; i < SizeOfSystem; i++)
		{
			cout << N << ReverseRow[i].x << '\t' << ReverseRow[i].y;
		}
	}
	else
	{
		cout << N << "A11 = a11 * M11 / DetA" << "\t\t" << "A12 = a12 * M12 / DetA" << "\t\t" << "A13 = a13 * M13 / DetA" << N << "A21 = a21 * M21 / DetA" << "\t\t" << "A22 = a22 * M22 / DetA" << "\t\t" << "A23 = a23 * M23 / DetA" << N << "A31 = a31 * M31 / DetA" << "\t\t" << "A32 = a32 * M32 / DetA" << "\t\t" << "A33 = a31 * M31 / DetA";
		cout << NN << "Обратная матрица к А:";
		for (int i = 0; i < SizeOfSystem; i++)
		{
			cout << N << ReverseRow[i].x << '\t' << ReverseRow[i].y << '\t' << ReverseRow[i].z;
		}
	}

}
double FindXiReverse(int SizeOfSytem, SystemData ReverseRow[], SystemData Row[], int i)
{
	if (i == 0)
	{
		if (SizeOfSystem == 2)
		{
			return ReverseRow[0].x * Row[0].b + ReverseRow[0].y * Row[1].b;
		}
		else
		{
			return ReverseRow[0].x * Row[0].b + ReverseRow[0].y * Row[1].b + ReverseRow[0].z * Row[2].b;
		}
	}
	else if (i == 1)
	{
		if (SizeOfSystem == 2)
		{
			return ReverseRow[1].x * Row[0].b + ReverseRow[1].y * Row[1].b;
		}
		else
		{
			return ReverseRow[1].x * Row[0].b + ReverseRow[1].y * Row[1].b + ReverseRow[1].z * Row[2].b;
		}
	}
	else
	{

		{
			return ReverseRow[2].x * Row[0].b + ReverseRow[2].y * Row[1].b + ReverseRow[2].z * Row[2].b;
		}
	}
}
void Reverse(int SizeOfSystem)
{
	double DetA(0);
	double X1(0), X2(0), X3(0);
	SystemData* Row = new SystemData[SizeOfSystem];
	SystemData* ReverseRow = new SystemData[SizeOfSystem];

	for (int i = 0; i < SizeOfSystem; i++)
	{
		Row[i] = ReadTheSystem(SizeOfSystem);
	}

	auto Start = chrono::high_resolution_clock::now(); //Старт замеров
	PrintTheSystem(SizeOfSystem, Row);

	DetA = FindDeterminant(SizeOfSystem, Row);
	if (DetA == 0)
	{
		cout << N << "Матрица несовместна ";
	}
	else
	{
		for (int i = 0; i < SizeOfSystem; i++)
		{
			ReverseRow[i] = FindReverseSystem(SizeOfSystem, Row, i, DetA);
		}

		if (SizeOfSystem == 2)
		{
			cout << NN << "Детерминант матрицы A (формула) = X1 * Y2 - X2 * Y1";
			cout << N << "Детерминант матрицы А = " << DetA;
			PrintTheReverseSystem(SizeOfSystem, ReverseRow);
			X1 = FindXiReverse(SizeOfSystem, ReverseRow, Row, 0);
			X2 = FindXiReverse(SizeOfSystem, ReverseRow, Row, 1);
			cout << NN << "Матрица столбец неизвестных X = reverse A * B (формулы): ";
			cout << N << "X1 = X1*B1+Y1*B2";
			cout << N << "X2 = X2*B1+Y2*B2";
			cout << NN << "Матрица столбец неизвестных X:" << N << "X1 = " << X1 << N << "X2 = " << X2;;
		}

		if (SizeOfSystem == 3)
		{
			cout << NN << "Детерминант матрицы A (формула) = X1 * Y2 * Z3 + Y1 * Z2 * X3 + Z1 * X2 * Y3 - Z1 * Y2 * X3 - X1 * Z2 * Y3 - Y1 * X2 * Z3";
			cout << N << "Детерминант матрицы А = " << DetA;
			PrintTheReverseSystem(SizeOfSystem, ReverseRow);
			X1 = FindXiReverse(SizeOfSystem, ReverseRow, Row, 0);
			X2 = FindXiReverse(SizeOfSystem, ReverseRow, Row, 1);
			X3 = FindXiReverse(SizeOfSystem, ReverseRow, Row, 2);
			cout << NN << "Матрица столбец неизвестных X = reverse A * B (формулы): ";
			cout << N << "X1 = X1*B1+Y1*B2+Z1*B3";
			cout << N << "X2 = X2*B1+Y2*B2+Z2*B3";
			cout << N << "X3 = X3*B1+Y3*B2+Z3*B3";
			cout << NN << "Матрица столбец неизвестных X:" << N << "X1 = " << X1 << N << "X2 = " << X2 << N << "X3 = " << X3;
		}
		auto End = chrono::high_resolution_clock::now();
		chrono::duration <double> duration = End - Start;
		cout << NN << "Скорость решения системы методом обратной матрицы: " << duration.count() << " (быстрее на 1.2, чем методом Крамера)";
	}
	delete[]Row;
	delete[]ReverseRow;
}
