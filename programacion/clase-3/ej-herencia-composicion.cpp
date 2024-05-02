#include "ej-herencia-composicion.h"
#include "alumno.cpp"
#include "fecha.cpp"
#include "fecha.h"
#include <cstring>
#include <iostream>
using namespace std;

Empleado::Empleado(int categoria, float sueldo, const Fecha fechaIngreso)
{
	_categoria = categoria;
	_sueldo = sueldo;
	_fechaIngreso = fechaIngreso;
}

const char *Proveedor::getCUIL() { return _CUIL; }
int Proveedor::getTipoProducto() { return _tipoProducto; }
char Proveedor::getCondicionPago() { return _condicionPago; }

bool Proveedor::setCUIL(const char *CUIL)
{
	if (CUIL == nullptr)
	{
		return false;
	}
	if (strlen(CUIL) == 11)
	{
		strcpy(_CUIL, CUIL);
		return true;
	}
	return false;
};
bool Proveedor::setTipoProducto(int tipoProducto)
{
	if (tipoProducto <= 10 && tipoProducto >= 1)
	{
		_tipoProducto = tipoProducto;
		return true;
	}
	else
	{
		return false;
	}
};
bool Proveedor::setCondicionPago(char condicionPago)
{
	if (condicionPago == 'a' || condicionPago == 'b' || condicionPago == 'c')
	{
		_condicionPago = condicionPago;
		return true;
	}
	else
	{
		return false;
	}
}

void Proveedor::Cargar()
{
	Persona::Cargar();
	char CUIL[11], condicionPago;
	int tipoProducto;
	bool inputValido = 0;

	cout << "CUIL: ";
	cin >> CUIL;
	setCUIL(CUIL);
	// 1 ejemplo de usar la validacion del setter en la carga
	while (!inputValido)
	{
		cout << "Condicion de pago: ";
		cin >> condicionPago;
		if (setCondicionPago(condicionPago))
		{
			inputValido = 1;
		}
		else
		{
			cout << "Input invalido...intente de nuevo." << endl;
		}
	}
	cout << "Tipo de producto: ";
	cin >> tipoProducto;
	setTipoProducto(tipoProducto);
}
void Proveedor::Mostrar()
{
	Persona::Mostrar();
	cout << "CUIL: " << getCUIL() << endl;
	cout << "Condicion de pago: " << getCondicionPago() << endl;
	cout << "Tipo de producto: " << getTipoProducto() << endl;
}

Proveedor::Proveedor(const char *CUIL = "203902805", int tipoProducto = 7,
					 char condicion = 'a')
{
	// strcpy(_CUIL, CUIL);
	setCUIL(CUIL);
	_tipoProducto = tipoProducto;
	_condicionPago = condicion;
}

Docente::Docente(const char *legajo, const char *cargo, Fecha fechaIngreso)
{
	strcpy(_legajo, legajo);
	strcpy(_cargo, cargo);
	_fechaIngreso = fechaIngreso;
}

// 2

void Inmueble::Cargar()
{
	cout << "Carga de fecha de ingreso: " << endl;
	_fechaIngreso.Cargar();
	cout << "Carga de fecha de operacion: " << endl;
	_fechaOperacion.Cargar();
	cout << "Superficie total: ";
	cin >> _superficieTotal;
	cout << "Tipo de operacion: ";
	cin >> _tipoOperacion;
}

void Inmueble::Mostrar()
{
	cout << "Fecha de ingreso: ";
	_fechaIngreso.Mostrar();
	cout << endl;
	cout << "Fecha de operacion: ";
	_fechaOperacion.Mostrar();
	cout << endl;
	cout << "Superficie total: " << _superficieTotal << endl;
	cout << "Tipo de operacion: " << _tipoOperacion << endl;
}

int Residencia::getCantAmbientes() { return _cantAmbientes; };
void Residencia::setCantAmbientes(int cantidad)
{
	if (cantidad > 0)
	{
		_cantAmbientes = cantidad;
	}
}
void Residencia::Cargar()
{
	int cantAmbientes;

	Inmueble::Cargar();
	cout << "Cantidad de ambientes: ";
	cin >> cantAmbientes;
	setCantAmbientes(cantAmbientes);
}

int Casa::getSuperficieConstruida()
{
	return _superficieConstruida;
}
void Casa::setSuperficieConstruida(int superficie)
{
	if (superficie >= 0)
	{
		_superficieConstruida = superficie;
	}
}
void Casa::Cargar()
{
	int superficie;
	Residencia::Cargar();
	cout << "Superficie construida: ";
	cin >> superficie;
	setSuperficieConstruida(superficie);
}

int main()
{
	Empleado emp1;
	Proveedor prov1;
	Docente doce1;
	// emp1.Cargar();
	// cout << endl;
	// prov1.Cargar();
	// cout << endl;
	// doce1.Cargar();
	// cout << endl;
	// system("pause");
	// prov1.Mostrar();

	// 2
	Inmueble inm1;
	inm1.Cargar();
	system("pause");
	cout << endl;
	inm1.Mostrar();
	return 0;
}