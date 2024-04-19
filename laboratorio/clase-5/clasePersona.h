#pragma once
#include <string>
using namespace std;

class Persona {
private:
  string _nombre;
  string _apellido;

public:
  // getter
  string getNombre() { return _nombre; }
  string getApellido() { return _apellido; }
  // setter
  void setNombre(string nombre) { _nombre = nombre; }
  void setApellido(string apellido) { _apellido = apellido; }
  void Cargar();
};