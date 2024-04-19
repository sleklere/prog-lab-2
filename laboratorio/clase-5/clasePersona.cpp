#include "clasePersona.h"
#include <iostream>
using namespace std;

void Persona::Cargar() {
  string nombre, apellido;
  cout << "Nombre: ";
  cin >> nombre;
  setNombre(nombre);
  cout << "Apellido: ";
  cin >> apellido;
  setApellido(apellido);
}