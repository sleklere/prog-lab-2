#include <iostream>
using namespace std;
#include "fecha.h"
// #include "fecha.cpp"
#include "persona.h"
#include <string.h>

// getters and setters para cada propiedad (los puristas estarían en desacuerdo)
// cout's van por fuera de la clase
// Fecha obj; -> solo es valido si no hay un constructor declarado o el unico
// que hay es igual al implícito (Fecha();) Segun los puristas, si un valor
// numerico no es usado para calculos aritmeticos deberia ser de tipo char o
// string la edad es un ejemplo de datos que no deberian ser propiedades (en
// este caso porque es un dato que se sabe que va a cambiar, en cambio se guarda
// la fecha de nacimiento) composicion -> "usar obj de una clase como prop de
// otra clase" cadenas de char -> usar variables de tipo constante
//      - recibir str literal
//      - mas seguro al momento de usar strcpy()
//      - ESPECIALMENTE importante para los getters (encapsulamiento)
// Los valores por omisión van en la implementación

int Alumno::getLegajo() { return _legajo; };
int Persona::getDni() { return _dni; };
const char* Persona::getNombre() { return _nombre; };
const char* Persona::getApellido() { return _apellido; };
Fecha Persona::getFechaNacimiento() { return _fechaNacimiento; };
const char* Persona::getTelefono() { return _telefono; };
void Alumno::setLegajo(const int legajo) { _legajo = legajo; };
void Persona::setDni(const int dni) { _dni = dni; };
void Persona::setNombre(const char* n) { strcpy(_nombre, n); };
void Persona::setApellido(const char* n) { strcpy(_apellido, n); };
void Persona::setFechaNacimiento(Fecha f) { _fechaNacimiento = f; };
void Persona::setTelefono(const char* t) { strcpy(_telefono, t); };
void Persona::Cargar() {
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
void Persona::Mostrar() {
  cout << "Nombre: " << _nombre << endl;
  cout << "Apellido: " << _apellido << endl;
  cout << "Dni: " << _dni << endl;
  cout << "Fecha de nacimiento: ";
  _fechaNacimiento.Mostrar();
  cout << endl;
  cout << "Telefono: " << _telefono << endl;
};

// int main() {
//   Persona pepe;
//   Alumno juan;

//   cout << "Cargando persona..." << endl;
//   pepe.Cargar();
//   cout << "Persona cargada." << endl;
//   system("pause");
//   cout << "Cargando alumno..." << endl;
//   juan.Cargar();

//   pepe.Mostrar();
//   cout << endl;
//   juan.Mostrar();
//   return 0;
// }