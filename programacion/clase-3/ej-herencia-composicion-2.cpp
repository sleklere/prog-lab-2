#include <iostream>
using namespace std;

class Denominacion
{
	char _nombreCientifico[30];
	char _nombreComun[30];
	char _nombrePuebOrig[30];
};

class Dimension
{
private:
	int _largo;
	int _ancho;
	int _alto;
};

class Animal
{
private:
	Denominacion _denominacion;
	int _tiempoVidaPromedio;
	Dimension _dimension;
	int _peso;
	char _habitatPrincipal[30];
	char _tipoAlimentacion[20];
	int _poblacionEstimada;
};

class Pez : Animal
{
};
class Anfibio : Animal
{
};
class Reptil : Animal
{
};
class Ave : Animal
{
};
class Mamifero : Animal
{
};
class MamiferoT : Mamifero
{
};
class MamiferoM : Mamifero
{
};

int main()
{

	return 0;
}