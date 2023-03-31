#include <iostream>
#include <iomanip>
#include "glut.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glut32.lib")

// ДРП
int FIELD[22][22] = { { 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 888, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 888, 0, 888, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 888, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 888, 888, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 888, 888, 888, 888, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0, 0, 0, 0, 0, 777 },
{ 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777, 777 } };

double dz = -40;
double x = 0, y = 0, z = 0;

// Печать поля в цифрах
void WAWE_PRINT()
{
	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			std::cout << std::setw(3) << FIELD[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// Вывод поля на экран
void PRINT()
{
	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			switch (FIELD[i][j])
			{
			case 888: std::cout << "* "; break;
			case -5: std::cout << "A "; break;
			case 999: std::cout << "B "; break;
			case 998: std::cout << "+ "; break;
			default: std::cout << ". ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// Изменение координат точки A
void CHANGE_A(int* x, int* y, int* xB, int* yB)
{
	bool check = true;

	if ((*x > 0) && (*y > 0)) FIELD[*x][*y] = 0;

	while (check)
	{
		std::cout << "Введите координаты А (1 - 20):" << std::endl;
		std::cout << "X: "; std::cin >> *x;
		std::cout << "Y: "; std::cin >> *y;


		// Проверка, не попадает ли точка А в точку В
		if ((*xB == *x) && (*yB == *y))
		{
			std::cout << "ОШИБКА: Точка А совпадает с точкой В, попробуйте снова: " << std::endl;
			continue;
		}

		// Проверка на выход координат за границы поля
		if ((*x < 1) || (*x > 20))
		{
			std::cout << "ОШИБКА: Координата Х выходит за границы поля, попробуйте снова: " << std::endl;
			continue;
		}
		if ((*y < 1) || (*y > 20))
		{
			std::cout << "ОШИБКА: Координата Y выходит за границы поля, попробуйте снова: " << std::endl;
			continue;
		}


		// Проверка на попадение точки А в препятствие
		if (FIELD[*x][*y] == 888)
		{
			std::cout << "ОШИБКА: Точка А попала на препятствие, повторите снова: " << std::endl;
		}
		else check = false;
	}

	FIELD[*x][*y] = -5;
}

// Изменение координат точки B
void CHANGE_B(int* x, int* y, int* xA, int* yA)
{
	bool check = true;

	if ((*x > 0) && (*y > 0)) FIELD[*x][*y] = 0;

	while (check)
	{
		std::cout << "Введите координаты А (1 - 20):" << std::endl;
		std::cout << "X: "; std::cin >> *x;
		std::cout << "Y: "; std::cin >> *y;

		//Проверка, не попадает ли точка В в точку А
		if ((*xA == *x) && (*yA == *y))
		{
			std::cout << "ОШИБКА: Точка А совпадает с точкой В, попробуйте снова: " << std::endl;
			continue;
		}


		// Проверка на выход координат за границы поля
		if ((*x < 1) || (*x > 20))
		{
			std::cout << "ОШИБКА: Координата Х выходит за границы поля, попробуйте снова: " << std::endl;
			continue;
		}
		if ((*y < 1) || (*y > 20))
		{
			std::cout << "ОШИБКА: Координата Y выходит за границы поля, попробуйте снова: " << std::endl;
			continue;
		}
		// Проверка на попадение точки А в препятствие
		if (FIELD[*x][*y] == 888)
		{
			std::cout << "ОШИБКА: Точка А попала на препятствие, повторите снова: " << std::endl;
		}
		else check = false;
	}

	FIELD[*x][*y] = 999;
}

// Волновой алгоритм
void WAWE(int xA, int yA, int xB, int yB)
{
	int W = 1;
	if ((xA - 1 >= 0) && (FIELD[xA - 1][yA] == 0)) FIELD[xA - 1][yA] = 1;
	if ((yA + 1 <= 20) && (FIELD[xA][yA + 1] == 0)) FIELD[xA][yA + 1] = 1;
	if ((xA + 1 <= 20) && (FIELD[xA + 1][yA] == 0)) FIELD[xA + 1][yA] = 1;
	if ((yA - 1 >= 0) && (FIELD[xA][yA - 1] == 0)) FIELD[xA][yA - 1] = 1;

	for (int k = 0; k < 200; k++)
	{
		for (int i = 1; i < 21; i++)
		{
			for (int j = 1; j < 21; j++)
			{
				if (FIELD[i][j] == W)
				{
					if ((i - 1 >= 0) && (FIELD[i - 1][j] == 0)) FIELD[i - 1][j] = W + 1;
					if ((j + 1 <= 20) && (FIELD[i][j + 1] == 0)) FIELD[i][j + 1] = W + 1;
					if ((i + 1 <= 20) && (FIELD[i + 1][j] == 0)) FIELD[i + 1][j] = W + 1;
					if ((j - 1 >= 0) && (FIELD[i][j - 1] == 0)) FIELD[i][j - 1] = W + 1;
				}
			}
		}
		W = W + 1;
	}
}

// Поиск минимального пути
int FIND_WAY(int xB, int yB)
{
	int x = xB, y = yB;

	// Ïðîâåðêà, íå ñòîÿò ëè ðÿäîì À è Â
	if ((FIELD[x - 1][y] == -5) || (FIELD[x][y - 1] == -5) || (FIELD[x][y + 1] == -5) || (FIELD[x + 1][y] == -5))
	{
		std::cout << "Точки А и В стоят рядом" << std::endl;
		return -1;
	}

	// Ïðîâåðêà íà òî, ÷òî âîëíà âîîáùå äîøëà îò À ê Â
	if ((FIELD[x - 1][y] == 0) || (FIELD[x - 1][y] == 888) || (FIELD[x - 1][y] == 777))
		if ((FIELD[x][y - 1] == 0) || (FIELD[x][y - 1] == 888) || (FIELD[x][y - 1] == 777))
			if ((FIELD[x][y + 1] == 0) || (FIELD[x][y + 1] == 888) || (FIELD[x][y + 1] == 777))
				if ((FIELD[x + 1][y] == 0) || (FIELD[x + 1][y] == 888) || (FIELD[x + 1][y] == 777))
				{
					std::cout << "Невозможно найти путь от точки А к точке В" << std::endl;
					return -1;
				}

	// Поиск минимального значения вокруг клетки
	while (true)
	{
		if ((FIELD[x - 1][y] <= FIELD[x][y - 1]) && (FIELD[x - 1][y] <= FIELD[x][y + 1]) && (FIELD[x - 1][y] <= FIELD[x + 1][y]))
		{
			x = x - 1;
			y = y;
			if (FIELD[x][y] == 1)
			{
				FIELD[x][y] = 998;
				break;
			}
			FIELD[x][y] = 998;
			continue;
		}

		if ((FIELD[x][y + 1] <= FIELD[x][y - 1]) && (FIELD[x][y + 1] <= FIELD[x - 1][y]) && (FIELD[x][y + 1] <= FIELD[x + 1][y]))
		{
			x = x;
			y = y + 1;
			if (FIELD[x][y] == 1)
			{
				FIELD[x][y] = 998;
				break;
			}
			FIELD[x][y] = 998;
			continue;
		}

		if ((FIELD[x][y - 1] <= FIELD[x + 1][y]) && (FIELD[x][y + 1] <= FIELD[x][y + 1]) && (FIELD[x][y - 1] <= FIELD[x + 1][y]))
		{
			x = x;
			y = y - 1;
			if (FIELD[x][y] == 1)
			{
				FIELD[x][y] = 998;
				break;
			}
			FIELD[x][y] = 998;
			continue;
		}

		if ((FIELD[x + 1][y] <= FIELD[x][y - 1]) && (FIELD[x + 1][y] <= FIELD[x][y + 1]) && (FIELD[x + 1][y] <= FIELD[x - 1][y]))
		{
			x = x + 1;
			y = y;
			if (FIELD[x][y] == 1)
			{
				FIELD[x][y] = 998;
				break;
			}
			FIELD[x][y] = 998;
			continue;
		}
	}
	return 1;
}

// Очистка поля (Кроме точек А и В)
void CLEAN()
{
	for (int i = 1; i < 21; i++)
		for (int j = 1; j < 21; j++)
		{
			if ((FIELD[i][j] != 888) && (FIELD[i][j] != -5) && (FIELD[i][j] != 999))
				FIELD[i][j] = 0;
		}
}

// Тотальная очистка поля (Кроме препятствий)
void CLEAN_FULL()
{
	for (int i = 1; i < 21; i++)
		for (int j = 1; j < 21; j++)
		{
			if (FIELD[i][j] != 888)
				FIELD[i][j] = 0;
		}
}

// Меню для консоли
void MENU()
{
	std::cout << std::endl;
	std::cout << "M: Отобразить меню" << std::endl;
	std::cout << "C: Нарисовать поле (символы)" << std::endl;
	std::cout << "I: Нарисовать поле (числовое)" << std::endl;
	std::cout << "A: Изменить координаты точки А" << std::endl;
	std::cout << "B: Изменить координаты точки В" << std::endl;
	std::cout << "F: Запустить волновой алгоритм и найти кротчайший путь" << std::endl;
	std::cout << "T: Построить графический путь" << std::endl;
	std::cout << "S: Очистить экран" << std::endl;
	std::cout << "R: Полностью перезапустить программу" << std::endl;
	std::cout << "E: Завершить программу" << std::endl;
}

// Рисование на экране средствами OpenGL
void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, 800, 800);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 0.1f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0, 0, dz);
	glRotatef(x, 1, 0, 0);
	glRotatef(y, 0, 1, 0);
	glRotatef(z, 0, 0, 1);
	glRotatef(-90, 0, 0, 1);

	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			switch (FIELD[i][j])
			{
				// Препятствие
			case 888:
				glColor3f(0.8, 0.8, 0.8);
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 0);
				glVertex3f(i - 11, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11, 0);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 0);
				glVertex3f(i - 11, j - 11 + 1, 0);
				glVertex3f(i - 11, j - 11 + 1, 1);
				glVertex3f(i - 11, j - 11, 1);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11 + 1, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11, 0);
				glVertex3f(i - 11 + 1, j - 11, 1);
				glVertex3f(i - 11 + 1, j - 11 + 1, 1);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 0);
				glVertex3f(i - 11 + 1, j - 11, 0);
				glVertex3f(i - 11 + 1, j - 11, 1);
				glVertex3f(i - 11, j - 11, 1);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11 + 1, 1);
				glVertex3f(i - 11, j - 11 + 1, 1);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 1);
				glVertex3f(i - 11, j - 11 + 1, 1);
				glVertex3f(i - 11 + 1, j - 11 + 1, 1);
				glVertex3f(i - 11 + 1, j - 11, 1);
				glEnd();
				break;

				/*glColor3f(1, 1, 1);
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 0);
				glVertex3f(i - 11, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11, 0);
				glEnd();
				break;*/

				// Точка А (кубик синего цвета)
			case -5:
				glColor3f(0, 0, 1);
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 0);
				glVertex3f(i - 11, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11, 0);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 0);
				glVertex3f(i - 11, j - 11 + 1, 0);
				glVertex3f(i - 11, j - 11 + 1, 1);
				glVertex3f(i - 11, j - 11, 1);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11 + 1, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11, 0);
				glVertex3f(i - 11 + 1, j - 11, 1);
				glVertex3f(i - 11 + 1, j - 11 + 1, 1);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 0);
				glVertex3f(i - 11 + 1, j - 11, 0);
				glVertex3f(i - 11 + 1, j - 11, 1);
				glVertex3f(i - 11, j - 11, 1);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11 + 1, 1);
				glVertex3f(i - 11, j - 11 + 1, 1);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 1);
				glVertex3f(i - 11, j - 11 + 1, 1);
				glVertex3f(i - 11 + 1, j - 11 + 1, 1);
				glVertex3f(i - 11 + 1, j - 11, 1);
				glEnd();
				break;

				// Точка Б (кубик желтого цвета)
			case 999:
				glColor3f(1, 1, 0);
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 0);
				glVertex3f(i - 11, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11, 0);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 0);
				glVertex3f(i - 11, j - 11 + 1, 0);
				glVertex3f(i - 11, j - 11 + 1, 1);
				glVertex3f(i - 11, j - 11, 1);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11 + 1, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11, 0);
				glVertex3f(i - 11 + 1, j - 11, 1);
				glVertex3f(i - 11 + 1, j - 11 + 1, 1);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 0);
				glVertex3f(i - 11 + 1, j - 11, 0);
				glVertex3f(i - 11 + 1, j - 11, 1);
				glVertex3f(i - 11, j - 11, 1);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11 + 1, 1);
				glVertex3f(i - 11, j - 11 + 1, 1);
				glEnd();

				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 1);
				glVertex3f(i - 11, j - 11 + 1, 1);
				glVertex3f(i - 11 + 1, j - 11 + 1, 1);
				glVertex3f(i - 11 + 1, j - 11, 1);
				glEnd();
				break;

				// Путь торами
			case 998:
				glColor3f(1, 1, 1);
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 0);
				glVertex3f(i - 11, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11, 0);
				glEnd();

				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				glColor3f(0.5, 0.5, 0.5);
				glTranslatef(i - 11 + 0.5, j - 11 + 0.5, 0.5);
				glutSolidTorus(0.2, 0.35, 6, 20);

				glLoadIdentity();
				glTranslatef(0, 0, dz);
				glRotatef(x, 1, 0, 0);
				glRotatef(y, 0, 1, 0);
				glRotatef(z, 0, 0, 1);
				glRotatef(-90, 0, 0, 1);
				break;

				// Поле
			default:
				glColor3f(1, 1, 1);
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				glBegin(GL_QUADS);
				glVertex3f(i - 11, j - 11, 0);
				glVertex3f(i - 11, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11 + 1, 0);
				glVertex3f(i - 11 + 1, j - 11, 0);
				glEnd();
				break;
			}
		}
	}
	glutSwapBuffers();
}

void READ_KEYBOARD(unsigned char key, int, int)
{
	// Масштаб
	if (key == '-') dz -= 1;
	if ((key == '=') || (key == '+')) dz += 1;

	// Вращение
	if ((key == 'w') || (key == 'ö')) x -= 6;
	if ((key == 's') || (key == 'û')) x += 6;
	if ((key == 'a') || (key == 'ô')) z += 6;
	if ((key == 'd') || (key == 'â')) z -= 6;
	if ((key == 'q') || (key == 'é')) y -= 6;
	if ((key == 'e') || (key == 'ó')) y += 6;

	if (key == 27) exit(0);

	glutPostRedisplay();
}

void READ_SPECIAL_KEYBOARD(int key, int, int)
{

}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUSSIAN");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 800);
	glutCreateWindow("WAVE");
	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0, 0, 1);

RELOAD:
	int xA = -5, yA = -5, xB = -5, yB = -5;
	char check;

	PRINT();

	CHANGE_A(&xA, &yA, &xB, &yB);
	CHANGE_B(&xB, &yB, &xA, &yA);

	PRINT();
	WAWE(xA, yA, xB, yB);
	WAWE_PRINT();

	if (FIND_WAY(xB, yB) == 1) PRINT();

	MENU();
	while (true)
	{
		std::cout << ">> ";
		std::cin >> check;

		switch (check)
		{
		case 'c':
		case 'C':
			PRINT();
			break;

		case 'm':
		case 'M':
			MENU();
			break;

		case 'i':
		case 'I':
			WAWE_PRINT();
			break;

		case 'a':
		case 'A':
			CHANGE_A(&xA, &yA, &xB, &yB);
			break;

		case 'b':
		case 'B':
			CHANGE_B(&xB, &yB, &xA, &yA);
			break;

		case 'f':
		case 'F':
			CLEAN();
			WAWE(xA, yA, xB, yB);
			if (FIND_WAY(xB, yB) == 1) PRINT();
			break;

		case 's':
		case 'S':
			system("CLS");
			break;

		case 'r':
		case 'R':
			system("CLS");
			CLEAN_FULL();
			goto RELOAD;
			break;

		case 't':
		case 'T':
			CLEAN();
			WAWE(xA, yA, xB, yB);
			if (FIND_WAY(xB, yB) != 1) break;
			glutDisplayFunc(RenderScene);
			glutKeyboardFunc(READ_KEYBOARD);
			glutSpecialFunc(READ_SPECIAL_KEYBOARD);
			glutMainLoop();
			break;

		case 'e':
		case 'E':
			std::cout << std::endl;
			return 0;
			break;

		default: std::cout << "Неопознанная команда, попробуйте: M" << std::endl;
		}
	}
	return 0;
}
