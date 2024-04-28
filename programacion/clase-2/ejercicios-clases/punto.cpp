// Ejercicio:
// Autor:DEK
// Fecha:
// Comentario:

#include <chrono>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <thread>
#include <windows.h>
#include <random>
#include <atomic>

using namespace std;

/// DEFINICIONES DE CONSTANTES Y FUNCIONES QUE SON UTILIZADAS POR LA CLASE PUNTO
enum Color
{
	cNEGRO = 0,
	cAZUL = 1,
	cVERDE = 2,
	cCIAN = 3,
	cROJO = 4,
	cMAGENTA = 5,
	cMARRON = 6,
	cGRIS_CLARO = 7,
	cGRIS = 8,
	cAZUL_CLARO = 9,
	cVERDE_CLARO = 10,
	cCIAN_CLARO = 11,
	cROJO_CLARO = 12,
	cMAGENTA_CLARO = 13,
	cAMARILLO = 14,
	cBLANCO = 15
};
/// Se definen una serie de constantes que asumen el valor que se le asignó.
/// Es más fácil usar cBLANCO para setear el color a blanco, que acordarse el
/// número 15

void ocultarCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void mostrarCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 10;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(short x,
			short y)
{ /// UBICA EL CURSOR EN LA POSICIÓN x,y DE LA PANTALLA
	COORD a;
	a.X = x;
	a.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
}
/// ASIGNA COLORES AL TEXTO Y AL FONDO DEL TEXTO
void textcolor(int colorTexto = 15, int colorFondo = 0)
{
	int color = colorTexto + colorFondo * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

///**FIN FUNCIONES

/// CLASE PUNTO
class Punto
{
private:
	int x;
	int y;
	int color;

public:
	Punto(int a = 0, int b = 0, int nuevoColor = cNEGRO)
	{
		x = a;
		y = b;
		color = nuevoColor;
	}
	void Mostrar()
	{
		textcolor(color, 15);
		gotoxy(x, y);
		cout << (char)219;
	}
	void MostrarValores();
	void Ocultar()
	{
		gotoxy(x, y);
		cout << " ";
	}
	void setX(int valor)
	{
		if (valor >= 0 && valor <= 166)
			x = valor;
	}
	void setY(int valor)
	{
		if (valor >= 0)
			y = valor;
	}

	void setColor(int nuevo)
	{
		if (nuevo > 0 && nuevo <= 15)
		{
			color = nuevo;
		}
		else
		{
			color = nuevo % 16;
		}
	}
	int getX() { return x; }
	int getY() { return y; }
	int getColor() { return color; }
	~Punto()
	{ /// DESTRUCTOR: se ejecuta cuando el objeto cae fuera de su
	  /// alcance.
		textcolor(cNEGRO, cBLANCO);
	}
};

void Punto::MostrarValores()
{
	cout << x << endl;
	cout << y << endl;
	cout << color << endl;
}

void punto1()
{
	Punto obj(10, 5, cAZUL);
	int x, y;
	cout << "INGRESE LA COORDENADA X: ";
	cin >> x;
	cout << "INGRESE LA COORDENADA Y: ";
	cin >> y;
	obj.setX(x);
	obj.setY(y);
	system("cls");
	obj.Mostrar();
}

void punto2()
{
	int y;
	cout << "INGRESE LA COORDENADA Y: ";
	cin >> y;
	for (int x = 0; x < 10; x++)
	{
		Punto p(x, y, cAZUL);
		p.Mostrar();
	}
}

// Intento de que imprima a lo largo de todo el eje X

// void punto2()
// {
//     HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//     int y, x = 0;
//     cout << "INGRESE LA COORDENADA Y: ";
//     cin >> y;
//     bool print = 1, firstPoint = 1;
//     while (print)
//     {
//         COORD currentPosition = GetConsoleCursorPosition(hConsoleOutput);
//         // cout << "X: " << x << endl;
//         // cout << currentPosition.Y << endl;
//         // cout << y << endl;
//         if (currentPosition.Y > y)
//         {
//             print = 0;
//             break;
//         }
//         else if (firstPoint != 1)
//         {
//             Punto p(x, y, cAZUL);
//             p.Mostrar();
//             x += 1;
//         }
//         else
//         {
//             firstPoint = 0;
//         }
//     }
// }

void punto3()
{
	int x;
	cout << "INGRESE LA COORDENADA X: ";
	cin >> x;
	for (int y = 1; y < 10; y++)
	{
		Punto p(x, y, cAZUL);
		p.Mostrar();
	}
}

void punto4()
{
	int y;
	cout << "INGRESE LA COORDENADA Y: ";
	cin >> y;
	for (int x = 0; x < 10; x++)
	{
		Punto p(x, y, cAZUL);
		if ((x % 2) != 0)
		{
			p.setColor(cROJO);
		}
		p.Mostrar();
	}
}

void punto5()
{
	int x;
	cout << "INGRESE LA COORDENADA X: ";
	cin >> x;
	for (int y = 1; y < 10; y++)
	{
		Punto p(x, y, cAZUL);
		if ((y % 2) != 0)
		{
			p.setColor(cROJO);
		}
		p.Mostrar();
	}
}

void punto6()
{
	if (_WIN32)
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		int columns, middle;
		Punto p1(0, 4, cAZUL), p2(0, 4, cROJO);

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		middle = columns / 2;

		for (int i = 0; i < middle; ++i)
		{
			p1.setX(i);
			p1.Mostrar();
		}

		for (int i = middle; i < columns; i++)
		{
			p2.setX(i);
			p2.Mostrar();
		}
	}
}

void punto7()
{
	if (_WIN32)
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		int columns, middle, y = 4;
		Punto p1(0, y, cAZUL), p2(0, y, cROJO);

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		middle = columns / 2;

		for (int i = 0; i < middle; ++i)
		{
			p1.setX(i);
			p1.Mostrar();
		}

		for (int i = middle; i < columns; i++)
		{
			p2.setX(i);
			p2.Mostrar();
		}

		p1.setX(middle - 1);
		p2.setX(middle);

		for (y; y >= 0; y--)
		{
			p1.setY(y);
			p2.setY(y);
			p1.Mostrar();
			p2.Mostrar();
		}
	}
}

void punto8()
{
	Punto obj;
	int x, y;
	cout << "INGRESE LA COORDENADA X: ";
	cin >> x;
	cout << "INGRESE LA COORDENADA Y: ";
	cin >> y;
	obj.setX(x);
	obj.setY(y);
	obj.setColor(cAZUL);
	//   system("cls");
	while (!_kbhit())
	{
		obj.Mostrar();
		std::this_thread::sleep_for(std::chrono::milliseconds(400));
		obj.Ocultar();
		std::this_thread::sleep_for(std::chrono::milliseconds(400));
	}

	_getch();
	return;
}

void punto9()
{
	// Punto pX, pY;
	int ladoX, ladoY;
	cout << "INGRESE VALOR LADO (EJE X): ";
	cin >> ladoX;
	cout << "INGRESE VALOR LADO (EJE Y): ";
	cin >> ladoY;

	for (int y = 10; y < (ladoY + 10); y++)
	{
		// cout << y << ", " << ladoY << endl;
		Punto pY(10, y, cAZUL);
		pY.Mostrar();
	}
	for (int x = 10; x < (ladoX + 10); x++)
	{
		// cout << x << ", " << ladoX << endl;
		Punto pX(x, ladoY + 10, cROJO);
		pX.Mostrar();
	}
	for (int y = 10; y < (ladoY + 10); y++)
	{
		Punto pY2((ladoX + 10) - 1, y, cAZUL);
		pY2.Mostrar();
	}
	for (int x = 10; x < (ladoX + 10); x++)
	{
		Punto pX(x, 10, cROJO);
		pX.Mostrar();
	}
}
void punto10()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	int x = csbi.srWindow.Left;

	Punto objPunto(x, 10, cROJO);

	while (x < csbi.srWindow.Right)
	{
		objPunto.Mostrar();
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		objPunto.Ocultar();
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		x += 2;
		objPunto.setX(x);
	}

	return;
}
void punto11()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	int y = csbi.srWindow.Top;

	Punto objPunto(10, y, cROJO);

	while (y < csbi.srWindow.Bottom)
	{
		objPunto.Mostrar();
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		objPunto.Ocultar();
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		y += 2;
		objPunto.setY(y);
	}

	return;
}

void loopGota(int x, int y)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	// int y = csbi.srWindow.Top;

	Punto objPunto(x, y, cROJO);

	while (true)
	{
		if (y >= csbi.srWindow.Bottom)
		{
			y = 0;
		}
		objPunto.Mostrar();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		objPunto.Ocultar();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		y++;
		objPunto.setY(y);
	}

	return;
}
void gota(int x, int y)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	// int y = csbi.srWindow.Top;

	Punto objPunto(x, y, cROJO);

	while (y < csbi.srWindow.Bottom)
	{
		objPunto.Mostrar();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		objPunto.Ocultar();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		y++;
		objPunto.setY(y);
	}

	return;
}

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distrib(0, 5);

void punto12()
{
	const int cantGotas = 10;
	std::thread threads[cantGotas];
	int randomYArr[cantGotas];

	for (int i = 0; i < cantGotas; i++)
	{
		randomYArr[i] = distrib(gen);
	}

	for (int i = 0; i < cantGotas; i++)
	{
		int startX = 10 * i + 10;
		threads[i] = std::thread(loopGota, startX, randomYArr[i]);
	}

	for (auto &thread : threads)
	{
		thread.join();
	}

	return;
}

void punto13()
{
	const int cantGotas = 10;
	std::thread threads[cantGotas];
	int randomYArr[cantGotas];

	for (int i = 0; i < cantGotas; i++)
	{
		randomYArr[i] = distrib(gen);
	}

	while (!kbhit())
	{
		for (int i = 0; i < cantGotas; i++)
		{
			int startX = 10 * i + 10;
			threads[i] = std::thread(gota, startX, randomYArr[i]);
		}

		for (auto &thread : threads)
		{
			thread.join();
		}
	}

	return;
}

int main()
{
	srand(time(NULL));
	ocultarCursor();
	textcolor(0, 15);
	int opc;
	while (true)
	{
		system("cls");
		cout << "----------MENU------------" << endl;
		cout << "1. DIBUJAR UN PUNTO EN LA POSICION QUE EL USUARIO PIDA POR TECLADO"
			 << endl;
		cout << "2. DIBUJAR UNA LINEA DE PUNTOS HORIZONTAL EN UNA POSICION DEL EJE "
				"Y DEFINIDA"
			 << endl;
		cout << "3. DIBUJAR UNA LINEA DE PUNTOS VERTICAL EN UNA POSICION DEL EJE X "
				"DEFINIDA"
			 << endl;
		cout << "4. DIBUJAR UNA LINEA DE PUNTOS HORIZONTAL QUE ALTERNE 2 COLORES"
			 << endl;
		cout << "5. DIBUJAR UNA LINEA DE PUNTOS VERTICAL QUE ALTERNE 2 COLORES"
			 << endl;
		cout << "6. DIBUJAR 2 LINEAS HORIZONTALES QUE NAZCAN EN AMBOS EXTREMOS DE "
				"LA PANTALLA "
			 << endl;
		cout << " Y SE ENCUENTREN EN EL CENTRO DE LA PANTALLA. DEBEN SER DE "
				"DISTINTOS COLORES "
			 << endl;
		cout << "7. DIBUJAR 2 LINEAS HORIZONTALES QUE NAZCAN EN AMBOS EXTREMOS DE "
				"LA PANTALLA "
			 << endl;
		cout << " Y SE ENCUENTREN EN EL CENTRO DE LA PANTALLA. DEBEN SER DE "
				"DISTINTOS COLORES "
			 << endl;
		cout << " AL ENCONTRARSE DEBEN LAS LINEAS DEBEN SUBIR HASTA LA POSICIÓN 0 "
				"DE Y "
			 << endl;
		cout << "8. HACER UN PUNTO QUE PARPADEE EN LA PANTALLA EN UNA POSICION DADA"
			 << endl;
		cout << "9. HACER UN RECTANGULO A PARTIR DE DOS VALORES DE 2 LADOS" << endl;
		cout << "10. HACER UN PUNTO QUE CAMINE POR LA PANTALLA DE MANERA HORIZONTAL"
			 << endl;
		cout << "11. HACER UN PUNTO QUE SE DESPLAZE POR LA PANTALLA DE MANERA "
				"VERTICAL"
			 << endl;
		cout << "12. DIBUJAR UNA LLUVIA DE PUNTOS" << endl;
		cout << "13. DIBUJAR UNA LLUVIA DE PUNTOS HASTA QUE SE PRESIONA UNA TECLA"
			 << endl;
		cout << "OPCION: ";
		cin >> opc;
		system("cls");
		switch (opc)
		{
		case 1:
			punto1();
			break;
		case 2:
			punto2();
			break;
		case 3:
			punto3();
			break;
		case 4:
			punto4();
			break;
		case 5:
			punto5();
			break;
		case 6:
			punto6();
			break;
		case 7:
			punto7();
			break;
		case 8:
			punto8();
			break;
		case 9:
			punto9();
			break;
		case 10:
			punto10();
			break;
		case 11:
			punto11();
			break;
		case 12:
			punto12();
			break;
		case 13:
			punto13();
			break;
		case 0:
			return 0;
		}
		system("pause>nul");
	}
	return 0;
}

/**
A partir de la clase Punto resolver lo siguiente:

8) Hacer un punto que parpadee en la pantalla en una posición dada.
9) Hacer un rectangulo, a partir de los valores de 2 lados
10) Hacer un punto que camine por la pantalla de manera horizontal
11) Hacer un punto que se desplaze por la pantalla de manera vertical
12) Hacer una lluvia de puntos aleatoria en la pantalla.
13) Igual que el anterior, pero debe terminar el programa cuando se
toca una tecla
Para este último hay una función que se llama kbhit()

Pueden agregar los métodos que consideren necesarios.
**/
