#include "ej-herencia-composicion.h"
#include "alumno.cpp"
#include "fecha.cpp"
#include "fecha.h"
#include <cstring>
#include <iostream>
using namespace std;

Empleado::Empleado(int categoria, float sueldo, const Fecha fechaIngreso) {
  _categoria = categoria;
  _sueldo = sueldo;
  _fechaIngreso = fechaIngreso;
}
const char* Proveedor::getCUIL() { return _CUIL; }
int Proveedor::getTipoProducto() { return _tipoProducto; }
char Proveedor::getCondicionPago() { return _condicionPago; }
bool Proveedor::setCUIL(const char* CUIL) {
  if (CUIL == nullptr) {
    return false;
  }
  cout << sizeof CUIL;
  if (strlen(CUIL) == 11) {
    strcpy(_CUIL, CUIL);
    return true;
  }
  return false;
};
bool Proveedor::setTipoProducto(int tipoProducto) {
  if (tipoProducto <= 10 && tipoProducto >= 1) {
    _tipoProducto = tipoProducto;
    return true;
  } else {
    return false;
  }
};
bool Proveedor::setCondicionPago(char condicionPago) {
  if (condicionPago == 'a' || condicionPago == 'b' || condicionPago == 'c') {
    _condicionPago = condicionPago;
    return true;
  } else {
    return false;
  }
}
Proveedor::Proveedor(const char* CUIL = "203902805", int tipoProducto = 7,
                     char condicion = 'a') {
  // strcpy(_CUIL, CUIL);
  setCUIL(CUIL);
  _tipoProducto = tipoProducto;
  _condicionPago = condicion;
}
Docente::Docente(const char* legajo, const char* cargo, Fecha fechaIngreso) {
  strcpy(_legajo, legajo);
  strcpy(_cargo, cargo);
  _fechaIngreso = fechaIngreso;
}

int main() {
  Proveedor prov1;
  prov1.Cargar();
  system("pause");
  prov1.Mostrar();
  return 0;
}