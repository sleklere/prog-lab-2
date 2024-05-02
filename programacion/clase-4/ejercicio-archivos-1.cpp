#include "ejercicio-archivos-1.h"
#include <string.h>

class Empresa
{
private:
	int _num;
	char _nombre[30];
	int _cantEmpleados;
	int _categoria;
	int _numMunicipio;
	bool _estado;

public:
	Empresa(int num, const char *nombre, int cantEmpleados, int categoria, int numMunicipio, bool estado);
};

Empresa::Empresa(int num = 0, const char *nombre = "", int cantEmpleados = 0, int categoria = 0, int numMunicipio = 0, bool estado = false)
{
	_num = num;
	strcpy(_nombre, nombre);
	_cantEmpleados = cantEmpleados;
	_categoria = categoria;
	_numMunicipio = numMunicipio;
	_estado = estado;
}