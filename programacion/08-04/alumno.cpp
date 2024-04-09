#include <iostream>
using namespace std;
#include "fecha.h"
#include "fecha.cpp"
#include <string.h>

class Persona
{
private:
  int _dni;
  char _nombre[30];
  char _apellido[30];
  Fecha _fechaNacimiento;
  char _telefono[15];

public:
  // Getters

  int getDni();
  const char *getNombre();
  const char *getApellido();
  Fecha getFechaNacimiento();
  const char *getTelefono();
  // Setters

  void setDni(const int dni);
  void setNombre(const char *n);
  void setApellido(const char *n);
  void setFechaNacimiento(Fecha f);
  void setTelefono(const char *t);
  void Mostrar();
  void Cargar();
};

class Alumno : public Persona
{
private:
  int _legajo;

public:
  // Getters
  int getLegajo();
  // Setters
  void setLegajo(const int legajo);
};

int Alumno::getLegajo()
{
  return _legajo;
};
int Persona::getDni()
{
  return _dni;
};
const char *Persona::getNombre()
{
  return _nombre;
};
const char *Persona::getApellido()
{
  return _apellido;
};
Fecha Persona::getFechaNacimiento()
{
  return _fechaNacimiento;
};
const char *Persona::getTelefono()
{
  return _telefono;
};
void Alumno::setLegajo(const int legajo)
{
  _legajo = legajo;
};
void Persona::setDni(const int dni)
{
  _dni = dni;
};
void Persona::setNombre(const char *n) { strcpy(_nombre, n); };
void Persona::setApellido(const char *n) { strcpy(_apellido, n); };
void Persona::setFechaNacimiento(Fecha f) { _fechaNacimiento = f; };
void Persona::setTelefono(const char *t) { strcpy(_telefono, t); };
void Persona::Cargar()
{
  cout << "Nombre: ";
  cin >> _nombre;
  cout << "Apellido: ";
  cin >> _apellido;
  cout << "Dni: ";
  cin >> _dni;
  cout << "Fecha de nacimiento: ";
  _fechaNacimiento.Cargar();
  cout << "Telefono: ";
  cin >> _telefono;
};
void Persona::Mostrar()
{
  cout << "Nombre: " << _nombre << endl;
  cout << "Apellido: " << _apellido << endl;
  cout << "Dni: " << _dni << endl;
  cout << "Fecha de nacimiento: ";
  _fechaNacimiento.Mostrar();
  cout << endl;
  cout << "Telefono: " << _telefono << endl;
};

int main()
{
  Persona pepe;
  Alumno juan;

  cout << "Cargando persona..." << endl;
  pepe.Cargar();
  cout << "Persona cargada." << endl;
  system("pause");
  cout << "Cargando alumno..." << endl;
  juan.Cargar();

  pepe.Mostrar();
  cout << endl;
  juan.Mostrar();
  return 0;
}